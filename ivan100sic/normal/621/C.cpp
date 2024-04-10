#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, p;
ld q[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> p;
	for (int i=0; i<n; i++) {
		int l, r;
		cin >> l >> r;
		q[i] = (ld)(r/p - (l-1)/p) / (r-l+1);
	}
	q[n] = q[0];

	ld e = 0;

	for (int i=0; i<n; i++) {
		ld g = q[i] + q[i+1] - q[i]*q[i+1];
		e += g;
	}

	cout.precision(20);
	cout << fixed << 2000*e << '\n';
}