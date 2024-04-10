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
		int n;
		cin >> n;
		int a, b, u=0, v=0;
		cin >> a >> b;
		while (a--) {
			int x;
			cin >> x;
			u = max(u, x);
		}
		while (b--) {
			int x;
			cin >> x;
			v = max(v, x);
		}
		cout << (u == n ? "YES\n" : "NO\n");
	}
}