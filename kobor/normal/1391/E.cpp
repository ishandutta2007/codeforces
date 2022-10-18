#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF=0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define PR pair
#define MP make_pair
#define X first
#define Y second

const int N = 5e5+5;

vi G[N];
int dpth[N], par[N], fre[N];

void dfs(int v, int p){
	dpth[v] = dpth[p]+1;
	par[v] = p;
	TRAV(x, G[v]) if(!dpth[x]) dfs(x, v);
}

void solve(){
	int n, m;
	cin >> n >> m;
	FOR(i, 1, n+1) G[i].clear();
	FOR(i, 1, n+1) fre[i] = dpth[i] = 0;
	FOR(i, 0, m){
		int a, b;
		cin >> a >> b;
		G[a].PB(b), G[b].PB(a);
	}
	dfs(1, 1);
	FOR(i, 1, n+1){
		if(dpth[i] >= (n+1)/2){
			cout << "PATH\n";
			cout << dpth[i] << '\n';
			while(i != 1){
				cout << i << ' ';
				i = par[i];
			}
			cout << 1 << '\n';
			return;
		}
	}
	vector<ii> ans;
	FOR(i, 1, n+1){
		if(fre[dpth[i]]){
			ans.PB({i, fre[dpth[i]]});
			fre[dpth[i]] = 0;
		}
		else fre[dpth[i]] = i;
	}
	cout << "PAIRING\n";
	cout << SZ(ans) << '\n';
	TRAV(x, ans) cout << x.X << ' ' << x.Y << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin>>tt;
	FOR(te, 0, tt){
		// cout << "Case #" << te+1 << ": ";
		solve();
	}
	// solve();
	return 0;
}