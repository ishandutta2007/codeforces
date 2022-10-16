#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define int long long
using namespace std;
int N,M,T;
string s;
int countbal[300100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N>>M>>s;
		M += N;
		int b = N;
		int i;
		for (i = 0; i < N; i++)
		{
			if (s[i] == '1')
				b--;
			else
				b++;
			countbal[b]++;
		}
		int oneturn = b - N;
		if (oneturn == 0 && M>=0&&M <= 2 * N && countbal[M])
			cout << -1 << '\n';
		else if (oneturn == 0)
			cout << 0 << '\n';
		else
		{
			int ans = 0;
			if (M == N)
				ans++;
			for (i = 0; i <= 2 * N; i++)
			{
				if (oneturn > 0)
				{
					if (i <= M && (i % oneturn == ((M+oneturn*(1<<30))) % oneturn))
						ans += countbal[i];
				}
				else
				{
					if (i >= M && (i % (-oneturn) == ((M - oneturn * (1 << 30) )% (-oneturn))))
						ans += countbal[i];
				}
			}
			cout << ans << '\n';
		}
		b = N;
		for (i = 0; i < N; i++)
		{
			if (s[i] == '1')
				b--;
			else
				b++;
			countbal[b]--;
		}
	}
}