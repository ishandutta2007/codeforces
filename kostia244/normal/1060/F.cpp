#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
const int maxn = 55;
using ll = long long;
using ld = long double;
using DP = array<ld, maxn>;
int n;
ll C[maxn][maxn];
vector<int> g[maxn];
int sz[maxn];
ld factorial(int x) {
	ld r = 1;
	for(int i = 1; i <= x; i++) r *= i;
	return r;
}
ld mrg(int a, int b) {return C[a+b][a];}
ld mrg(int a, int b, int c, int d) {
	return C[a+b][a]*C[c+d][d]/(ld)C[a+b+c+d][a+c];
}
DP dfs(int v, int p) {
	DP dp {};
	sz[v] = 1;
	dp[0] = 1;
	for(auto &i : g[v]) if(i != p) {
		auto ch = dfs(i, v);
		DP ndp {};
		//for(int i = 1; i < n; i++) ch[i] += ch[i-1];
		for(int p1 = 0; p1 < sz[v]; p1++)
			for(int q = 0; q <= sz[i]; q++) {
					for(int p2 = 0; p2 < sz[i]; p2++) {
						ld t = dp[p1]*ch[min(q, p2)];
						t *= mrg(p1, q);
						t /= mrg(sz[v]-1, sz[i]);
						t *= mrg(sz[v]-1 - p1, sz[i] - q);
						t /= sz[i];
						//t *= mrg(p1, q, sz[v]-1 - p1, sz[i] - q);
						if(p2 < q) t /= 2;
						//if(t > 1e-5)
						//cout << p1 << " " << q << " " << p2 << " " << t << " | " << t << " " << ch[q - (p2 < q)] << '\n';
						ndp[p1+q] += t;
					}
				}
		sz[v] += sz[i];
		dp = ndp;
		//cout << v << " : ";
		//for(int i = 0; i < sz[v]; i++) cout << dp[i] << " "; cout << '\n';
	}
	return dp;
}
ld solve(int v) {
	memset(sz, 0, sizeof sz);
	auto dp = dfs(v, v);
	return dp[n-1];
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j <= i; j++) {
			if(j) C[i][j] = C[i-1][j-1] + C[i-1][j];
			else C[i][j] = 1;
		}
	cin >> n;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	cout << fixed << setprecision(7);
	vector<ld> res;
	for(int i = 1; i <= n; i++) res.push_back(solve(i));
	ld sm = 1;
	//for(auto &i : res) sm += i;
	for(auto &i : res) cout << i/sm << '\n';
}