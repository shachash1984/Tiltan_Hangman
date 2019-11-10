#include<iostream>
#include<string>
#include<ctime>
#include<iomanip>
#include<random>

using namespace std;

void DrawHangman(int, string, string&);
void CheckAns(string&, string&, string&, int&);
bool GameOver(string, string, string, int, bool&);


int main() {
	//variable for the outer loop
	char c_PlayAgain;

	cout << "\nHello and welcome to HangMan." << endl;
	do //program loop
	{
		//declaring and clearing values for variables in the game
		srand(time(0));
		bool b_GameOver = false;
		int i_UserCat;
		int i_Mistakes = 0;
		string sports[10] = { "muhammad ali" , "michael jordan", "babe ruth", "lionel messi", "roger federer", "christiano ronaldo", "usain bolt", "garry kasparov", "wayne gretzky", "michael phelps" };
		string politics[10] = { "bill clinton" , "benjamin netanyahu", "angela merkel", "moshe kahlon", "avigdor liberman", "tony blair", "bashar asad", "yair lapid", "tzipi livni", "barack obama" };
		string science[10] = { "albert einstein" , "george boole", "nicola tesla", "charles darwin", "marie curie", "isaac newton", "thomas edison", "louis paster", "stephen hawking", "adam smith" };
		string entertainment[10] = { "kim kardashian" , "sean connery", "dave chappelle", "mel brooks", "dalik volinitz", "mariah carey", "jimi hendrix", "woody harrelson", "ariana grande", "justin bieber" };
		string s_Answer = "";
		string s_HiddenWord = "";
		string s_UsedLetters = "";

		//requesting for category
		cout << "\n\nPlease choose a category: \n1.Sports \n2.Politics \n3.Science \n4.Entertainment" << endl;
		cin >> i_UserCat;

		switch (i_UserCat)
		{
			//choosing a random word from the chosen category
			case 1:
			{
				s_HiddenWord = sports[rand() % 10];
				break;
			}
			case 2:
			{
				s_HiddenWord = politics[rand() % 10];
				break;
			}
			case 3:
			{
				s_HiddenWord = science[rand() % 10];
				break;
			}
			case 4:
			{
				s_HiddenWord = entertainment[rand() % 10];
				break;
			}
			default:
			{
				cout << "Please choose one of the four categories" << endl;
				break;
			}
		}
		
		s_Answer = s_HiddenWord;
		
		// hiding the answer
		for (int i = 0; i < s_HiddenWord.length(); i++) {
			if (s_HiddenWord[i] != ' ')
			{
				s_HiddenWord[i] = '_';

			}
			else
			{
				s_HiddenWord[i] = ' ';
			}
		}
		cout << "\nThank you.\nYour goal is to guess the famous persona from the category you chose. you have 8 tries... Good Luck!" << endl;

		while (!b_GameOver) //game loop
			{

				DrawHangman(i_Mistakes, s_HiddenWord, s_UsedLetters);
				CheckAns(s_HiddenWord, s_UsedLetters, s_Answer, i_Mistakes);
				GameOver(s_HiddenWord, s_Answer, s_UsedLetters, i_Mistakes, b_GameOver);

			} 

		cout << "Would you like to play again? (y/n)" << endl;
		cin >> c_PlayAgain;

	} while (c_PlayAgain == 'y');
	



	//END
	return 0;
}

