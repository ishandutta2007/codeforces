#include <bits/stdc++.h>
using namespace std;
 
int n, q;
struct upit {
	int l, r, x;
} a[10005], b[10005];
int bb;
 
bitset<10001> sol;
 
void solve(int l, int r, const vector<upit>& v, bitset<10001> bs) {
	if (l > r)
		return;
 
	if (l == r) {
		sol |= bs;
		return;
	}
 
	vector<upit> vl, vr;
	int m = (l+r) >> 1;
 
	auto bsl = bs;
	auto bsr = bs;
 
	for (auto u : v) {
		if (u.l <= l && m <= u.r)
			bsl |= bsl << u.x;
		else if (!(u.r < l || m < u.l))
			vl.push_back(u);
 
		if (u.l <= m+1 && r <= u.r)
			bsr |= bsr << u.x;
		else if (!(u.r < m+1 || r < u.l))
			vr.push_back(u);
	}
 
	solve(l, m, vl, bsl);
	solve(m+1, r, vr, bsr);
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
 
	cin >> n >> q;
	for (int i=0; i<q; i++)
		cin >> a[i].l >> a[i].r >> a[i].x;
 
	bitset<10001> bs0;
	bs0[0] = 1;
 
	for (int i=0; i<q; i++)
		if (a[i].l == 1 && a[i].r == n) {
			bs0 |= bs0 << a[i].x;
		} else {
			b[bb++] = a[i];
		}
 
	solve(1, n, vector<upit>(b, b+bb), bs0);
 
	int c = 0;
	for (int i=1; i<=n; i++)
		if (sol[i])
			c++;
 
	cout << c << '\n';
	for (int i=1; i<=n; i++)
		if (sol[i])
			cout << i << ' ';
 	cout << '\n'; // ja sam
}