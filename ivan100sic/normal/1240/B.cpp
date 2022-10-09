#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct seg {
	int l, r;
	bool operator< (const seg& b) const {
		return l < b.l;
	}
};

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
		vector<int> l(n+1, 123123123), r(n+1, -1);
		for (int i=1; i<=n; i++) {
			int x;
			cin >> x;
			l[x] = min(l[x], i);
			r[x] = max(r[x], i);
		}
		vector<seg> b;
		for (int i=1; i<=n; i++) {
			if (r[i] != -1) {
				b.push_back({l[i], r[i]});
			}
		}
		int c=0, rr=-1, d=0, e=0;
		for (auto [u, v] : b) {
			if (u > rr)
				c++;
			else
				c = 1;
			rr = v;
			e = max(e, c);
			d++;
		}
		cout << d - e << '\n';
	}
}