void DrawHangman(int wrongs, string word, string& usedLetters) {
	
	for (int i = 0; i < 8; i++) {
		cout << endl;

		for (int j = 0; j < 160; j= j+10) {

			int ij = i + j;

			switch (ij) //drawing the hangman
			{
				case 20:
				{
					cout << "=";
					break;
				}
				case 30:
				{
					cout << "=";
					break;
				}
				case 40:
				{
					cout << "=";
					break;
				}
				case 50:
				{
					cout << "=";
					break;
				}
				case 60:
				{
					cout << "=";
					break;
				}
				case 65:
				{
					if (wrongs < 6)
					{
						cout << " ";
					}
					else
					{
						cout << "/";
					}
					break;
				}
				case 66:
				{
					if (wrongs < 7)
					{
						cout << " ";
					}
					else
					{
						cout << "/";
					}
					
					break;
				}
				case 70:
				{
					if (wrongs < 1)
					{
						cout << " ";
					}
					else
					{
						cout << "|";
					}
					
					break;
				}
				case 71:
				{
					if (wrongs < 2)
					{
						cout << " ";
					}
					else
					{
						cout << "|";
					}
					break;
				}
				case 72:
				{
					if (wrongs < 3)
					{
						cout << " ";
					}
					else
					{
						cout << "|";
					}
					break;
				}
				case 73:
				{
					if (wrongs < 4)
					{
						cout << " ";
					}
					else
					{
						cout << "|";
					}
					break;
				}
				case 74:
				{
					if (wrongs < 5)
					{
						cout << " ";
					}
					else
					{
						cout << "O";
					}
					
					break;
				}
				case 75:
				{
					if (wrongs < 6)
					{
						cout << " ";
					}
					else
					{
						cout << "|";
					}
					
					break;
				}
				case 85:
				{
					if (wrongs < 6)
					{
						cout << " ";
					}
					else
					{
						cout << "\\";
					}
					
					break;
				}
				case 86:
				{
					if (wrongs < 8)
					{
						cout << " ";
					}
					else
					{
						cout << "\\";
					}
					
					break;
				}
				case 7:
				{
					cout << "_";
					break;
				}
				case 17:
				{
					cout << "_";
					break;
				}
				case 21:
				{
					cout << "|";
					break;
				}
				case 22:
				{
					cout << "|";
					break;
				}
				case 23:
				{
					cout << "|";
					break;
				}
				case 24:
				{
					cout << "|";
					break;
				}
				case 25:
				{
					cout << "|";
					break;
				}
				case 26:
				{
					cout << "|";
					break;
				}
				case 27:
				{
					cout << "|";
					break;
				}
				case 37:
				{
					cout << "_";
					break;
				}
				case 47:
				{
					cout << "_";
					break;
				}
				case 103:
				{
					for (int i = 0; i < word.length(); i++)
					{
						cout << word[i] << " ";
						
					}
					break;
				}
				case 131: 
				{
					cout << "Used letters: " << usedLetters;
					break;
				}
				

				default:
				{
					cout << " ";
					break;
				}
					
			}

			
			

			}
	}
	cout << endl;
}

void CheckAns(string& hidden, string& used, string& answer, int& errors) { 
	string s_Input;
	cin >> s_Input;
	s_Input = s_Input[0];
	size_t foundInAns = answer.find(s_Input);
	size_t foundInUsed = used.find(s_Input);

	//checking if input is found in the hidden word and in the used letters

	if (foundInAns != answer.npos && foundInUsed == used.npos) 
	{
		for (int i = 0; i < answer.length(); i++) {

			if (s_Input[0] == answer[i])
			{
				hidden[i] = answer[i];
				
			}

		}
		used += "*" + s_Input;
	}
	else if (foundInUsed != used.npos)
	{
		cout << "You already typed " << s_Input;
	}
	else if (foundInAns == answer.npos && foundInUsed == used.npos)
	{
		used += "*" + s_Input;
		errors++;
	}

}

bool GameOver(string hidden, string answer, string used, int errors, bool& gameOver) { //checking the conditions if the game is over
	
	if (errors >= 8)
	{
		DrawHangman(errors, hidden, used);
		cout << "\n\nSorry, you didn't get it this time. \nThe Answer is: " << answer << endl;
		gameOver = true;
		
	}
	else if (hidden == answer)
	{
		cout << "Hooray! you got it!" << endl;
		gameOver = true;
		
	}
	return gameOver;
} 