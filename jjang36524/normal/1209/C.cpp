#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
int T,N;
int minpos[10];
int maxpos[10];
int b12[10];
int boarder;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		memset(minpos, 1, sizeof(minpos));
		memset(maxpos, 0, sizeof(maxpos));
		memset(b12, 0, sizeof(b12));
		boarder = 0;
		string input;
		cin >> input;
		int i;
		for (i = 0; i < N; i++)
		{
			int num = input[i] - '0';
			minpos[num] = min(minpos[num], i);
			maxpos[num] = i;
		}
		int stcases=0;
		int stp=10;
		int oldbor=0;
		for (i = 0; i < 10; i++)
		{
			if (minpos[i] < boarder)
			{
				stcases++;
				stp = i;
				if (stcases == 2)
				{
					cout << '-' << '\n';
					goto T;
				}
				else
				{
					int j;
					oldbor = boarder;
					for (j = 0; j < N; j++)
					{
						if (j < oldbor&&input[j]-'0'==i)
							boarder = j;
					}
				}
			}
			else
			{
				if(minpos[i]<=N)
					boarder = maxpos[i];
				
			}
		}
		for (i = 0; i < N; i++)
		{
			if (input[i]-'0' < stp)
				cout << '1';
			else if (input[i] - '0' == stp)
			{
				if (i > oldbor)
					cout << '1';
				else
					cout << '2';
			}
			else
			{
				cout << '2';
			}
		}
	T:
		cout << '\n';
		int d;
		
	}
}