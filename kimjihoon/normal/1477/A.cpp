#include <iostream>
#include <algorithm>
using namespace std;

long long x[200009];

long long gcd(long long a, long long b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; long long k; cin >> n >> k;
		long long s = 0;
		for (int i = 1; i <= n; i++) 
			cin >> x[i];
		sort(x + 1, x + n + 1);
		for (int i = 2; i <= n; i++)
			s = gcd(s, x[i] - x[1]);
		if (((x[1] % s) + s) % s == ((k % s) + s) % s) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}