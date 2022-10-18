#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef double K;
constexpr int INF = 0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define X first
#define Y second

const int N = 3e5 + 5;

ll asph[N];
int par[N];
set<ii> kraw[N];
vi ans;
int d;
set<pair<ll, int>> cands;

int Find(int v) {
	return v == par[v] ? v : v = Find(par[v]);
}

void Union(int v, int u) {
	v = Find(v), u = Find(u);
	if(v == u) return;
	if(SZ(kraw[v]) < SZ(kraw[u])) swap(v, u);
	par[u] = v;
	TRAV(x, kraw[u]) kraw[v].insert(x);
	cands.erase({-asph[u], u});
	cands.erase({-asph[v], v});
	asph[v] += asph[u] - d;
	cands.insert({-asph[v], v});
}

void solve() {
	int n, m;
	cin >> n >> m >> d;
	FOR(i, 0, n) cin >> asph[i];
	ll sum = 0;
	FOR(i, 0, n) sum += asph[i];
	if(sum < 1ll * (n - 1) * d) {
		cout << "NO\n";
		return;
	}
	FOR(i, 0, m) {
		int a, b;
		cin >> a >> b;
		kraw[a - 1].insert({b - 1, i});
		kraw[b - 1].insert({a - 1, i});
	}
	FOR(i, 0, n) cands.insert({-asph[i], i});
	FOR(i, 0, n) par[i] = i;
	while(SZ(cands) > 1) {
		TRAV(gst, cands) {
			int v = gst.Y, kot = -1;
			vector<ii> wywal, upew;
			for(auto it = kraw[v].begin(); it != kraw[v].end(); it++) {
				int u = (*it).X;
				int id = (*it).Y;
				wywal.PB({u, id});
				u = Find(u);
				if(u == v) continue;
				upew.PB({u, id});
				if(asph[v] + asph[u] >= d) {
					kot = u;
					ans.PB(id);
					break;
				}
			}
			TRAV(x, wywal) kraw[v].erase(x);
			TRAV(x, upew) {
				auto it = kraw[v].lower_bound({x.X, 0});
				while(it != kraw[v].end() && (*it).X == x.X) {
					it = next(it);
					kraw[v].erase(prev(it));
				}
				kraw[v].insert(x);
			}
			if(kot != -1) {
				Union(v, kot);
				break;
			}
		}
	}
	cout << "YES\n";
	TRAV(x, ans) cout << x + 1 << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// int tt; cin >> tt;
	// FOR(te, 0, tt) {
	// 	// cout << "Case #" << te + 1 << ": ";
	// 	solve();
	// }
	solve();
	return 0;
}