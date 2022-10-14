//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("trapv")
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
const int mod = 1e9 + 7;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	ll c, s;
	cin >> c >> s;
	ll u = s/c;
	ll v = s%c;
	c -= v;
	ll a = u*u*c + v*(u+1)*(u+1);
			cout << a << "\n";

}
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	while(n--) solve();
}