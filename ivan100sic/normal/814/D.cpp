#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll kv(ll x) {
	return x*x;
}

struct krug {
	ll x, y, r;

	bool je_unutar(krug b) const {
		return r <= b.r && kv(x - b.x) + kv(y - b.y) <= kv(b.r);
	}
};

int n;
krug a[1005];
ll b[1005];
vector<int> e[1005];
vector<int> roots;

ll sol = 0;

void dfs(int x, int d) {
	if (d <= 1 || d % 2 == 1) {
		sol += b[x];
	} else {
		sol -= b[x];
	}
	for (int y : e[x]) {
		dfs(y, d+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].r;
		b[i] = kv(a[i].r);
	}

	for (int i=1; i<=n; i++) {
		int naj = -1;
		for (int j=1; j<=n; j++) if (j != i) {
			if (a[i].je_unutar(a[j])) {
				if (naj == -1 || a[j].r < a[naj].r) {
					naj = j;
				}
			}
		}
		if (naj != -1) {
			e[naj].push_back(i);
			cerr << naj << ' ' << i << '\n';
		} else {
			roots.push_back(i);
		}
	}

	for (int x : roots) {
		dfs(x, 0);
	}

	cout.precision(20);
	cout << fixed << sol * 3.14159265358979323;




}