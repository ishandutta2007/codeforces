#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;
int n, id, a[N], s[N], T[N], pre[N], p[N];
int ls[N * 21], rs[N * 21], sum[N * 21];
bool cmp(int x, int y) {
	return pre[x] < pre[y];
}
void build(int &u, int l, int r) {
	u = ++ id;
	if(l == r) { sum[u] = s[l]; return ; }
	int mid = (l + r) >> 1;
	build(ls[u], l, mid);
	build(rs[u], mid + 1, r);
	sum[u] = sum[ls[u]] + sum[rs[u]];
//	printf("sum[%d, %d] = %d\n", l, r, sum[u]);
}
void insert(int &u, int la, int l, int r, int pos) {
	u = ++ id; ls[u] = ls[la]; rs[u] = rs[la]; sum[u] = sum[la] + 1;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	if(pos <= mid) insert(ls[u], ls[la], l, mid, pos);
	else insert(rs[u], rs[la], mid + 1, r, pos);
}
int qryk, qsum, qpos;
void solve(int u, int l, int r) {
	if(qsum + sum[u] <= qryk) {
		qsum += sum[u]; qpos = r; return ;
	}
	if(l == r) return ;
	int mid = (l + r) >> 1;
	if(qsum + sum[ls[u]] <= qryk) {
		qsum += sum[ls[u]]; qpos = mid;
		solve(rs[u], mid + 1, r);
	} else {
		solve(ls[u], l, mid);
	}
}
void solve(int u, int l, int r, int ql, int qr) {
	if(l == ql && r == qr) {
		qsum += sum[u]; qpos = qr;
		if(qsum > qryk) {
			qpos = l - 1; qsum -= sum[u];
//			fprintf(stderr, "note : [%d, %d]\n", ql, qr);
//			fprintf(stderr, "solving %d !\n", __LINE__);
			solve(u, l, r); 
//			fprintf(stderr, "solving %d !\n", __LINE__);
			qryk = -1;
		}
		return ;
	}
	int mid = (l + r) >> 1;
	if(qr <= mid) solve(ls[u], l, mid, ql, qr);
	else if(ql > mid) solve(rs[u], mid + 1, r, ql, qr);
	else {
		solve(ls[u], l, mid, ql, mid);
		if(~ qryk) solve(rs[u], mid + 1, r, mid + 1, qr);
	}
}
int main() {
	scanf("%d", &n);
	static int pos[N];
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
		pre[i] = pos[a[i]]; pos[a[i]] = i;
	}
	for(int i = 1; i <= n; i ++) p[i] = i;
	sort(p + 1, p + n + 1, cmp);
	int u = 1;
	for(; u <= n && !pre[p[u]]; u ++) s[p[u]] = 1; 
	build(T[0], 1, n);
	for(int i = 1; i <= n; i ++) {
		T[i] = T[i - 1];
		for(; u <= n && pre[p[u]] == i; u ++) 
			insert(T[i], T[i], 1, n, p[u]);
	}
	for(int k = 1; k <= n; k ++) {
		int ans = 0;
		for(int l = 1; l <= n; l = qpos + 1) {
			qsum = 0; qryk = k;
			solve(T[l - 1], 1, n, l, n);
			ans ++;
//			printf("qpos = %d!\n", qpos);
		}
		printf("%d%c", ans, " \n"[k == n]);
	}
	return 0;
}