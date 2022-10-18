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
#define X first
#define Y second

const int M = 5e6 + 5;
const int N = 2e5+5;

int n;
vector<ii> parki[M];
int t[N];

void solve(){
	cin >> n;
	FOR(i, 0, n) cin >> t[i];
	FOR(i, 0, n) FOR(j, 0, i){
		int sum = t[i]+t[j];
		ii par = {i, j};
		TRAV(x, parki[sum]) if(x.X != par.X && x.X != par.Y && x.Y != par.X && x.Y != par.Y){
			cout << "YES\n";
			cout << x.X + 1 << ' ' << x.Y + 1 << ' ' << par.X + 1 << ' ' << par.Y + 1 << '\n';
			return;
		}
		parki[sum].PB(par);
	}
	cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	// int tt; cin >> tt;
	// FOR(te, 0, tt){
	// 	// cout << "Case #" << te+1 << ": ";
	// 	solve();
	// }
	solve();
	return 0;
}