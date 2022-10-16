#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;
int T, N,M, a, b, c, d;
int arr[31][31];
int sum[100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		int i, j;
		memset(sum, 0, sizeof(sum));
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				cin >> arr[i][j];
				sum[min(i + j, N + M - 2 - i - j)] += arr[i][j] ? 1 : -1;
			}
		}
		int ans = 0;
		for (i = 0; i < (N + M-1)/2; i++)
		{
			ans += (min((i+1)*2,min(N*2,M*2))-abs(sum[i]))/2;
		}
		cout << ans << '\n';
	}
}