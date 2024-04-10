#include <algorithm>
#include <cstdio>
using namespace std;
const int K = 510;
struct Node {
	int op, l, r, x;
	bool operator < (const Node &b) const {
		return x < b.x;
	}
} a[K * 2];
int n, m, k, px[K], py[K], by[2 * K], cy, tag[2 * K], use[2 * K];
bool check(int mid) {
	cy = 0;
	for(int i = 1; i <= k; i ++) {
		int lx = max(1, px[i] - mid), rx = min(n, px[i] + mid);
		int ly = max(1, py[i] - mid), ry = min(m, py[i] + mid);
		a[i * 2 - 1] = (Node) {1, ly, ry, lx};
		a[i * 2] = (Node) {-1, ly, ry, rx + 1};
		by[++ cy] = ly; by[++ cy] = ry;	
	}
	mid <<= 1;
	a[2 * k + 1] = (Node) {0, 1, m, 1};
	a[2 * k + 2] = (Node) {0, 1, m, n};
	by[++ cy] = 1; by[++ cy] = m;
	sort(by + 1, by + cy + 1);
	cy = unique(by + 1, by + cy + 1) - by - 1;
	sort(a + 1, a + 2 * k + 3);
	fill(tag + 1, tag + cy + 1, 0);
	fill(use + 1, use + cy + 1, 0);
	int ly = m + 1, ry = 0, lx = n + 1, rx = 0;
	for(int i = 1; i <= 2 * k + 2; i ++) {
		if(a[i].x > n) break ;
		a[i].l = lower_bound(by + 1, by + cy + 1, a[i].l) - by;
		a[i].r = lower_bound(by + 1, by + cy + 1, a[i].r) - by;
		if(i > 1 && a[i].x - a[i - 1].x > 1) {
			for(int j = 1; j <= cy; j ++) {
				if(tag[j] <= 0) {
					lx = min(lx, a[i].x - 1);
					rx = max(rx, a[i].x - 1);
					ly = min(ly, by[j]);
					ry = max(ry, by[j]);
				}
				if(j < cy && by[j] + 1 < by[j + 1] && use[j] <= 0) {
					lx = min(lx, a[i].x - 1);
					rx = max(rx, a[i].x - 1);
					ly = min(ly, by[j] + 1);
					ry = max(ry, by[j + 1] - 1);
				}
			}
			if(ry - ly > mid) return 0;
			if(rx - lx > mid) return 0;
		}
		for(int j = a[i].l; j <= a[i].r; j ++) {
			tag[j] += a[i].op; use[j] += a[i].op;
		}
		use[a[i].r] -= a[i].op;
		if(i == 2 * k + 2 || a[i + 1].x != a[i].x) {
			for(int j = 1; j <= cy; j ++) {
				if(tag[j] <= 0) {
					lx = min(lx, a[i].x);
					rx = max(rx, a[i].x);
					ly = min(ly, by[j]);
					ry = max(ry, by[j]);
				}
				if(j < cy && by[j] + 1 < by[j + 1] && use[j] <= 0) {
					lx = min(lx, a[i].x);
					rx = max(rx, a[i].x);
					ly = min(ly, by[j] + 1);
					ry = max(ry, by[j + 1] - 1);
				}
			}
			if(ry - ly > mid) return 0;
			if(rx - lx > mid) return 0;
		}
	}
	return ry - ly <= mid && rx - lx <= mid;
}
 
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= k; i ++)
		scanf("%d%d", px + i, py + i);
	int l = 0, r = max(n, m), mid;
	while(l <= r) {
		mid = (l + r) >> 1;
		if(check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", r + 1);
	return 0;
}