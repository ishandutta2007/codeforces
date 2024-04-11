#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
#define int long long
using namespace std;
using ll = int64_t;
const int maxn = 330, mod = 1000000007;
char mat[maxn][maxn];
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n; m = n;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> mat[i][j], mat[i][j] -= '0';
		vector<array<int, 2>> ops;
		if(mat[1][0] == mat[0][1]) {
			if(mat[n-1][m-2] == mat[1][0]) ops.push_back({n, m-1});
			if(mat[n-2][m-1] == mat[1][0]) ops.push_back({n-1, m});
		} else if(mat[n-1][m-2] == mat[n-2][m-1]) {
			if(mat[n-1][m-2] == mat[1][0]) ops.push_back({2, 1});
			if(mat[n-1][m-2] == mat[0][1]) ops.push_back({1, 2});
		} else {
			mat[0][1] ^= 1;
			ops.push_back({1, 2});
			if(mat[n-1][m-2] == mat[1][0]) ops.push_back({n, m-1});
			if(mat[n-2][m-1] == mat[1][0]) ops.push_back({n-1, m});
		}
		cout << ops.size() << '\n';
		for(auto &i : ops) cout << i[0] << " " << i[1] << '\n';
	}
}