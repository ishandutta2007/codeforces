#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll x[100005], y[100005];
ll n, j;
ll p, q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> j;
	j %= 2*n;

	cin >> p >> q;
	for (int i=0; i<n; i++)
		cin >> x[i] >> y[i];

	for (int i=0; i<j; i++) {
		p = 2*x[i % n] - p;
		q = 2*y[i % n] - q;
	}

	cout << p << ' ' << q << '\n';
}