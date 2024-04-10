#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct stanje {
	int di, offs;
	map<int, int> mp;

	stanje() {
		di = 0;
		offs = 0;
	}

	void inc(int x, int y) {
		int r = (mp[x-offs] += y) - mp[di];
		if (r > 0)
			di = x-offs;
		else if (r == 0 && x-offs < di)
			di = x-offs;
	}
};

int n;
vector<int> e[1000005];
int ans[1000005];

void spoji(stanje& a, stanje& b) {
	if (a.mp.size() < b.mp.size())
		swap(a, b);

	for (auto p : b.mp)
		a.inc(p.first + b.offs, p.second);
}

stanje solve(int x, int p) {
	stanje z;
	for (int y : e[x])
		if (y != p) {
			auto t = solve(y, x);
			spoji(z, t);
		}

	z.offs += 1;
	z.inc(0, 1);
	ans[x] = z.di + z.offs;

	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	scanf("%d", &n);
	for (int i=1; i<n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}

	solve(1, 1);
	for (int i=1; i<=n; i++)
		printf("%d\n", ans[i]);
}