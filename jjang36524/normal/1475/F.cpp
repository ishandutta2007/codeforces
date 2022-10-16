#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
char arr[2][1001][1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int i;
		for (i = 0; i < N; i++)
		{
			cin >> arr[0][i];
		}
		for (i = 0; i < N; i++)
		{
			cin >> arr[1][i];
			int j;
			for (j = 0; j < N; j++)
			{
				arr[1][i][j] ^= arr[0][i][j];
			}
		}
		int cur = 1;
		for (i = 0; i < N; i++)
		{
			int j;
			for (j = 1; j < N; j++)
			{
				if ((arr[1][i][0] == arr[1][i][j]) != (arr[1][0][0] == arr[1][0][j]))
					cur = 0;
			}
		}
		cout << (cur?"YES" : "NO") << '\n';
	}
}