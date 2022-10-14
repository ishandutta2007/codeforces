#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 1e9 + 7;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, s[200200], g[200200], a[200200], suf[200200], pref[200200];

int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s[i] >> g[i];
		a[i] = s[i] + g[i];
	}
	pref[1] = a[1];
	for(int i = 2; i <= n; i++)
		pref[i] = min(pref[i-1]+1, a[i]);
	suf[n] = a[n];
	for(int i = n; i-->1;)
		suf[i] = min(suf[i+1]+1, a[i]);
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		pref[i] = min(pref[i], suf[i]);
		if(s[i]>pref[i]) return cout << -1, 0;
		ans += pref[i]-s[i];
	}
	cout << ans << "\n";
	for(int i = 1; i <= n; i++) cout << pref[i] << " ";
}