#include <bits/stdc++.h>
#define maxn 400086
using namespace std;

int a[maxn][2], b[maxn];

struct Node{
	bool cov;
	int sum, l, r;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	if(t[x].cov) t[x].sum = b[t[x].r] - b[t[x].l];
	else t[x].sum = t[ls(x)].sum + t[rs(x)].sum;
}

inline void down(int x){
	if(t[x].cov){
		t[ls(x)].cov = true, up(ls(x));
		t[rs(x)].cov = true, up(rs(x));
	}
}

void modify(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr){
		t[x].cov = true, up(x);
		return;
	}
	down(x);
	int mid = l + r >> 1;
	if(mid >= ll) modify(ls(x), l, mid, ll, rr);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr);
	up(x);
}

int query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return t[x].sum;
	down(x);
	int mid = l + r >> 1, sum = 0;
	if(mid >= ll) sum += query(ls(x), l, mid, ll, rr);
	if(mid < rr) sum += query(rs(x), mid + 1, r, ll, rr);
	return sum;
}

void build(int x, int l, int r){
	if(l == r){
		t[x].l = l, t[x].r = r + 1;
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r); 
	t[x].l = t[ls(x)].l, t[x].r = t[rs(x)].r;
}

int n, n0, m;
int x, y;
int ans[maxn];

struct Query{
	int x, y, i;
}q[maxn];

inline bool cmp(Query x, Query y){
	return x.x > y.x;
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d%d", &a[i][0], &a[i][1]);
		a[i][1] += a[i][0];
		b[++n0] = a[i][0], b[++n0] = a[i][1];
	}
	sort(b + 1, b + 1 + n0);
	n0 = unique(b + 1, b + 1 + n0) - (b + 1);
	build(1, 1, n0 - 1);
	scanf("%d", &m);
	for(int i = 1;i <= m;i++) scanf("%d%d", &q[i].x, &q[i].y), q[i].i = i;
	sort(q + 1, q + 1 + m, cmp);
	int x = n + 1;
	for(int i = 1;i <= m;i++){
		int l = lower_bound(b + 1, b + 1 + n0, a[q[i].x][0]) - b, r = lower_bound(b + 1, b + 1 + n0, a[q[i].y][0]) - b;
		//printf("%d %d %d %d--\n", a[x][0], a[x][1], lower_bound(b + 1, b + 1 + n0, a[x][0]) - b, lower_bound(b + 1, b + 1 + n0, a[x][1]) - b);
		while(x > q[i].x){
			--x, modify(1, 1, n0 - 1, lower_bound(b + 1, b + 1 + n0, a[x][0]) - b, lower_bound(b + 1, b + 1 + n0, a[x][1]) - b - 1);
			//printf("%d %d--\n", x, t[1].sum);
		}
		//printf("%d %d %d %d %d--\n", b[r], b[l], r, l, query(1, 1, n0 - 1, l, r - 1));
		ans[q[i].i] = b[r] - b[l] - query(1, 1, n0 - 1, l, r - 1);
	}
	for(int i = 1;i <= m;i++) printf("%d\n", ans[i]);
}