#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 1e6 + 5;
int dp[maxn], sm[maxn][10];
int g(int x) {
	if(dp[x]!=-1) return dp[x];
	if(x<10) return x;
	string t= to_string(x);
	ll ans = 1;
	for(auto i : t) if(i-'0') ans*=i-'0';
	return g(ans);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof dp);
	for(int i = 1; i <= 1000000; i++) {
		for(int j = 1; j <= 10; j++) sm[i][j] = sm[i-1][j];
		sm[i][g(i)]++;
	}
	int q, l, r, x;
	cin >> q;
	while(q--) {
		cin >> l >> r >> x;
		cout << (sm[r][x] - sm[l-1][x]) << '\n';
	}
}