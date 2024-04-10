#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353
int dp[1010];
int cnt[1010];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i;
	for (i = 2; i <= 1000; i++)
	{
		memset(cnt, 0, sizeof(cnt));
		int j;
		for (j = 0; j <= i - 2; j++)
		{
			cnt[dp[j] ^ dp[i - 2 - j]]++;
		}
		for (j = 0;; j++)
		{
			if (cnt[j] == 0)
			{
				dp[i] = j;
				break;
			}
		}
	}
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		string s;
		cin >> s;
		int i;
		int rc = 0;
		int bc = 0;
		int befc = 0;
		int ans = 0;
		for (i = 0; i < s.size(); i++)
		{
			if (s[i] == 'R')
				rc++;
			else
				bc++;
			if (i&&s[i] != s[i - 1])
			{
				befc++;
			}
			else
			{
				if(befc<=100)
					ans ^= dp[befc + 1];
				else
					ans ^= dp[(befc + 1-101)%34+67];
				befc = 0;
			}
		}
		if (befc <= 100)
			ans ^= dp[befc + 1];
		else
			ans ^= dp[(befc + 1 - 101) % 34 + 67];
		if (rc < bc)
			cout << "Bob" << '\n';
		else if (rc > bc)
			cout << "Alice" << '\n';
		else
			cout << (ans ? "Alice" : "Bob") << '\n';
	}
}