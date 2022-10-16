#include <iostream>
#include <string.h>
using namespace std;
int N;
int assumed[55][55];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i,j;
	memset(assumed, -1, sizeof(assumed));
	assumed[0][0] = 1;
	assumed[N - 1][N - 1] = 0;
	for (i = 0; i <N; i+=2)
	{
		for (j = 0; j < N; j+=2)
		{
			if ((i == 0 && j == 0)||(i==N-1&&j==N-1))
				continue;
			else if (!j)
			{
				cout << '?' <<' '<< i - 1 << ' ' << 1 << ' ' << i + 1 << ' ' << 1 << '\n';
				cout.flush();
				int a;
				cin >> a;
				if (a)
				{
					assumed[i][j] = assumed[i - 2][j];
				}
				else
				{
					assumed[i][j] = (assumed[i - 2][j] + 1) % 2;
				}
			}
			else
			{
				cout << '?' << ' ' << i + 1 << ' ' << j-1 << ' ' << i + 1 << ' ' << j+1 << '\n';
				cout.flush();
				int a;
				cin >> a;
				if (a)
				{
					assumed[i][j] = assumed[i][j-2];
				}
				else
				{
					assumed[i][j] = (assumed[i][j-2] + 1) % 2;
				}
			}
		}
	}
	cout << '?' << ' ' << 1 << ' ' << 1 << ' ' << 2 << ' ' << 2 << '\n';
	cout.flush();
	int a;
	cin >> a;
	if (a)
	{
		assumed[1][1] = 1;
	}
	else
	{
		assumed[1][1] = 0;
	}
	for (i = 1; i < N; i += 2)
	{
		for (j = 1; j < N; j+=2)
		{
			if ((i == 1 && j == 1) )
				continue;
			else if (j==1)
			{
				cout << '?' << ' ' << i - 1 << ' ' << 2 << ' ' << i + 1 << ' ' << 2 << '\n';
				cout.flush();
				int a;
				cin >> a;
				if (a)
				{
					assumed[i][j] = assumed[i - 2][j];
				}
				else
				{
					assumed[i][j] = (assumed[i - 2][j] + 1) % 2;
				}
			}
			else
			{
				cout << '?' << ' ' << i + 1 << ' ' << j - 1 << ' ' << i + 1 << ' ' << j + 1 << '\n';
				cout.flush();
				int a;
				cin >> a;
				if (a)
				{
					assumed[i][j] = assumed[i][j - 2];
				}
				else
				{
					assumed[i][j] = (assumed[i][j - 2] + 1) % 2;
				}
			}
		}
	}
	assumed[1][0] = 1;
	for (i = 1; i < N; i+=2)
	{
		for (j = 0; j < N; j += 2)
		{
			if ((i == 1 && j == 0) )
				continue;
			else if (j == 0)
			{
				cout << '?' << ' ' << i - 1 << ' ' << 1 << ' ' << i + 1 << ' ' << 1 << '\n';
				cout.flush();
				int a;
				cin >> a;
				if (a)
				{
					assumed[i][j] = assumed[i - 2][j];
				}
				else
				{
					assumed[i][j] = (assumed[i - 2][j] + 1) % 2;
				}
			}
			else
			{
				cout << '?' << ' ' << i + 1 << ' ' << j - 1 << ' ' << i + 1 << ' ' << j + 1 << '\n';
				cout.flush();
				int a;
				cin >> a;
				if (a)
				{
					assumed[i][j] = assumed[i][j - 2];
				}
				else
				{
					assumed[i][j] = (assumed[i][j - 2] + 1) % 2;
				}
			}
		}
	}
	cout << '?' << ' ' << 2 << ' ' << 1 << ' ' << 3 << ' ' << 2 << '\n';
	cout.flush();
	cin >> a;

	if (a)
	{
		assumed[2][1] = 1;
	}
	else
	{
		assumed[2][1] = 0;
	}
	cout << '?' << ' ' << 1 << ' ' << 2 << ' ' << 3 << ' ' << 2 << '\n';
	cout.flush();
	cin >> a;

	if (a)
	{
		assumed[0][1] = assumed[2][1];
	}
	else
	{
		assumed[0][1] = (assumed[2][1]+1)%2;
	}
	for (i = 0; i < N; i += 2)
	{
		for (j = 1; j < N; j += 2)
		{
			if ((i == 0 && j == 1)||(i==2&&j==1))
				continue;
			else if (j == 1)
			{
				cout << '?' << ' ' << i - 1 << ' ' << 2 << ' ' << i + 1 << ' ' << 2 << '\n';
				cout.flush();
				int a;
				cin >> a;
				if (a)
				{
					assumed[i][j] = assumed[i - 2][j];
				}
				else
				{
					assumed[i][j] = (assumed[i - 2][j] + 1) % 2;
				}
			}
			else
			{
				cout << '?' << ' ' << i + 1 << ' ' << j - 1 << ' ' << i + 1 << ' ' << j + 1 << '\n';
				cout.flush();
				int a;
				cin >> a;
				if (a)
				{
					assumed[i][j] = assumed[i][j - 2];
				}
				else
				{
					assumed[i][j] = (assumed[i][j - 2] + 1) % 2;
				}
			}
		}
	}
	int x = 0;
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - 1; j++)
		{
			if (j < N - 2)
			{
				int fres = ((assumed[i][j + 1] == assumed[i][j + 2]) || (assumed[i + 1][j] == assumed[i + 1][j + 1])) && (assumed[i][j] == assumed[i + 1][j + 2]);
				int sres = ((assumed[i][j + 1] != assumed[i][j + 2]) || (assumed[i + 1][j] != assumed[i + 1][j + 1])) && (assumed[i][j] != assumed[i + 1][j + 2]);
				if (fres != sres)
				{
					cout << '?' << ' ' << i +1 << ' ' << j + 1 << ' ' << i + 2 << ' ' << j + 3 << '\n';
					cout.flush();
					int a;
					cin >> a;
					if (a != fres)
					{
						x = 1;
					}
					goto t;
				}
			}
			if (i < N - 2)
			{
				int fres = ((assumed[i+1][j] == assumed[i+2][j]) || (assumed[i + 1][j+1] == assumed[i][j + 1])) && (assumed[i][j] == assumed[i + 2][j + 1]);
				int sres = ((assumed[i + 1][j] != assumed[i + 2][j]) || (assumed[i + 1][j + 1] != assumed[i][j + 1])) && (assumed[i][j] != assumed[i + 2][j + 1]);
				if (fres != sres)
				{
					cout << '?' << ' ' << i + 1 << ' ' << j + 1 << ' ' << i + 3 << ' ' << j + 2 << '\n';
					cout.flush();
					int a;
					cin >> a;
					if (a != fres)
					{
						x = 1;
					}
					goto t;
				}
			}
		}
	}
	t:
	if (x)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (!((i + j) % 2))
					continue;
				assumed[i][j] = (assumed[i][j] + 1) % 2;
			}
		}
	}
		
	
	cout << '!'<<'\n';
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cout << assumed[i][j];
		}
		cout << '\n';
	}
}