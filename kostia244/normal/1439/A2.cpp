#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4.1,sse4.2,popcnt")
#include<bits/extc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 111, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int t;
char a[maxn][maxn];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> a[i][j], a[i][j] -= '0';
		vector<vector<array<int, 2>>> ops;
		auto apply = [&](int x, int y, int A, int B) {
			vector<array<int, 2>> op;
			for(int i = 0; i < 2; i++)
				for(int j = 0; j < 2; j++)
					if(x+i != A|| y+j != B) op.push_back({x+i, y+j}), a[x+i][y+j] ^= 1;
			ops.push_back(op);
		};
		int ON = n, OM = m;
		if(n&1) {
			for(int j = 1; j <= m; j++) {
				if(a[n][j]) {
					apply(n-1, j - (j==m), n, j == m ? j-1 : j+1);
				}
			}
			n--;
		}
		if(m&1) {
			for(int i = 1; i <= n; i++) {
				if(a[i][m]) {
					apply(i - (i==n), m-1, i == n ? i-1 : i+1, m);
				}
			}
			m--;
		}
		for(int i = 1; i <= n; i+=2)
			for(int j = 1; j <= m; j+=2) {
				int msk = 0;
				for(int x = 0; x < 2; x++)
					for(int y = 0; y < 2; y++) if(a[i+x][j+y]) {
						msk ^= 15;
						msk ^= 1<<(x+2*y);
					}
				for(int x = 0; x < 2; x++)
					for(int y = 0; y < 2; y++) if(msk & (1<<(x+2*y))) {
						apply(i, j, i+x, j+y);
					}
			}
		
		//for(int i = 1; i <= ON; i++, cout << endl)
		//	for(int j = 1; j <= OM; j++) 
		//		cout << char('0'+a[i][j]);
		for(int i = 1; i <= ON; i++)
			for(int j = 1; j <= OM; j++) assert(a[i][j] == 0);
		assert(ops.size() <= ON*OM);
		cout << ops.size() << '\n';
		for(auto i : ops) {
			for(auto [x, y] : i) cout << x << " " << y << " ";
			cout << '\n';
		}
	}
}