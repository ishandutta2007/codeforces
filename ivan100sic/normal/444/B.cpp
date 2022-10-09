#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll x;

ll getnx() {
	x = (x * 37 + 10007) % 1000000007;
	return x;
}

int a[100005], b[100005], n, d;
basic_string<int> bplus;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> d >> x;
	for (int i=0; i<n; i++)
		a[i] = i+1;
	for (int i=0; i<n; i++)
		swap(a[i], a[getnx() % (i+1)]);
	for (int i=0; i<n; i++)
		if (i < d)
			b[i] = 1;
		else
			b[i] = 0;
	for (int i=0; i<n; i++)
		swap(b[i], b[getnx() % (i+1)]);

	// resi
	if (d >= 4000) {
		set<pair<int, int>> s;
		for (int i=0; i<n; i++) {
			int c = 0;
			s.insert({-a[i], i});
			for (auto [p, q] : s) {
				if (b[i-q]) {
					c = -p;
					break;
				}
			}
			cout << c << '\n';
		}
	} else {
		for (int i=0; i<n; i++)
			if (b[i])
				bplus += i;

		for (int i=0; i<n; i++) {
			int c = 0;
			for (int x : bplus) {
				if (x > i)
					break;
				c = max(c, a[i-x]);
			}
			cout << c << '\n';
		}
	}
		
}