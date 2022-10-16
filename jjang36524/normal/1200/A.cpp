#include <iostream>
using namespace std;
int N;
char arr[100100];
int ass[10];
int main()
{
	scanf("%d", &N);
	scanf("%s", arr);
	int i;
	for (i = 0; i < N; i++)
	{
		if (arr[i] == 'L')
		{
			int j;
			for (j = 0; j < 10; j++)
			{
				if (!ass[j])
				{
					ass[j] = 1;
					break;
				}
			}
		}
		else if (arr[i] == 'R')
		{

			int j;
			for (j = 9; j >=0; j--)
			{
				if (!ass[j])
				{
					ass[j] = 1;
					break;
				}
			}
		}
		else
		{
			ass[arr[i] - '0'] = 0;
		}
	}
	for (i = 0; i < 10; i++)
	{
		cout << ass[i];
	}
}