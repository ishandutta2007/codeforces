//#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using ld = long double;
const int maxn = 505, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	ll a, b, c, r;
	cin >> a >> b >> c >> r;
	if(b<a) swap(a, b);
	cout << (b-a) - max(0ll, min(c+r, b) - max(c-r, a)) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
}