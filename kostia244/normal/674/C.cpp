#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<18;
int mod = 1e9 + 7;
struct node {
	ld cur, inv, sum;
	node() : cur(0), inv(0), sum(0) {}
	node(ld x) {
		sum = x; cur=1;inv=1./x;
	}
};
node merge(node a, node b) {
	if(a.inv < 1e-10) return b;
	if(b.inv < 1e-10) return a;
	node res;
	res.cur = a.cur + b.cur + a.sum*b.inv;
	res.inv = a.inv + b.inv;
	res.sum = a.sum + b.sum;
	return res;
}
node tree[maxn*2];
int n, k;
ld dp[55][maxn], t[maxn];
void upd(int v, node val) {
	for(tree[v += n] = val; v>>=1;) tree[v] = merge(tree[v<<1], tree[v<<1|1]);
}
node query(int l, int r) {
	if(l > r) return node();
	node al, ar;
	for(l += n, r += n; l < r; l>>=1, r>>=1) {
		if(l&1) al = merge(al, tree[l++]);
		if(r&1) ar = merge(tree[--r], ar);
	}
	return merge(al, ar);
}
void calc(int x, int l, int r, int ql, int qr) {
	if(l > r) return;
	int mid = (l+r)/2;
	//cout << l << " " << mid << " " << r << " " << ql << " " << qr << endl;
	pair<ld, int> opt = {1e18, -1};
	ld cur = 0, inv = 0;/*
	for(int i = r; i > qr; i--) {
		inv += 1./t[i];
		cur += t[i]*inv;
	}*/
	auto T = query(qr, mid);
	cur = T.cur, inv = T.inv;
	for(int i = min(qr, mid); i >= ql; i--) {
		//cout << i << " - " << dp[x-1][i] << " " << cur << endl;
		opt = min(opt, {cur+dp[x-1][i], i});
		if(i) {
		inv += 1./t[i];
		cur += t[i]*inv;
		}
		//cout << i << " - " << dp[x-1][i] << " " << cur << endl;
	}
	//cout << mid << ":= " << opt.first << endl;
	dp[x][mid] = min((ld)1e18, opt.first);
	calc(x, l, mid-1, ql, opt.second);
	calc(x, mid+1, r, opt.second, qr);
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> t[i], dp[0][i] = 1e18;
	for(int i = 0; i < n; i++) upd(i, node(t[i+1]));
	dp[0][0] = 0;
	//for(int i = 0; i < n; i++) {
		//auto t = query(0, i+1);
		//cout << t.cur << " ";}cout << endl;
	
	for(int l = 1; l <= k; l++) {
		calc(l, 1, n, 0, n);
		//for(int i = 0; i <= n; i++) cout << dp[l][i] << " "; cout << endl;
	}
	cout << fixed << setprecision(15) << dp[k][n] << endl;
}