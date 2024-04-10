#include <bits/stdc++.h>
using namespace std;
vector<int>pos[1010];
#define int long long
#define MOD 1000000007
int modinv(int n, int m = MOD - 2)
{
	if (m == 0)
		return 1;
	if(m % 2)
		return modinv(n, m - 1) * n % MOD;
	int a = modinv(n, m / 2);
	return a * a % MOD;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int a, b, c, d, e, f, g;
		cin >> a >> b >> c >> d >> e >> f >> g;
		int i;
		int ans = 0;
		int prob = 1;
		int mip = modinv(g);
		int miip = modinv(100 - g);
		int mih = modinv(100);
		int rrprob = 0;
		int dx = 1;
		int dy = 1;
		for (i = 0; i < (2*a-2) * (2*b-2); i++)
		{
			int rprob = prob * g % MOD * mih % MOD;
			if (c != e && d != f)
			{
				goto T;
			
			}
				
			
			rrprob += rprob;
			rrprob %= MOD;
			ans += rprob * i;
			ans %= MOD;
			prob *= 100-g;
			prob%=MOD;
			prob *= mih;
			prob %= MOD;
			T:
			if (c == a)
				dx = -1;
			if (c == 1)
				dx = 1;
			if (d == b)
				dy = -1;
			if (d == 1)
				dy = 1;
			c += dx;
			d += dy;
		}
		ans *= modinv(rrprob);
		ans %= MOD;
		int rans = ans + ((2*a-2) *( 2*b-2) * ((1-rrprob+MOD)*modinv(rrprob)%MOD));
		cout << rans % MOD << '\n';
	}
}