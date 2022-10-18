#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF=0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < e; i++)
#define TRAV(x, a) for(auto &x: a)
#define SZ(x) ((int)(x).size())
#define PB push_back
#define PR pair
#define MP make_pair
#define X first
#define Y second

const int mod = 1e9+123;
const int N = 2e5+5;

vector<ii> G[N];
int daj[10][10], val[N];
int n, m, k, perf, akt, ans;

void gen(int kt){
	if(kt > k){
		ans += (akt == perf);
		return;
	}
	FOR(i, 0, kt){
		akt = (akt + daj[kt][i]) % mod;
		gen(kt+1);
		akt = (akt - daj[kt][i] + mod) % mod;
	}
}

void solve(){
	srand(123);
	cin >> n >> m >> k;
	n++;
	FOR(i, 1, n) val[i] = (rand()*rand() + rand())%mod, perf = (perf + val[i]) % mod;
	FOR(i, 0, m){
		int a, b, c;
		cin >> a >> b >> c;
		G[a].PB({c, b});
	}
	FOR(i, 1, n){
		sort(G[i].begin(), G[i].end());
		FOR(j, 0, SZ(G[i])) daj[SZ(G[i])][j] = (daj[SZ(G[i])][j] + val[G[i][j].Y]) % mod;
	}
	gen(1);
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 0, tt){
	// 	// cout << "Case #" << te+1 << ": ";
	// 	solve();
	// }
	solve();
	return 0;
}