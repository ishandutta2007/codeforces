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

	int n, v;
	cin >> n >> v;
	basic_string<int> z;
	for (int i=1; i<=n; i++) {
		int k, ok=0;
		cin >> k;
		while (k--) {
			int x;
			cin >> x;
			if (v > x)
				ok = 1;
		}
		if (ok)
			z += i;
	}
	cout << size(z) << '\n';
	for (int x : z)
		cout << x << ' ';
	cout << '\n';
}