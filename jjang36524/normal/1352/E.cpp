#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int T, a, b, c, d;
int coun[8010];
int psum[8010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		long long N, K;
		cin >> N;
		memset(coun, 0, sizeof(coun));
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			psum[i + 1] = psum[i] + a;
			coun[a]++;
		}
		int ans = 0;
		for (i = 0; i < N; i++)
		{
			int j;
			for (j = i + 2; j <= N; j++)
			{
				if (psum[j] - psum[i] <= N)
				{
					ans += coun[psum[j] - psum[i]];
					coun[psum[j] - psum[i]] = 0;
				}
			}
		}
		cout << ans << '\n';
	}
}