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
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vi a, s;
	a.resize(n);
	s.resize(n);
	for(auto &i : a) cin >> i;
	sort(all(a));
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		s[i%m]+=a[i];
		ans += s[i%m];
		cout << ans << " ";
	}
}