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


void solve(){
	int n;
	cin >> n;
	vi vec(n/2+1), vec2(n/2);
	FOR(i, 0, n){
		if(i % 2 == 0) cin >> vec[i/2];
		else cin >> vec2[i/2];
	}
	TRAV(x, vec2) vec.PB(x);
	FOR(i, 0, n) vec.PB(vec[i]);
	ll akt = 0, ans = 0;
	FOR(i, 0, n*2){
		akt += vec[i];
		ans = max(ans, akt);
		if(i-(n+1)/2+1 >= 0) akt -= vec[i-(n+1)/2+1];
	}
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