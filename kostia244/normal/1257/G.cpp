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
const int w = 390359979, iw = 304321983;
const int maxn = (1 << 20), inv2 = 499122177;
void norm(int &x) {
	if(x>=mod) x-=mod;
	if(x<0) x+=mod;
}
int pw[maxn+1], ipw[maxn+1];
void init() {
	pw[maxn] = w, ipw[maxn] = iw;
	for(int i = maxn; i>>=1;){
		pw[i] = (pw[i<<1]*1ll*pw[i<<1])%mod;
		ipw[i] = (ipw[i<<1]*1ll*ipw[i<<1])%mod;
	}
}
vi a,res1, res2;
void ntt(vi &a, vi& ans, int l, int cl, int step, int n, bool inv) {
	if(n==1) {
		ans[l] = a[cl];
		return;
	}
	ntt(a, ans, l, cl, step<<1, n>>1, inv);
	ntt(a, ans, l + (n>>1), cl + step, step<<1, n>>1, inv);
	int cw = 1, gw = (inv ? ipw[n] : pw[n]);
	for(int i = l; i < l + (n>>1); i++) {
		int u = ans[i], v = (cw * 1ll * ans[i + (n>>1)])%mod;
		norm(ans[i] = u+v);
		norm(ans[i + (n>>1)] = u - v);
		if(inv) {
			ans[i] = (ans[i] * 1ll * inv2)%mod;
			ans[i + (n>>1)] = (ans[i + (n>>1)] * 1ll * inv2) %mod;
		}
		cw = (cw * 1ll * gw)%mod;
	}
}
int n;
vi mul(vi x, vi y, vi &res2) {
	int sz = x.size()+y.size(), m = 1;
	while(m < sz) m<<=1;
	while(x.size()<m) x.pb(0);
	while(y.size()<m) y.pb(0);
	res1.resize(m);
	res2.resize(m);
	ntt(x, res1, 0, 0, 1, m, 0);
	ntt(y, res2, 0, 0, 1, m, 0);
	for(int i = 0; i < res1.size(); i++)
		res1[i] = (res2[i]*1ll*res1[i])%mod;
	ntt(res1, res2, 0, 0, 1, m, 1);
//	for(int i = 0; i < m; i++) cout << x[i] << " ";
//	cout << " * ";
//	for(int i = 0; i < m; i++) cout << y[i] << " ";
//	cout << " = ";
	while(res2.size()>n) res2.pop_back();
	while(!res2.empty()&&!res2.back()) res2.pop_back();
	return res2;
}
void multiply(int l, int r, vi &res) {
	if(l+1==r) {
		res = vi(a[l]+1, 1);
		return;
	};
	vi a, b;
	multiply(l, (l+r)>>1, a);
	multiply((l+r)>>1, r, b);
	mul(a, b, res);
}
vi t;
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	map<int, int> cnt;
	cin >> n;
	for(int t, i = 0; i < n; i++)
		cin >> t, cnt[t]++;
	for(auto i : cnt) a.pb(i.second);
	multiply(0, a.size(), t);
	cout << t[n/2];
}