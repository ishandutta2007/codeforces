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
		vector<int> a(n+1), b = a;
		for (int i=1; i<=n; i++)
			cin >> a[i], b[a[i]] = i;
		int l = 1e9, r = -1;
		for (int i=1; i<=n; i++) {
			l = min(l, b[i]);
			r = max(r, b[i]);
			cout << (r-l+1 == i);
		}
		cout << '\n';
	}
}