#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 10100;
using ll = long long;
int n, q;
bitset<maxn> ans, cur;
vector<int> seg[4*maxn];
void upd(int v, int l, int r, int ql, int qr, int x) {
	if(r < ql || qr < l) return;
	if(ql <= l && r <= qr) {
		seg[v].push_back(x);
		return;
	}
	int mid = (l+r)/2;
	upd(2*v, l, mid, ql, qr, x);
	upd(2*v+1, mid+1, r, ql, qr, x);
}
void dfs(int v, int l, int r) {
	bitset<maxn> old = cur;
	for(auto i : seg[v]) cur = cur|(cur<<i);
	if(l == r) {
		ans |= cur;
		return;
	}
	int mid = (l+r)/2;
	dfs(2*v, l, mid);
	dfs(2*v+1, mid+1, r);
	cur = old;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;
	for(int l, r, x, i = q; i--;) {
		cin >> l >> r >> x;
		upd(1, 1, n, l, r, x);
	}
	cur[0] = 1;
	dfs(1, 1, n);
	vector<int> rans;
	for(int i = 1; i <= n; i++) if(ans[i]) rans.push_back(i);
	cout << rans.size() << '\n';
	for(auto i : rans) cout << i << " "; cout << endl;
}