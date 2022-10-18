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
	string s;
	bool odd = 0, even = 0;
	cin >> n >> s;
	FOR(i, 0, n){
		if(i%2 == 0 && s[i]%2 == 1) odd = 1;
		if(i%2 == 1 && s[i]%2 == 0) even = 1;
	}
	if(n%2 == 1) cout << (odd ? 1 : 2) << '\n';
	else cout << (even ? 2 : 1) << '\n';
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