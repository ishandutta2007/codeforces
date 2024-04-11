#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define left trigged
#define right lol
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1e6 + 1;
const ll maxa = 1e10 + 3;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int lp[maxn];
vector<int> pr;
map<vector<int>, ll> mp;
map<ll, ll> S;
vector<int> cur;
vector<pair<int, vector<int>>> ars;
void dfs(ll val, ll i, ll lst, ll prod) {
	ars.push_back({prod, cur});
	//for(auto i : cur) cout << i << " "; cout << " : " << prod << endl;
	for(ll p = 0; val < maxa && p <= lst; p++, val *= pr[i]) if(p) {
		cur.push_back(p);
		dfs(val, i+1, p, prod*(1+p));
		cur.pop_back();
	}
}

void sieve() {
	for(int i = 2; i < maxn; i++) {
		if(!lp[i]) {
			lp[i] = i;
			pr.push_back(i);
		}
		for(int j = 0; j < pr.size() && pr[j]*i < maxn && pr[j] <= lp[i]; j++)
			lp[i*pr[j]] = pr[j];
	}
}
int X, Y;
vector<int> read() {
	vector<int> p;
	int x;
	cin >> x;X = x;
	for(int t; t = lp[x];) {
		int c = 0;
		while(lp[x] == t) c++, x /= t;
		p.push_back(c);
	}
	sort(all(p));
	reverse(all(p));
	return p;
}
int dp[39][39];
int dist(const vector<int> &a, const vector<int> &b) {
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i = 0; i <= a.size(); i++) {
		for(int j = 0; j <= b.size(); j++) {
			if(i < a.size() && j < b.size()) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + abs(a[i]-b[j]));
			if(i < a.size()) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + a[i]);
			if(j < b.size()) dp[i][j+1] = min(dp[i][j+1], dp[i][j] + b[j]);
		}
	}
	return dp[a.size()][b.size()];
}
int C;
vector<int> vals[4000];
void comp(vector<int> &pa, vector<int> &a) {
	pa.reserve(C);
	for(int i = 0; i < C; i++) pa.push_back(dist(ars[i].second, a));
	for(int i = C; i--;) if(i+1 != C && ars[i].first == ars[i+1].first) pa[i] = min(pa[i], pa[i+1]);
}
int ord(vector<int> a) {
	int prod = 1;
	for(auto &i : a) prod *= i+1;
	auto it = lower_bound(all(ars), pair<int, vector<int>>{prod, a});
	assert(it != ars.end());
	return it-ars.begin();
}
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	sieve();
	dfs(1, 0, 30, 1);
	int t;
	cin >> t;
	sort(all(ars));
	C = ars.size();
	for(int i = 0; i < ars.size(); i++) comp(vals[i], ars[i].second);
	int no = 0;
	while(t--) {
		auto x = read();
		swap(X, Y);
		auto y = read();
		int a = ord(x), b = ord(y), ans = 100;
		for(int i = 0; i < C; i++) ans = min(ans, vals[a][i] + vals[b][i]);
		//for(auto &i : x) cout << i << " ";cout<<endl;
		//for(auto &i :y) cout << i << " ";cout<<endl;
		cout << ans << '\n';
	}
}