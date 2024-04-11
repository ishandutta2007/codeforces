//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
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
const ll mod = 1e9 + 7;
char get(int a) {
	if(a<26) return 'a'+a;
	if(a<26*2) return 'A'+a-26;
	return '0'+a-2*26;
}
char c[101][101], mat[103][103];
void solve() {
	memset(c, 0, sizeof c);
	memset(mat, 0, sizeof mat);
	int n, m, x, y, k;
	cin >> n >> m >> k;
	int cnt = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> mat[i][j], cnt += mat[i][j]!='.';
	x=y=0;
	int T = cnt/k;
	int dy = 1, cc = 0, u = cnt%k, cur = 0;
	while(true) {
		if(x==n) break;
		if(cur>=k) cur = k-1;
		c[x][y] = get(cur);
		if(mat[x][y]!='.') {
			cc++;
			if(u) {
				if(cc==T+1) {
					cc = 0;
					u--;
					cur++;
				}
			} else {
				if(cc==T) {
					cc = 0;
					cur++;
				}
			}
		}
		if(dy==1&&y+1==m) {
			x++;
			dy=-1;
		} else if(dy==-1&&y==0) {
			x++;
			dy=1;
		} else
			y += dy;
	}
	for(int i = 0; i < n; i++, cout << "\n")
		for(int j = 0; j < m; j++)
			cout << c[i][j];
}
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;while(t--) solve();
}