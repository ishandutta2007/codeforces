#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/STACK:26777216")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1e9 + 7;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	ll a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;
	ll x = (c+a-1)/c;
	ll y = (d+b-1)/d;
	if(x+y > k)
		cout << "-1\n";
	else
		cout << x << " " << y << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
}