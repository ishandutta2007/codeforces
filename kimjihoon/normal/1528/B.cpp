#include <iostream>
#include <algorithm>
using namespace std;

int p[1000009];
long long md = 998244353;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = i; j <= n; j += i)
			p[j]++;
	long long ans = 0, s = 1;
	for (int i = 0; i < n; i++) {
		ans = (ans + s * p[n - i]) % md;
		if (i) s = (s * 2) % md;
	}
	cout << ans << '\n';
	return 0;
}