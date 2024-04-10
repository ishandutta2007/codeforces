#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

const int N = 2e5 + 10;
const int M = 460;

struct node {
	int id, l, r, t;
	bool operator < (const node &b) const { return l < b.l; }
} a[N], b[N];
int n, m, block, ans[N], bel[N], L[M], R[M], sz[M], ma[M], val[N], id[N], cnt, t_set[N];

void ins(int x) {
	val[a[x].t] = a[x].r;
	id[a[x].t] = a[x].id;
	ma[bel[a[x].t]] = max(ma[bel[a[x].t]], a[x].r);
}
int qry(int t, int low) {
	for(int i = t; i <= R[bel[t]]; i ++) {
		if(val[i] >= low) {
			return id[i];
		}
	}
	for(int i = bel[t] + 1; i <= bel[t_set[0]]; i ++) {
		if(ma[i] >= low) {
			for(int j = L[i]; j <= R[i]; j ++) {
				if(val[j] >= low) {
					return id[j];
				}
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) {
		a[i].id = i;
		scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].t);
		t_set[++ t_set[0]] = a[i].t;
	}
	for(int i = 1; i <= m; i ++) {
		b[i].id = i;
		scanf("%d%d%d", &b[i].l, &b[i].r, &b[i].t);
		t_set[++ t_set[0]] = b[i].t;
	}
	sort(t_set + 1, t_set + t_set[0] + 1);
	t_set[0] = unique(t_set + 1, t_set + t_set[0] + 1) - t_set - 1;
	sort(a + 1, a + n + 1); sort(b + 1, b + m + 1);
	for(int i = 1; i <= n; i ++) {
		a[i].t = lower_bound(t_set + 1, t_set + t_set[0] + 1, a[i].t) - t_set;
	}
	for(int i = 1; i <= m; i ++) {
		b[i].t = lower_bound(t_set + 1, t_set + t_set[0] + 1, b[i].t) - t_set;
	}
	block = (int) sqrt(t_set[0]);
	for(int i = 1; i <= t_set[0]; i ++) {
		bel[i] = (i - 1) / block + 1; sz[bel[i]] ++;
	}
	for(int i = 1; i <= bel[t_set[0]]; i ++) {
		L[i] = R[i - 1] + 1; R[i] = L[i] + sz[i] - 1;
	}
	int i = 0;
	for(int j = 1; j <= m; j ++) {
		while(i < n && a[i + 1].l <= b[j].l) ins(++ i);
		ans[b[j].id] = qry(b[j].t, b[j].r);
	}
	for(int i = 1; i <= m; i ++)
		printf("%d ", ans[i]);
	return 0;
}
/*
a, b:[l, r, t]
a[i].l <= b[j].l
ja[1] ~ a[i]l
a[k].r >= b[j].r, min a[k].t 
a[k] : ins(pos = a[k].t, val = a[k].r)
b[j] : query(b[j].r, 1e9)
*/