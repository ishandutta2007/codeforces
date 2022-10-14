#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<10;
struct solver {
	int n, m, nxt[maxn][maxn];
	vector<vector<int>> B;
	solver(int n, int m, vector<vector<int>> B) : n(n), m(m), B(B) {
		for(int i = 0; i < n; i++)
			for(int j = m; j--;) {
				if(!B[i][j]) nxt[i][j] = j;
				else if(j+1 == m) nxt[i][j] = m;
				else nxt[i][j] = nxt[i][j+1];
			}
	}
	void block(int x, int y) {
		B[x][y] ^= 1;
		for(int i = y+1; i--;) {
			if(!B[x][i]) nxt[x][i] = i;
			else if(i+1 == m) nxt[x][i] = m;
			else nxt[x][i] = nxt[x][i+1];
		}
	}
	int query(int i, int j) {
		int Lx, Rx; Lx = Rx = i;
		int ans, cur;ans = cur = nxt[i][j]-j;
		while(Lx || Rx+1 < n) {
			if(!Lx || (Rx+1<n && nxt[Rx+1][j] > nxt[Lx-1][j])) {
				++Rx;
				cur = min(cur, nxt[Rx][j]-j);
			} else {
				--Lx;
				cur = min(cur, nxt[Lx][j]-j);
			}
			ans = max(ans, cur*(Rx-Lx+1));
		}
		return ans;
	}
};
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> a(n, vector<int>(m)),
						b(n, vector<int>(m)),
						c(m, vector<int>(n)),
						d(m, vector<int>(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int t;
			cin >> t;
			a[i][j] = b[i][m-1-j] = c[j][i] = d[j][n-1-i] = t;
		}
	}
	solver A(n, m, a), B(n, m, b), C(m, n, c), D(m, n, d);
	for(int t, x, y; q--;) {
		cin >> t >> x >> y;--x,--y;
		if(t == 1) {
			A.block(x, y);
			B.block(x, m-1-y);
			C.block(y, x);
			D.block(y, n-1-x);
		} else {
			cout << max({A.query(x, y), B.query(x, m-1-y), C.query(y, x), D.query(y, n-1-x)}) << '\n';
		}
	}
	return 0;
}