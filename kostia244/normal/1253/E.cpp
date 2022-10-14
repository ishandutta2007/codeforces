//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;

ll n, m, dp[100100];
vector<pair<ll, ll>> a;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	a.resize(n);
	for(auto &i : a) {
		cin >> i.first >> i.second;
	}
	sort(all(a));
	for(int i = 1; i <= m; i++) dp[i] = 2e6;
	for(auto seg : a) {
		for(int i = 0; i <= m; i++) {
			dp[min(m, seg.first+i)] = min(dp[min(m, seg.first+i)], dp[max(seg.first-i-1, 0ll)]+max(0ll, i-seg.second));
		}
		for(int i = m; i--;)
			dp[i] = min(dp[i], dp[i+1]);
	}
	cout << dp[m];
}