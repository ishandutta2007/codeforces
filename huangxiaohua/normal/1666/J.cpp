#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
template <typename T> bool chkmin (T &x, T y) {return y < x ? x = y, 1 : 0;}
template <typename T> bool chkmax (T &x, T y) {return y > x ? x = y, 1 : 0;}

const int N = 1e3 + 5;

int n;
int c[N][N];

ll pre[N][N];
ll query (ll l1, ll l2, ll r1, ll r2) {return pre[l2][r2] - pre[l2][r1 - 1] - pre[l1 - 1][r2] + pre[l1 - 1][r1 - 1];}

ll dp[N][N];
int pos[N][N];
int ans[N];
void solve (int u, int l, int r) {
	if (l > r) return;
	// cout << u << ' ' << l << ' ' << r << endl;
	ans[pos[l][r]] = u;
	solve(pos[l][r], l, pos[l][r] - 1);
	solve(pos[l][r], pos[l][r] + 1, r);
}

int main () {
	cin >> n;
	for (int i = 1;i <= n;++i) {
		for (int j = 1;j <= n;++j) {
			cin >> c[i][j];
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + c[i][j];
		}
	}
	
	memset(dp, 0x3f, sizeof dp);
	for (int i = 1;i <= n + 1;++i) {
		dp[i][i] = 0;
		dp[i][i - 1] = 0;
		pos[i][i] = i;
	}
	for (int len = 2;len <= n;++len) {
		for (int l = 1;l + len - 1 <= n;++l) {
			int r = l + len - 1;
			for (int k = l;k <= r;++k) {
				ll cur = dp[l][k - 1] + dp[k + 1][r];
				cur += query(l, k - 1, 1, n) - query(l, k - 1, l, k - 1);
				cur += query(k + 1, r, 1, n) - query(k + 1, r, k + 1, r);
				if (chkmin(dp[l][r], cur)) pos[l][r] = k;
			}
			// cout << l << ' ' << r << ':' << pos[l][r] << ' ' << dp[l][r] << endl;
		}
	}
	
	solve(0, 1, n);
	for (int i = 1;i <= n;++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}