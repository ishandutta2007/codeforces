#include <iostream>
#include <algorithm>
using namespace std;
char arr[200006];
int Q, K, N;
int psum[200006][3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> Q;
	while (Q--)
	{
		cin >> N >> K;
		memset(psum, 0, N * 12);
		scanf("%s", arr);
		int i;
		for (i = 0; i < N; i++)
		{
			if (arr[i] == 'R')
				arr[i] = 0;
			if (arr[i] == 'G')
				arr[i] = 1;
			if (arr[i] == 'B')
				arr[i] = 2;
		}
		for (i = 0; i < N; i++)
		{
			if (i)
			{
				psum[i][0] = psum[i - 1][0];
				psum[i][1] = psum[i - 1][1];
				psum[i][2] = psum[i - 1][2];
			}
			psum[i][(arr[i]-i+333333)%3]++;
		}
		int ans = 1101000;
		for (i = 0; i < 3; i++)
		{
			int j;
			ans = min(ans, K-psum[K-1][i]);
			for (j = K; j < N; j++)
			{
				ans = min(ans, K-psum[j][i] + psum[j - K][i]);
			}
		}
		cout << ans << '\n';
	}
}