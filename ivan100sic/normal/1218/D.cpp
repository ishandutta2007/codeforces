#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int mod1 = 1'000'000'007;
const int mod2 = 666'666'667;
const int sz = 131072;
const int logsz = 17;

vector<vector<int>> q;
vector<pair<int, int>> e[100005];
int p[100005], g[100005];
int n, m;
bool st[100005];

void dfs(int x) {
	st[x] = 1;
	for (auto [y, w] : e[x]) {
		if (!p[y]) {
			p[y] = x;
			g[y] = w;
			dfs(y);
		} else if (st[y] && y != p[x]) {
			vector<int> t = {w};
			for (int i=x; i!=y; i=p[i])
				t.push_back(g[i]);
			q.emplace_back(move(t));
		}
	}
	st[x] = 0;
}

template<int mod>
void wht(vector<int>& a) {
	for (int i=1; i<sz; i<<=1) {
		for (int j=0; j<sz; j++) {
			if (j & i) {
				int u = a[j-i], v = a[j];
				a[j-i] = u+v - (u+v>=mod)*mod;
				a[j]   = u-v + (u-v<0)*mod;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	int sve = 0;
	for (int i=0; i<m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].emplace_back(v, w);
		e[v].emplace_back(u, w);
		sve ^= w;
	}
	p[1] = 1;
	dfs(1);

	vector<int> sol1(sz), sol2 = sol1;
	sol1[sve] = sol2[sve] = 1;
	wht<mod1>(sol1);
	wht<mod2>(sol2);
	for (auto p : q) {
		vector<int> t1(sz), t2 = t1;
		for (int x : p)
			t1[x]++, t2[x]++;
		wht<mod1>(t1);
		wht<mod2>(t2);
		for (int i=0; i<sz; i++) {
			sol1[i] = sol1[i] * 1ll * t1[i] % mod1;
			sol2[i] = sol2[i] * 1ll * t2[i] % mod2;
		}
	}
	wht<mod1>(sol1);
	wht<mod2>(sol2);
	for (int i=0; i<sz; i++) {
		if (sol1[i] || sol2[i]) {
			cout << i << ' ' << sol1[i] * 742744451ll % mod1 << '\n';
			return 0;
		}
	}
}