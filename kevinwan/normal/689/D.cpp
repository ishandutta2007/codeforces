#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct seg_tree {
	vector<int> seg;
	function<int(int, int)> func;
	int n;
	void set_size(int n) { this->n=n,seg.resize(2 * n); }
	void set_func(function<int(int, int)> f) { func = f; }
	void init(int a[]) { for (int i = 0; i < n; i++)seg[n + i] = a[i]; for (int i = n - 1; i; i--)seg[i] = func(seg[i * 2], seg[i * 2 + 1]); }
	void update(int a, int b) { for (seg[a += n] = b, a >>= 1; a; a >>= 1)seg[a] = func(seg[a * 2], seg[a * 2 + 1]); }
	int query(int l, int r) {
		l += n, r += n;
		int ans = seg[l++];
		while (l <= r) {
			if (l & 1)ans = func(seg[l], ans),l++;
			if (!(r & 1))ans = func(seg[r], ans), r--;
			l >>= 1, r >>= 1;
		}
		return ans;
	}
};
int maxi(int a, int b) { return a > b ? a : b; }
int mini(int a, int b) { return a < b ? a : b; }
int aa[200000], bb[200000];
int main() {
	int n,i,j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", aa + i);
	for (i = 0; i < n; i++)scanf("%d", bb + i);
	seg_tree a, b;
	a.set_size(n);
	b.set_size(n);
	a.set_func(maxi);
	b.set_func(mini);
	a.init(aa);
	b.init(bb);
	ll ans = 0;
	for (i = 0; i < n; i++) {
		int cur = i - 1,lo;
		for (j = 1 << 17; j; j >>= 1) {
			if (cur + j >= n)continue;
			if (a.query(i, cur + j) < b.query(i, cur + j))cur += j;
		}
		lo = cur;
		cur = i - 1;
		for (j = 1 << 17; j; j >>= 1) {
			if (cur + j >= n)continue;
			if (a.query(i, cur + j) <= b.query(i, cur + j))cur += j;
		}
		ans += cur - lo;
	}
	printf("%lld", ans);
}