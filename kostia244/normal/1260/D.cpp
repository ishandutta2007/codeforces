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
int n, m, k, t;
int op[200200], cl[200200];
vi a;
vector<pair<int, int>> z[200200];
bool can(int x) {
	memset(cl, 0, sizeof cl);
	memset(op,0,sizeof op);
	int u = n+1, l = 0;
	for(int i = x; i <= 200000; i++) {
		for(auto j : z[i]) {
			op[j.first]++;
			cl[j.second]++;
		}
	}
	int c = 0;
	for(int i = 1; i <= n+1; i++) {
		c += op[i];
//		cout << i << " > " << c << " : ";
		if(c) l++;
		else {
			u += 2*l;
			l=0;
		}
		c -= cl[i];
	}
//	cout << x << " " << u << "\n";
	return u<=t;
}
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n >> k >> t;
	a.resize(m);
	for(auto &i :a) cin >> i;
	int l, r, d;
	while(k--) {
		cin >> l >> r >> d;
		z[d].pb({l, r});
	}
	ll ans = 0;
	for(int i = 1<<17; i; i>>=1)
		if(ans+i<200001&&!can(ans+i)) ans += i;
	ll cnt= 0;
	for(auto i : a) if(i>=ans) cnt++;
	cout << cnt;
}