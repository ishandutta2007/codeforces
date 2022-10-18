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
	int t[4];
	FOR(i, 0, 4) cin >> t[i];
	sort(t, t+4);
	if(t[0] + t[1] > t[2] || t[1] + t[2] > t[3]) cout << "TRIANGLE\n";
	else if(t[0] + t[1] == t[2] || t[1] + t[2] == t[3]) cout << "SEGMENT\n";
	else cout << "IMPOSSIBLE\n";
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