// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct seg {
	int l, r;
	template<class T>
	auto operator< (const T& b) const {
		return r < b.r;
	}
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	cin >> n;
	vector<seg> vs(n);
	for (int i=0; i<n; i++) {
		int l, r;
		cin >> l >> r;
		if (l > r)
			swap(l, r);
		vs[i] = {l, r};
	}

	vector<int> sol;

	while (vs.size()) {
		sort(begin(vs), end(vs));
		int x = vs[0].r;
		vs.erase(remove_if(begin(vs), end(vs), [x](seg s) {
			return s.l <= x && x <= s.r;
		}), vs.end());
		sol.push_back(x);
	}
	cout << sol.size() << '\n';
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}