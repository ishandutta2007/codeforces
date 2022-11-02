#include <iostream>
using namespace std;

long long d[1000009], f[1000009], md = 998244353;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	d[1] = 1; d[2] = 2;
	int n; cin >> n;
	f[1] = 1;
	for (int i = 2; i <= n; i++)
		f[i] = (f[i - 1] * (long long)i) % md;
	for (int i = 3; i <= n; i++) 
		d[i] = (((d[i - 1] - 1LL + f[i - 1]) % md) * (long long)i) % md;
	cout << d[n] << '\n';
	return 0;
}