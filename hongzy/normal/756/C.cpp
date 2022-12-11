#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

int n, pos[N], ma[N << 2], tag[N << 2];

void pd(int u) {
	if(tag[u]) {
		tag[u << 1] += tag[u];
		ma[u << 1] += tag[u];
		tag[u << 1 | 1] += tag[u];
		ma[u << 1 | 1] += tag[u];
		tag[u] = 0;
	}
}

void pu(int u) {
	ma[u] = max(ma[u << 1], ma[u << 1 | 1]);
}

void upd(int u, int l, int r, int ql, int qr, int x) {
	if(l == ql && r == qr) {
		tag[u] += x; ma[u] += x; return ;
	}
	int mid = (l + r) >> 1; pd(u);
	if(qr <= mid) upd(u << 1, l, mid, ql, qr, x);
	else if(ql > mid) upd(u << 1 | 1, mid + 1, r, ql, qr, x);
	else {
		upd(u << 1, l, mid, ql, mid, x);
		upd(u << 1 | 1, mid + 1, r, mid + 1, qr, x);
	}
	pu(u);
}

int qry(int u, int l, int r) {
	if(l == r) return ma[u] == 1 ? l : -1;
	int mid = (l + r) >> 1; pd(u);
	if(ma[u << 1 | 1] >= 1) return qry(u << 1 | 1, mid + 1, r);
	if(ma[u << 1] >= 1) return qry(u << 1, l, mid);
	return -1;
}

int main() {
	scanf("%d", &n);
	int p, t, x;
	for(int i = 1; i <= n; i ++) {
		scanf("%d%d", &p, &t);
		if(t == 0)  {
			upd(1, 1, n, 1, p, -1);
		}
		if(t == 1) {
			upd(1, 1, n, 1, p, 1);
			scanf("%d", &pos[p]);
		}
		int ans = qry(1, 1, n);
		printf("%d\n", ans == -1 ? -1 : pos[ans]);
	}
	return 0;
}