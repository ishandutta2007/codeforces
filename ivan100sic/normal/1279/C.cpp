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
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int& x : a)
			cin >> x;
		reverse(a.begin(), a.end());
		set<int> b;
		ll sol = 0;
		while (m--) {
			int x;
			cin >> x;
			if (b.count(x)) {
				sol++;
				b.erase(x);
			} else {
				sol += 2 * b.size();
				while (1) {
					int t = a.back();
					a.pop_back();
					if (t == x) {
						sol++;
						break;
					} else {
						b.insert(t);
						sol += 2;
					}
				}
			}
		}
		cout << sol << '\n';
	}
}