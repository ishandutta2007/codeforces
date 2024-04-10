#include <iostream>
#include <algorithm>
#include <string.h>
#define int long long
using namespace std;
int N,M,T;
int arr[300][300];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		memset(arr, 0, sizeof(arr));
		cout << !(!(M % N)) * 2 << '\n';
		int i, j;
		int su = 0;
		for (i = 0; i < N; i++)
		{
			int j;
			for (j = 0; j < i; j++)
			{
				if (su == M)
					goto F;
				su++;
				arr[j][i - j-1] = 1;
			}
			for (j = i; j < N; j++)
			{
				if (su == M)
					goto F;
				su++;
				arr[j][i+N - j-1] = 1;
			}
		}
	F:
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				cout << arr[i][j];
			}
			cout << '\n';
		}
	}
}