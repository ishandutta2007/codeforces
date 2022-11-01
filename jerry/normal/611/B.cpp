#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll foo(ll x)
{
	if (x <= 1) return 0;
	if (x <= 3) return 1;
	ll res = 0;
	ll pow = 4;
	while (pow < x) pow <<= 1;
	ll po2 = pow >> 1;
	pow--; po2--;
	for (int i = 0;i < __builtin_popcountll(po2);i++)
		res += i;
	for (int i = 0;i+1 < __builtin_popcountll(pow);i++) if (pow-(1ll<<i) <= x)
		res++;
	return res;
}

int main()
{
	ll a, b;
	cin >> a >> b;
	cout << foo(b)-foo(a-1) << endl;
	return 0;
}