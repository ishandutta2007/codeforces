//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 7 * 17 * (1 << 23) + 1;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pi, null_type, less<pi>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_set; // order_of_key, find_by_order
int n, m;
vvi mat, pref, tmp, tmp2;
inline int get(const vvi &a, int x, int y, int x1, int y1) {
	--x, --y;
	x1 = min(x1, (int)a.size()-1), y1 = min(y1, (int)a[0].size()-1);
	return a[x1][y1] - (x>=0?a[x][y1]:0) - (y>=0?a[x1][y]:0) + (y>=0&&x>=0?a[x][y]:0);
}
bool can(int x) {
//	cerr << x << ":\n";
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			tmp[i][j] = tmp2[i][j] = 0;
	for(int i = x-1; i+x <= n; i++)
		for(int j = x-1; j+x <= m; j++) {
//			cout << i << " " << j << " " << (get(pref, i-x+1, j-x+1, i+x-1, j+x-1)==(2*x-1)*(2*x-1)) << "\n";
			tmp[i][j] = (get(pref, i-x+1, j-x+1, i+x-1, j+x-1)==(2*x-1)*(2*x-1));
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			tmp2[i][j] = (j?tmp2[i][j-1]:0)+(i?tmp2[i-1][j]:0)-(i&&j?tmp2[i-1][j-1]:0)+tmp[i][j];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
//			cout << tmp2[i][j] << " ";
			if(mat[i][j]!=(get(tmp2, i-x+1, j-x+1, i+x-1, j+x-1)>0)) return false;
		}
	return true;
}
void get(int x) {
//	cerr << x << ":\n";
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			tmp[i][j] = tmp2[i][j] = 0;
	for(int i = x-1; i+x <= n; i++)
		for(int j = x-1; j+x <= m; j++) {
//			cout << i << " " << j << " " << (get(pref, i-x+1, j-x+1, i+x-1, j+x-1)==(2*x-1)*(2*x-1)) << "\n";
			tmp[i][j] = (get(pref, i-x+1, j-x+1, i+x-1, j+x-1)==(2*x-1)*(2*x-1));
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			tmp2[i][j] = (j?tmp2[i][j-1]:0)+(i?tmp2[i-1][j]:0)-(i&&j?tmp2[i-1][j-1]:0)+tmp[i][j];
	for(int i = 0; i < n; i++, cout << '\n')
		for(int j = 0; j < m; j++) {
			cout << (tmp[i][j]?'X':'.');
		}
}
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	mat.resize(n, vi(m));
	pref.resize(n, vi(m));
	tmp.resize(n, vi(m));
	tmp2.resize(n, vi(m));
	char t;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			cin >> t;
			pref[i][j] = (j?pref[i][j-1]:0)+(i?pref[i-1][j]:0)-(i&&j?pref[i-1][j-1]:0)+(mat[i][j] = (t=='X'));
		}
	int ans = 0;
	for(int i = 1<<9; i; i>>=1) {
		if(can(ans+i)) ans+=i;
	}
	cout << ans-1 << "\n";
	get(ans);
}