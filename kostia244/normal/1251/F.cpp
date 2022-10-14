//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 7*17*(1<<23) + 1;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int w = 390359979, iw = 304321983, i2 = 499122177, maxn = 1<<20;
int _w[maxn+1], _iw[maxn+1];
void pre() {
	_w[maxn] = w, _iw[maxn] = iw;
	for(int i = maxn; i>>=1;){
		_w[i] = (_w[i<<1] * 1ll * _w[i<<1])%mod;
		_iw[i] = (_iw[i<<1] * 1ll * _iw[i<<1])%mod;
	}
}
void ntt(vi &a, vi &res, int l, int cl, int n, int step, bool inv) {
	if(n == 1) {
		res[l] = a[cl];
		return;
	}
	ntt(a, res, l, cl, n>>1, step<<1, inv);
	ntt(a, res, l + (n>>1), cl + step, n>>1, step<<1, inv);
	int cw = 1, gw = inv?_iw[n]:_w[n];
	for(int i = l; i < l + (n>>1); i++) {
		int u = res[i], v = (cw * 1ll * res[i + (n>>1)])%mod;
		res[i] = (u+v);
		if(res[i] >= mod) res[i] -= mod;
		res[i+(n>>1)] = u-v;
		if(res[i+(n>>1)]<0) res[i+(n>>1)]+=mod;
		if(inv) {
			res[i] = (res[i] * 1ll * i2)%mod;
			res[i + (n>>1)] = (res[i + (n>>1)] * 1ll * i2)%mod;
		}
		cw = (cw * 1ll * gw)%mod;
	}
}
vi t1, t2;
void mul(vi &a, vi &b) {//a*=b
	int sz = a.size()+b.size(), m = 1;
	while(m < sz) m<<=1;
	while(a.size()<m) a.pb(0);
	while(b.size()<m) b.pb(0);
	ntt(a, t1, 0, 0, m, 1, 0);
	ntt(b, t2, 0, 0, m, 1, 0);
	for(int i = 0; i < m; i++)
		t1[i] = (t1[i] * 1ll * t2[i])%mod;
	ntt(t1, a, 0, 0, m, 1, 1);
	while(a.size()>300001) a.pop_back();
	while(!a.empty()&&!a.back()) a.pop_back();
}
int n, k, q;
vi a, b, qs, items, cur[5];
map<int, int> cnt;
void bp(int l, int r, vi &dp) {
	if(l+1==r) {
		if(items[l])
			dp = items[l]==1?vi{1, 2}:vi{1, 2, 1};
		else
			dp = {1};
		return;
	}
	vi tdp;
	int mid = (l+r)>>1;
	bp(l, mid, dp);
	bp(mid, r, tdp);
	mul(dp, tdp);
}
void solve() {
	sort(all(b));
	for(int i = 0; i < n; i++)
		cnt[a[i]]++;
	int p = 0, lst = -1;
	for(auto X : b) {
		items.clear();
		items.pb({0});
		for(auto i : cnt) {
			if(i.first > lst && i.first < X) {
				items.pb(i.second);
				lst = i.first;
			}
		}
		bp(0, items.size(), cur[p]);
		if(p) mul(cur[p], cur[p-1]);
		p++;
	}
}
int main() { //DINIC ORZ, FFT ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	pre();
	t1.resize(maxn+3);
	t2.resize(maxn+3);
	cin >> n >> k;
	a.resize(n);
	b.resize(k);
	for(auto &i : a) cin >> i;
	for(auto &i : b) cin >> i;
	solve();
	cin >> q;
	int t;
	while(q--) {
		cin >> t;
		int ans = 0;
		for(int i = 0; i < k; i++) {
			if(t - 2*b[i] - 2 >= 0 && (t - 2*b[i] - 2)/2 < cur[i].size()) {
				ans = (ans + cur[i][(t - 2*b[i] - 2)/2])%mod;
			}
		}
		cout << ans << "\n";
	}
}