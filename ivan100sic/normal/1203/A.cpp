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

	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& x : a)
			cin >> x;
		vector<int> b = a, c = a;
		sort(b.begin(), b.end());
		c = b;
		reverse(c.begin(), c.end());
		bool ok = false;
		for (int i=0; i<n; i++) {
			rotate(a.begin(), a.begin()+1, a.end());
			if (a == b || a == c)
				ok = true;
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}