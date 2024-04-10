#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct stvar {
	int l, r, x;
};

int n;
vector<pair<int, ll>> b;
basic_string<stvar> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		st.push_back({i, i+1, x});
		for (auto& p : st) {
			p.x = gcd(p.x, x);
		}
		int j = 0;
		for (int i=1; i<(int)st.size(); i++) {
			if (st[i].x == st[j].x) {
				st[j].r = st[i].r;
			} else {
				st[++j] = st[i];
			}
		}
		st.resize(j+1);
		for (auto& p : st) {
			b.push_back({p.x, p.r-p.l});
		}
	}
	sort(b.begin(), b.end());
	int j = 0;
	for (int i=1; i<(int)b.size(); i++) {
		if (b[i].first == b[j].first) {
			b[j].second += b[i].second;
		} else {
			b[++j] = b[i];
		}
	}
	b.resize(j+1);
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		auto it = lower_bound(b.begin(), b.end(), make_pair(x, 0ll));
		if (it == b.end() || it->first != x) {
			cout << "0\n";
		} else {
			cout << it->second << '\n';
		}
	}
}