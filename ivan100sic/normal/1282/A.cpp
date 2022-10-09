#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int a, b, c, r;
		cin >> a >> b >> c >> r;
		if (a > b)
			swap(a, b);
		int u = max(c-r, a);
		int v = min(c+r, b);
		cout << b-a-max(0, v-u) << '\n';
	}
}