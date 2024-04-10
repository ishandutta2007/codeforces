#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, r, a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> r;
	a = 123123123;
	while (n--) {
		int x;
		cin >> x;
		a = min(x, a);
	}
	while (m--) {
		int x;
		cin >> x;
		b = max(x, b);
	}
	cout << max(r, r/a*b + r%a) << '\n';
}