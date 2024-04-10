#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll dp[2][5005];
ll cu[2][5005];
char buf[5005];
int nxt[5005];
int prv[30];
int n;

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n >> buf;
	for (int i = 0;i < 30;i++) prv[i] = n;
	for (int i = n-1;i >= 0;i--)
	{
		nxt[i] = prv[buf[i]-'a'];
		prv[buf[i]-'a'] = i;
	}
	for (int at = n-1;at >= 0;at--) for (int idx = n-1;idx >= 0;idx--)
	{
		if (at == n-1) dp[at&1][idx] = 1;
		else if (idx == n) dp[at&1][idx] = 0;
		else dp[at&1][idx] = cu[(at&1)^1][idx];
		cu[at&1][idx] = (cu[at&1][idx+1]+dp[at&1][idx]-dp[at&1][nxt[idx]]+MOD)%MOD;
	}

	ll ans = 0;
	set<char> hv;
	for (int i = 0;i < n;i++)
	{
		auto it = hv.lower_bound(buf[i]);
		if (it == hv.end() || *it != buf[i])
		{
			ans = (ans+dp[0][i])%MOD;
			hv.insert(it, buf[i]);
		}
	}
	cout << ans << endl;
	return 0;
}