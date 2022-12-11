#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1 << 17 | 5;

int n, m, w[N << 2], d[N << 2];

void build(int rt, int l, int r) {
	if(l == r) {
		scanf("%d", w + rt); d[rt] = 0; return ;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	d[rt] = d[rt << 1] + 1;
	if(d[rt] & 1) w[rt] = w[rt << 1] | w[rt << 1 | 1];
	else w[rt] = w[rt << 1] ^ w[rt << 1 | 1];
}

void upd(int rt, int l, int r, int x, int p) {
	if(l == r) {
		w[rt] = p; return ;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) upd(rt << 1, l, mid, x, p);
	else upd(rt << 1 | 1, mid + 1, r, x, p);
	if(d[rt] & 1) w[rt] = w[rt << 1] | w[rt << 1 | 1];
	else w[rt] = w[rt << 1] ^ w[rt << 1 | 1];
}

int main() {
	scanf("%d%d", &n, &m); n = 1 << n;
	build(1, 1, n);
	while(m --) {
		int x, y;
		scanf("%d%d", &x, &y);
		upd(1, 1, n, x, y);
		printf("%d\n", w[1]);
	}
	return 0;
}