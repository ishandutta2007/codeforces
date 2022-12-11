#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
struct ask {
	int l, r, id;
} qs[N];
int n, q, a[N], base[32], base_id[32], ans[N];
void insert(int id, int x) {
	for(int i = 30; ~ i; i --) {
		if(x >> i & 1) {
			if(!base[i]) {
				base[i] = x;
				base_id[i] = id;
				return ;
			}
			if(base_id[i] < id) {
				swap(base[i], x); swap(base_id[i], id);
			}
			x ^= base[i];
		}
	}
}
int query(int l) {
	int ans = 0;
	for(int i = 30; ~ i; i --) {
		if(ans < (ans ^ base[i]) && l <= base_id[i]) {
			ans ^= base[i];
		}
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
	}
	scanf("%d", &q);
	for(int i = 1; i <= q; i ++) {
		scanf("%d%d", &qs[i].l, &qs[i].r);
		qs[i].id = i;
	}
	sort(qs + 1, qs + q + 1, [&](ask x, ask y) {
		return x.r < y.r;
	});
	int p = 0;
	for(int i = 1; i <= q; i ++) {
		for(; p < qs[i].r; p ++) {
			insert(p + 1, a[p + 1]);
		}
		ans[qs[i].id] = query(qs[i].l);
	}
	for(int i = 1; i <= q; i ++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}