#define SolutionToA 8bd96cf2dcad0ec7e9afce582c4bd1390179f4dec00841d13edc4420ce7de42b
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 1e3 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, p[1<<18], dp[1<<18], din[20], dout[20], mskin[1<<18], mskout[1<<18], win[20], wout[20], in[1<<18], out[1<<18];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m;
    cin >> n >> m;
    for(int x, y, w, i = 0; i < m; i++) {
		cin >> x >> y >> w;x--, y--;
		dout[y] |= 1<<x;
		din[x] |= 1<<y;
		win[x] += w;
		wout[y] += w;
	}
	for(int i = 0; i < 1<<n; i++)
		for(int j = 0; j < n; j++) if((i>>j)&1) {
			mskin[i] |= din[j];
			mskout[i] |= dout[j];
			out[i] += wout[j];
			in[i] += win[j];
		}
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	for(int i = 0; i < 1<<n; i++) {
		int inv = (1<<n)-1-i;
		for(int j = inv; j; j = (j-1)&inv) {
			if(mskout[j]&(i|j)) continue;
			if((mskin[j]&i) != mskin[j]) continue;
			//cout << i << " " << j << " " << mskin[j] << endl;
			dp[i|j] = min(dp[i|j], dp[i] + out[i] - in[i]);
			if(dp[i|j] == dp[i] + out[i] - in[i]) p[i|j] = j;
		}
	}
	cerr << dp[(1<<n)-1] << '\n';
	int msk = 1<<n;msk--;
	vector<int> col(n);
	int a = 69;
	while(msk) {
		for(int j = 0; j < n; j++) if((p[msk]>>j)&1) col[j] = a;
		msk -= p[msk];
		a--;
	}
	for(auto i : col) cout << i << " "; cout << '\n';
}