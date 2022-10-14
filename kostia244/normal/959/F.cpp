//#pragma GCC optimize("trapv")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 2e5 + 55, mod = 1e9 + 7 , i2 = (mod+1)/2;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
vpi q[maxn];
vi basis;
void insert(int i) {
	for(auto j : basis) i = min(i, i^j);
	if(i) basis.pb(i);
}
bool check(int i) {
	for(auto j : basis) i = min(i, i^j);
	return i==0;
}
int pw[maxn], ipw[maxn], ans[maxn], a[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	pw[0] = ipw[0] = 1;
	for(int i = 1; i < maxn; i++) {
		pw[i] = (pw[i-1]<<1)%mod;
		ipw[i] = (ipw[i-1]*1ll*i2)%mod;
	}
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int l, x, i = 0; i < m; i++) {
		cin >> l >> x;
		q[l].pb({x, i});
	}
	for(int i = 1; i <= n; i++) {
		insert(a[i]);
		int x = pw[i]*1ll*ipw[basis.size()]%mod;
		//cout<< i << " " << basis.size() << " " << x << '\n';
		for(auto j : q[i]) {
			if(check(j.first)) {
				ans[j.second] = x;
			}
		}
	}
	for(int i = 0; i < m; i++) cout << ans[i] << '\n';
}