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
#define X first
#define Y second

map<int, vi> xd;

void solve(){
	int n, a;
	xd.clear();
	cin >> n;
	FOR(i, 0, n){
		cin >> a;
		xd[a].PB(i);
	}
	TRAV(x, xd){
		if(SZ(x.Y) == 1){
			cout << x.Y.front()+1 << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	FOR(te, 0, tt){
		// cout << "Case #" << te+1 << ": ";
		solve();
	}
	// solve();
	return 0;
}