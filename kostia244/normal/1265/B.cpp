//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 7*17*(1<<23) + 1;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	vi mn, mx, a;
	int n;
	cin >> n;
	a.resize(n);
	mn.resize(n);
	mx.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i], a[i]--;
		mn[a[i]] = mx[a[i]] = i;
	}
	for(int i = 1; i < n; i++) {
		mn[i] = min(mn[i], mn[i-1]);
		mx[i] = max(mx[i], mx[i-1]);
	}
	for(int i = 0; i < n; i++) {
		cout << (mx[i]-mn[i]==i);
	}
	cout << "\n";
}
int main() { //DINIC ORZ, FFT ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}