#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
#define int long long
using namespace std;
using ll = int64_t;
const int maxn = 303, mod = 1000000007;
int n, m, a[maxn][maxn], b[maxn][maxn], v[maxn*maxn];
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	for(int i = 0; i < n; i++) {
		int x = 0;
		for(int j = 0; j < m; j++) x = max(x, a[i][j]);
		v[x] += 1;
	}
	for(int j = 0; j < m; j++) {
		int x = 0;
		for(int i = 0; i < n; i++) x = max(x, a[i][j]);
		v[x] += 2;
	}
	int x = 0, y = 0, fix = 0, fiy = 0;
	for(int i = n*m; i; i--) {
		if(v[i]) {
			if(v[i]&1) if(fix++) x++;
			if(v[i]&2)
				if(fiy++)y++;
			b[x][y] = i;
		} else {
			int ok = 0;
			for(int p = 0; !ok && p <= x; p++) {
				if(b[p][0]) continue;
				ok = 1;
				int t = 0;
				while(!b[p][t+1]) t++;
				b[p][t] = i;
				break;
			}
			for(int p = 0; !ok && p <= y; p++) {
				if(b[0][p]) continue;
				ok = 1;
				int t = 0;
				while(!b[t+1][p]) t++;
				b[t][p] = i;
				break;
			} 
		}
		//cout << i << " " << x << " " << y << " " << b[x][y] << endl;
	}
	
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) a[i][j] = b[i][j];
	for(int i = 0; i < n; i++, cout << '\n')
		for(int j = 0; j < m; j++)
			cout << b[i][j] << ' ';
}