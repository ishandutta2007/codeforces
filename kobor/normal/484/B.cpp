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
	vi vec(n);
	TRAV(x, vec) cin >> x;
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	int ans = 0;
	TRAV(x, vec){
		int akt = x*2;
		while(akt < vec.back()*2){
			int ind = lower_bound(vec.begin(), vec.end(), akt) - vec.begin() - 1;
			if(ind >= 0) ans = max(ans, vec[ind] % x);
			akt += x;
		}
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