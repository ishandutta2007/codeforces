#include <iostream>

using namespace std;

typedef long long ll;

#define MOD  1000000007ll

char buf[100002];
ll fact[100002];
ll exp[100002];
ll prs[100002];
ll d[100002];
ll ans;
int n;
int k;

ll po(ll a, ll e)
{
	if (e == 0ll) return 1ll;
	if (e == 1ll) return a;
	ll b = po(a, e>>1);
	b = (b*b)%MOD;
	if (e&1) return ((a*b)%MOD);
	return b;
}

ll inv(ll a)
{
	return po(a, MOD-2ll);
}

ll ncr(int a, int b)
{
	if (b > a) return 0ll;
	return ((((fact[a]*inv(fact[b]))%MOD)*inv(fact[a-b]))%MOD);
}

int main()
{
	cin.sync_with_stdio(false); cin >> n >> k >> buf;
	exp[0] = 1ll;
	for (int i = 1;i <= n;i++)
		exp[i] = (exp[i-1]*10ll)%MOD;
	fact[0] = 1ll;
	for (int i = 1;i <= n;i++)
		fact[i] = (fact[i-1]*((ll)i))%MOD;
	for (int i = 0;i < n;i++)
		d[i] = buf[i] - '0';
	prs[0] = d[0];
	for (int i = 1;i < n;i++)
		prs[i] = prs[i-1] + d[i];
	for (int i = 0;i < n-1;i++)
		ans = (((((exp[i]*ncr(n-i-2, k-1))%MOD)*prs[n-i-2])%MOD)+ans)%MOD;
	for (int i = 0;i < n;i++)
		ans = (((((exp[n-i-1]*ncr(i, k))%MOD)*d[i])%MOD)+ans)%MOD;
	cout << ans << "\n";
	return 0;
}