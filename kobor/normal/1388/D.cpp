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

const int N = 2e5+5;

ll t[N], ans;
vi G[N], kol, sa;
bool inc[N];
int n;

void dfs(int v){
	TRAV(x, G[v]){
		dfs(x);
		t[v] += max(t[x], 0ll);
		if(t[x] > 0) kol.PB(x);
		else sa.PB(x);
	}
	ans += t[v];
}

void solve(){
	cin >> n;
	FOR(i, 0, n) cin >> t[i];
	FOR(i, 0, n){
		int a;
		cin >> a;
		if(a > 0) G[a-1].PB(i), inc[i] = 1;
	}
	FOR(i, 0, n) if(!inc[i]) dfs(i), kol.PB(i);
	cout << ans << '\n';
	TRAV(x, kol) cout << x+1 << ' ';
	reverse(sa.begin(), sa.end());
	TRAV(x, sa) cout << x+1 << ' ';
	cout << '\n';
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