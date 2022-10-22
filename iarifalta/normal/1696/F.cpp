#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define pill pair<ll, ll>
#define s second
#define ld long double
using namespace std;

const ll N = 1e2 + 10;
const ll mod = 998244353;
const ll big = 1e4;
const double eps = 1e-8;

ll t, n;
bool x[N][N][N];
bool was[N];
bool was2[N][N];
vector<pair<int, int>> g;
vector<int> G[N];

int dp[N];

bool solve(int a, int b) {
	for(int i = 1; i <= n; i++)
		was[i] = 0, G[i].clear();
	g.clear();
	queue<pair<int, int>> q;
	q.push(mp(a, b));
	was[a] = was[b] = 1;
	while(q.size()) {
		ll v = q.front().f;
		ll u = q.front().s;
		g.pb(mp(v, u));
		G[v].pb(u);
		G[u].pb(v);
		q.pop();
		for(int k = 1; k <= n; k++) {
			if(x[v][k][u]) {
				if(was[k])return 0;
				was[k] = 1;
				q.push(mp(u, k));
			}
		}
	}
	for(int i = 1; i <= n; i++)
		if(!was[i]) {
			return 0;
		}
	for(int i = 1; i <= n; i++) {
		queue<int> qq;
		qq.push(i);
		for(int j = 1; j <= n; j++)
			dp[j] = 0;
		while(qq.size()) {
			ll v = qq.front();
			qq.pop();
			for(auto u : G[v]) {
				if(u != i && dp[u] == 0) {
					dp[u] = dp[v] + 1;
					qq.push(u);
				}
			}
		}
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
			    //if(j == k || j == i || i == k)continue;
			    if(j == k)continue;
				if(x[j][k][i] == 1 && dp[j] != dp[k])return 0;
				if(x[j][k][i] == 0 && dp[j] == dp[k])return 0;
			}
		}
	}
	return 1;	
}

int main() {
	speed;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++) {
			    was2[i][j] = 0;
				for(int k = 1; k <= n; k++)
					x[i][j][k] = 0;
			}
		for(int i = 1; i <= n; i++)
			was[i] = 0, G[i].clear();
		g.clear();		
		for(int i = 1; i <= n; i++) {
			string a;
			for(int j = 1; j <= n - i; j++) {
				cin >> a;
				for(int k = 0; k < n; k++) {
					x[i][i + j][k + 1] = (a[k] == '1');
					x[i + j][i][k + 1] = (a[k] == '1');
				}
			}
		}
		bool ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == j)continue;
				if(solve(i, j)) {
					ans = 1;
					break;
				}
				for(auto u : g) {
					was2[u.f][u.s] = 1,
					was2[u.s][u.f] = 1;
				}
			}
			if(ans)break;
		}
		if(ans) {
			cout << "Yes\n";
			for(auto u : g)
				cout << u.f << " " << u.s << '\n';		
		} else {
			cout << "No\n";
		}
	}

}
/*
3
1 0
3 0
5 0

*/