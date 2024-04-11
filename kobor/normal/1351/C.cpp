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

map<pair<ii, ii>, int> m;

void solve(){
	ii akt = {0, 0}, nowy;
	string s;
	cin >> s;
	TRAV(x, s){
		nowy = akt;
		if(x == 'N') nowy.X++;
		if(x == 'S') nowy.X--;
		if(x == 'W') nowy.Y++;
		if(x == 'E') nowy.Y--;
		m[{min(akt, nowy), max(akt, nowy)}]++;
		akt = nowy;
	}
	int ans = 0;
	TRAV(x, m) ans += x.Y + 4;
	cout << ans << '\n';
	m.clear();
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