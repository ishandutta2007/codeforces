// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int m, n, k, t;
int a[200005];

int l[200005], r[200005], d[200005];

struct seg {
	int l, r;
	template<class T>
	auto operator< (const T& b) const {
		return l < b.l;
	}
};

int resi(vector<seg> s) {
	if (s.size() == 0)
		return n+1;
	sort(begin(s), end(s));
	vector<seg> t;
	for (auto [l, r] : s) {
		if (t.empty()) {
			t.push_back({l, r});
		} else {
			if (t.back().r < l) {
				t.push_back({l, r});
			} else {
				t.back().r = max(t.back().r, r);
			}
		}
	}

	int sol = 3*n+3, fri = n+1;
	for (auto [l, r] : t)
		fri -= r-l;
	sol -= 2*fri;
	sol += 2*t.size();
	return sol;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> m >> n >> k >> t;
	for (int i=0; i<m; i++)
		cin >> a[i];
	for (int i=0; i<k; i++)
		cin >> l[i] >> r[i] >> d[i];

	int lo = 0, hi = 200000, o = 200005;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		// disarmuj sve trapove do mid+1 na gore
		vector<seg> s;
		for (int i=0; i<k; i++) {
			if (d[i] > mid) {
				s.push_back({l[i], r[i]});
			}
		}
		int rs = resi(s);
		if (rs <= t) {
			// ok
			o = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout << count_if(a, a+m, [&](int x) { return x >= o; }) << '\n';
}