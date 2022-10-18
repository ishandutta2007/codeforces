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

const int N = 1e5+5;

int maks[N], col[N];
ll sum[N];
map<int, int> mco[N];
vi G[N];
int n;

void dfs(int v, int p){
	ii gosc = {0, 0};
	for(auto &x: G[v]){
		if(x == p) continue;
		dfs(x, v);
		gosc = max(gosc, {SZ(mco[x]), x});
	}
	mco[v] = move(mco[gosc.Y]);
	maks[v] = maks[gosc.Y];
	sum[v] = sum[gosc.Y];
	mco[v][col[v]]++;
	if(mco[v][col[v]] > maks[v]){
		maks[v] = mco[v][col[v]];
		sum[v] = 0;
	}
	if(mco[v][col[v]] == maks[v]) sum[v] += col[v];
	for(auto &x: G[v]){
		if(x == p || x == gosc.Y) continue;
		for(auto &y: mco[x]){
			mco[v][y.X] += y.Y;
			if(mco[v][y.X] > maks[v]){
				maks[v] = mco[v][y.X];
				sum[v] = 0;
			}
			if(mco[v][y.X] == maks[v]) sum[v] += y.X;
		}
	}
}

void solve(){
	cin >> n;
	FOR(i, 1, n+1) cin >> col[i];
	FOR(i, 0, n-1){
		int a, b;
		cin >> a >> b;
		G[a].PB(b);
		G[b].PB(a);
	}
	dfs(1, 1);
	FOR(i, 1, n+1) cout << sum[i] << ' ';
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