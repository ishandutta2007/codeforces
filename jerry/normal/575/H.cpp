// ncr(2n+2, n+1)-1
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int n;

ll mdpow(ll b, int e)
{
	if (e == 0) return 1;
	if (e == 1) return b;
	ll m = mdpow(b, e>>1);
	m = (m*m) % MOD;
	if (e&1) m = (m*b) % MOD;
	return m;
}

int main()
{
	cin >> n;
	ll ans = 1;
	for (int i = n+2;i <= 2*n+2;i++)
		ans = (ans * i) % MOD;
	for (int i = 2;i <= n+1;i++)
		ans = (ans * mdpow(i, 1000000005)) % MOD;
	cout << --ans << endl;
	return 0;
}