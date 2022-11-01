#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

namespace UF
{
	int par[1005];
	void I(int n) { for (int i = 0;i < n;i++) par[i] = i; }
	int G(int a) { return par[a]==a?a:par[a]=G(par[a]); }
	void M(int a, int b) { par[G(a)] = G(b); }
};

ll dp[1005], ncr[1005][1005];

ll slv(int rem)
{
	if (rem == 0) return 1;
	if (dp[rem]) return dp[rem];
	for (int take = 1;take <= rem;take++)
	{
		dp[rem] += slv(rem-take)*ncr[rem-1][take-1];
		dp[rem] %= MOD;
	}
	return dp[rem];
}

char buf[64][1024];
ll ans = 1;
int n, m;

int main()
{
	for (int i = 0;i < 1005;i++)
	{
		ncr[i][0] = 1;
		for (int j = 1;j <= i;j++) ncr[i][j] = (ncr[i-1][j-1]+ncr[i-1][j])%MOD;
	}
	scanf("%d%d", &m, &n); UF::I(m);
	for (int i = 0;i < n;i++) scanf("%s", buf[i]); n++;
	for (int i = 0;i < m;i++) for (int j = i+1;j < m;j++)
	{
		int st = buf[0][i]^buf[0][j];
		bool ok = true;
		for (int k = 1;k < n;k++) if (st != (buf[k][i]^buf[k][j])) ok = false;
		if (ok) UF::M(i, j);
	}
	for (int i = 0;i < m;i++)
	{
		int num = 0;
		for (int j = 0;j < m;j++) if (UF::G(j) == i) num++;
		ans *= slv(num);
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}