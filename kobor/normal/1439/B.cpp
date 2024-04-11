#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define PR pair
#define MP make_pair
#define X first
#define Y second

const int N = 1e5+5;

int n, m, k;
int deg[N], stat[N], val[N], rox[N];
vi G[N];
set<int> intr, kozak;
vector<ll> g;

void zbij(int v){
	deg[v]--;
	if(stat[v] == 2 && deg[v] <= k-1){	// spad
		stat[v]--;
		kozak.erase(v);
		intr.insert(v);
	}
	if(stat[v] == 1 && deg[v] <= k-2){	// umar
		stat[v]--;
		intr.erase(v);
		TRAV(x, G[v]) if(stat[x]) rox[x] ^= val[v], zbij(x);
	}
}

void solve(){
	cin >> n >> m >> k;
	FOR(i, 0, n) G[i].clear();
	g.clear();
	intr.clear();
	kozak.clear();
	FOR(i, 0, n) val[i] = rox[i] = rand();
	FOR(i, 0, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].PB(b);
		G[b].PB(a);
		rox[a] ^= val[b];
		rox[b] ^= val[a];
		g.PB(1ll*INF*a+b);
		g.PB(1ll*INF*b+a);
	}
	sort(g.begin(), g.end());
	FOR(i, 0, n){
		deg[i] = SZ(G[i]) + 1;
		stat[i] = 2;
		kozak.insert(i);
	}
	FOR(i, 0, n) zbij(i);
	while(SZ(intr) > 0){
		int v = *intr.begin();
		vi ziomy;
		TRAV(x, G[v]) if(stat[x]) ziomy.PB(x);
		bool ok = 1;
		TRAV(x, ziomy) if(stat[x] == 1 && rox[x] != rox[v]) ok = 0;
		FOR(i, 0, SZ(ziomy)){
			if(!ok) break;
			FOR(j, i+1, SZ(ziomy)){
				if(!ok) break;
				ll co = 1ll*INF*ziomy[i]+ziomy[j];
				int ind = lower_bound(g.begin(), g.end(), co) - g.begin();
				if(ind == SZ(g)) ok = 0;
				else ok &= g[ind] == co;
			}
		}
		if(ok){
			cout << 2 << '\n';
			TRAV(x, ziomy) cout << x+1 << ' ';
			cout << v+1 << '\n';
			return;
		}
		zbij(v);
	}
	if(SZ(kozak) > 0){
		cout << 1 << ' ' << SZ(kozak) << '\n';
		TRAV(x, kozak) cout << x+1 << ' ';
		cout << '\n';
	}
	else cout << -1 << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(123);
	int tt; cin >> tt;
	FOR(te, 0, tt){
		// cout << "Case #" << te+1 << ": ";
		solve();
	}
	// solve();
	return 0;
}