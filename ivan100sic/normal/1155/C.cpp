#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

ll n, m;
ll x[300005], p[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> x[i];
	for (int i=0; i<m; i++)
		cin >> p[i];

	ll g = 0;
	for (int i=0; i<n; i++)
		g = gcd(g, x[i] - x[0]);

	for (int i=0; i<m; i++) {
		if (g % p[i] == 0) {
			cout << "YES\n";
			cout << x[0] << ' ' << i+1 << '\n';
			return 0;
		}
	}
	cout << "NO\n";
}