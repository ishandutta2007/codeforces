#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long x[300009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	cin >> x[0];
	long long g = 0;
	for (int i = 1; i < n; i++) {
		cin >> x[i];
		g = gcd(g, x[i] - x[i - 1]);
	}
	int t = 0;
	for (int i = 1; i <= m; i++) {
		long long p; cin >> p;
		if (g % p == 0 && t == 0) 
			t = i;
	}
	if (t == 0) cout << "NO" << '\n';
	else {
		cout << "YES" << '\n';
		cout << x[0] << " " << t << '\n';
	}
	return 0;
}