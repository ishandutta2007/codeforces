#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 220, mod = 1e9 + 7;
int to[maxn][20], link[maxn], term[maxn], sz = 1;
struct aho {
	void add(vector<int> s, int v) {
		int cur = 0;
		for(auto c : s) {
			if(!to[cur][c]) to[cur][c] = sz++;
			cur = to[cur][c];
		}
		term[cur] += v;
	}
	void push_links() {
		int q[maxn], s = 0, e = 0;
		q[e++] = 0;
		while(s < e) {
			int V = q[s++];
			int U = link[V];
			term[V] += term[U];
			for(int i = 0; i < 20; i++) {
				if(!to[V][i]) {
					to[V][i] = to[U][i];
				} else {
					q[e++] = to[V][i];
					link[to[V][i]] = V ? to[U][i] : 0;
				}
			}
		}
	}
};
int n, m, k;
aho ra;
void add(int &a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}
vector<int> l, r;
int dp[2][202][501][2][2];
int solve(vector<int> mx) {
	int L = mx.size();
	memset(dp[0], 0, sizeof dp[0]);
	dp[0][0][0][0][0] = 1;
	int ans = 0;
	for(int i = 0; i < L; i++) {
		int nxt = (i&1)^1;
		memset(dp[nxt], 0, sizeof dp[nxt]);
		for(int cur = 0; cur < sz; cur++) {
			for(int val = 0; val <= k; val++) {
				for(int flg = 0; flg < 2; flg++) {
					for(int lst = 0; lst < 2; lst++) {
						if(!dp[i&1][cur][val][flg][lst]) continue;
						//cout << i << " " << cur << " " << val << " " << flg << " " << lst << " - " << dp[i&1][cur][val][flg][lst] << " " << mx[i] << endl;
						for(int d = 0; d < m; d++) {
							int ncur = to[cur][d];
							int nval = val + term[ncur];
							int nflg = mx[i] == d ? flg : (d > mx[i]);
							if(nval <= k)
								add(dp[nxt][ncur][nval][nflg][d>0], dp[i&1][cur][val][flg][lst]);
						}
					}
				}
			}
		}
		for(int cur = 0; cur < sz; cur++)
			for(int val = 0; val <= k; val++) {
				//if(dp[nxt][cur][val][0][1]) {
				//	cout << nxt << " " << cur << " " << val << " " << dp[nxt][cur][val][0][1] << endl;}
				add(ans, dp[nxt][cur][val][0][1]);
				if(i+1 != L) {
					//if(dp[nxt][cur][val][1][1]) {
					//	cout << nxt << " " << cur << " " << val << " " << dp[nxt][cur][val][1][1] << endl;}
					add(ans, dp[nxt][cur][val][1][1]);
				}
			}	
		//cout << ans << '\n';
	}
	//cout << dp[L&1][
	return ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> k;
	{
		int t;
		cin >> t;
		l.resize(t);
		for(auto &i : l) cin >> i;reverse(all(l));
		cin >> t;
		r.resize(t);
		for(auto &i : r) cin >> i;reverse(all(r));
	}
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		vector<int> a(t);
		for(auto &i : a) cin >> i;
		reverse(all(a));
		cin >> t;
		ra.add(a, t);
	}
	ra.push_links();
	for(int carry = 1, i = 0; carry; i++) {
		if(l[i]-- == 0) l[i] = m-1;
		else carry = 0;
	}
	cout << (solve(r) - solve(l) + mod)%mod << '\n';
}