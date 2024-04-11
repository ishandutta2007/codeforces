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

int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	vi a;
	cin >> n;
	a.resize(n);
	for(auto &i : a) cin >> i;
	multiset<ll> t;
	ll ans = 0;
	for(int i = n; i--;) {
		if(a[i] == -1) {
			break;
		}
		t.insert(a[i]);
		if(!(i&(i+1))) {
			ans += *t.begin();
			t.erase(t.begin());
		}
	}
	cout << ans;
}