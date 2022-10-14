#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 402, mod = 998244353 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
string x[maxn][maxn], y[maxn][maxn];
vector<array<int, 4>> compress(string mt[][maxn]) {
	vector<array<int, 4>> q;
	for(auto [x, y] : {pi{1, 1}, pi{n, m}}) {
		for(auto c : mt[x][y]) {
			q.pb({x, y, 1, m});
			mt[1][m].pb(c);
		}
		mt[x][y].clear();
	}
	for(int _ = 0; _ < 2; _++)
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			if(i == 1 && j == 1) continue;
			if(i == n && j == m) continue;
			for(auto c : mt[i][j]) {
				if(c == '0') {
					if(j == 1) {
						q.pb({i, j, 1, 1});
						mt[1][1].pb(c);
					} else {
						q.pb({i, j, i, 1});
						mt[i][1].pb(c);
					}
				} else {
					if(j == m) {
						q.pb({i, j, n, m});
						mt[n][m].pb(c);
					} else {
						q.pb({i, j, i, m});
						mt[i][m].pb(c);
					}
				}
			}
			mt[i][j].clear();
		}
	return q;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			cin >> x[i][j];
			reverse(all(x[i][j]));
		}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> y[i][j];
	vector<array<int, 4>> a = compress(x), b = compress(y);
	reverse(all(b));
	cout << a.size()+b.size() << '\n';
	for(auto i : a) 
		cout << i[0] << " " << i[1] << " " << i[2] << " " << i[3] << '\n';
	for(auto i : b) 
		cout << i[2] << " " << i[3] << " " << i[0] << " " << i[1] << '\n';
	return 0;
}