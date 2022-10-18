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

const int N = 2e5+5;

map<int, int> ans;
int t[N];

void solve(){
	int n, lans = INF;
	cin >> n;
	FOR(i, 0, n) cin >> t[i];
	FOR(i, 0, n) if(i == 0 || t[i] != t[i-1]) ans[t[i]]++;
	ans[t[0]]--, ans[t[n-1]]--;
	TRAV(x, ans) lans = min(lans, x.Y);
	cout << lans+1 << '\n';
	ans.clear();
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