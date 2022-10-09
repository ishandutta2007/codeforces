#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	int x, y;
	bool operator< (const pt& b) const {
		return tie(x, y) < tie(b.x, b.y);
	}
	bool operator== (const pt& b) const {
		return tie(x, y) == tie(b.x, b.y);
	}
};

int n;
pt a[10005];
vector<pt> sol;

void solve(int l, int r) {
	if (r-l <= 1)
		return;
	int m = (l+r) >> 1;
	int x = a[m].x;
	vector<int> y;
	for (int i=l; i<r; i++)
		y.push_back(a[i].y);
	sort(y.begin(), y.end());
	y.erase(unique(y.begin(), y.end()), y.end());
	for (int j : y)
		sol.push_back({x, j});
	solve(l, m);
	solve(m, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i].x >> a[i].y;
	sort(a, a+n);
	sol.assign(a, a+n);
	solve(0, n);
	sort(sol.begin(), sol.end());
	sol.erase(unique(sol.begin(), sol.end()), sol.end());
	cout << sol.size() << '\n';
	for (auto [x, y] : sol)
		cout << x << ' ' << y << '\n';
}