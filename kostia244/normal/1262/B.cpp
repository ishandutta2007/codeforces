//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
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
const ll mod = 7 * 17 * (1 << 23) + 1;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	int n;
	cin >> n;
	vi a, b;
	a.resize(n);
	b.resize(n);
	set<int> c;
	for(int i = 1; i <= n; i++)
		c.insert(i);
	for(auto &i : a){
		cin >> i;
		if(c.count(i)) c.erase(i);
	}
	b[0] = a[0];
	for(int i = 1; i < n; i++) {
		if(a[i]!=a[i-1]) {
			b[i] = a[i];
		} else {
			b[i] = *c.begin();
			if(b[i]>a[i]) {cout << "-1\n"; return;};
			c.erase(c.begin());
		}
	}
	for(auto i : b) cout << i << " ";
	cout << "\n";
}
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}