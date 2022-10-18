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

bool check(vi zioms, int ile){
	FOR(i, 0, ile) if(i > zioms[SZ(zioms)-i-1]-1) return 0;
	return 1;
}

void solve(){
	int n, m;
	cin >> n >> m;
	vi zioms(n), prez(m);
	TRAV(x, zioms) cin >> x;
	TRAV(x, prez) cin >> x;
	sort(zioms.begin(), zioms.end());
	int l = 0, r = min(n+1, m+1), mid;
	while(l+1 < r){
		mid = (l+r)/2;
		if(check(zioms, mid)) l = mid;
		else r = mid;
	}
	ll ans = INF, lans = 0;
	TRAV(x, zioms) lans += prez[x-1];
	ans = lans;
	for(int i = n-1; i >= n-l; i--){
		lans -= prez[zioms[i]-1];
		lans += prez[n-1 - i];
		ans = min(ans, lans);
	}
	cout << ans << '\n';
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