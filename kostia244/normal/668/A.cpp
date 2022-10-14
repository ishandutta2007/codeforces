#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 105, mod = 1e9 + 7;
int n, m, q;
vector<array<int, 4>> s;
int mat[maxn][maxn];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> q;
	s.resize(q);
	for(auto &i : s) {
		cin >> i[0] >> i[1];
		if(i[0] == 3) cin >> i[2] >> i[3];
	}
	reverse(all(s));
	for(auto &[t, r, c, v] : s) {
		if(t == 3) mat[r][c] = v;
		if(t == 2) {
			t = mat[n][r];
			for(int i = n; i-1; i--) mat[i][r] = mat[i-1][r];
			mat[1][r] = t;
		}
		if(t == 1) {
			t = mat[r][m];
			for(int i = m; i-1; i--) mat[r][i] = mat[r][i-1];
			mat[r][1] = t;
		}
	}
	for(int i = 1; i <= n; i++, cout << endl)
		for(int j = 1; j <= m; j++)
			cout << mat[i][j] << " ";
}