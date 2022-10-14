//#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 3e5 + 33, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, k;
vector<array<int, 2>> add[maxn], rem[maxn];
array<int, 2> ANS[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int s, t, d, w, i = 0; i < k; i++) {
		cin >> s >> t >> d >> w;
		add[s].push_back({w, d});
		rem[t].push_back({w, d});
	}
	multiset<array<int, 2>> cur;
	array<ll, maxn> B, dp, ndp;
	fill(all(B), 1ll<<60);
	dp = ndp = B;
	dp[1] = 0;
	for(int i = 1; i <= n; i++) {
		for(auto x : add[i])
			cur.insert(x);
		ANS[i] = cur.empty()?array<int, 2>{-1, -1}:*cur.rbegin();
		for(auto x : rem[i])
			cur.erase(cur.find(x));
	}
	ll r = 1ll<<60;
	for(int d = 0; d <= m; d++) {
	for(int i = 1; i <= n; i++) {
		if(ANS[i][0] == -1) {
			dp[i+1] = min(dp[i+1], dp[i]);
		} else {
			ndp[i+1] = min(ndp[i+1], dp[i]);
			auto t = ANS[i];
			dp[t[1]+1] = min(dp[t[1]+1], dp[i] + t[0]);
			//cout << t[1]+1 << " " << d << endl;
		}
		//cout << dp[i] << " ";
	}
	//cout << '\n';
	r = min(r, dp[n+1]);
	dp = ndp;
	}
	cout << r;
}