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

int n;
vi vec;

int solve(int l, int r){
	int ret = r-l+1, mink = INF, last = -1;
	FOR(i, l, r+1) mink = min(mink, vec[i]);
	FOR(i, l, r+1) vec[i] -= mink;
	int lans = mink;
	FOR(i, l, r+2){
		if(i == r+1 || vec[i] == 0){
			if(last != -1) lans += solve(last, i-1);
			last = -1;
		}
		else if(last == -1) last = i;
	}
	return min(ret, lans);
}

void solve(){
	cin >> n;
	vec.resize(n);
	TRAV(x, vec) cin >> x;
	cout << solve(0, n-1) << '\n';
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