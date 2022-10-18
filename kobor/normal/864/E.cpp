#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF=0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < e; i++)
#define TRAV(x, a) for(auto &x: a)
#define SZ(x) ((int)(x).size())
#define PB push_back
#define PR pair
#define MP make_pair
#define X first
#define Y second

const int T = 2020;
const int N = 105;

int dp[N][T], bt[N][T], btwh[N][T];
vector<PR<ii, ii>> item; // {{burn_time, id} {time, value}}

void solve(){
	int n;
	cin >> n;
	FOR(i, 0, n){
		int t, d, p;
		cin >> t >> d >> p;
		item.PB({{d, i+1}, {t, p}});
	}
	sort(item.begin(), item.end());
	FOR(j, 1, SZ(item)+1){
		auto x = item[j-1];
		FOR(i, 0, T) dp[j][i] = dp[j-1][i], bt[j][i] = 0, btwh[j][i] = i;
		FOR(i, x.Y.X, x.X.X){
			if(dp[j-1][i-x.Y.X] + x.Y.Y > dp[j][i]){
				dp[j][i] = dp[j-1][i-x.Y.X] + x.Y.Y;
				bt[j][i] = x.X.Y;
				btwh[j][i] = i-x.Y.X;
			}
		}
	}
	vi ans;
	ii best;
	FOR(i, 0, T) best = max(best, {dp[SZ(item)][i], i});
	for(int j = SZ(item); j > 0; j--){
		if(bt[j][best.Y]) ans.PB(bt[j][best.Y]);
		best.Y = btwh[j][best.Y];
	}
	cout << best.X << '\n';
	cout << SZ(ans) << '\n';
	reverse(ans.begin(), ans.end());
	TRAV(x, ans) cout << x << ' ';
	cout << '\n';
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