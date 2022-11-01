#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long LL;

struct Node{
	int mx, mn, cov;
	LL sum;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].sum = t[ls(x)].sum + t[rs(x)].sum;
	t[x].mx = max(t[ls(x)].mx, t[rs(x)].mx);
	t[x].mn = min(t[ls(x)].mn, t[rs(x)].mn);
}

inline void cover(int x, int l, int r, int y){
	t[x].mx = t[x].mn = t[x].cov = y;
	t[x].sum = 1ll * (r - l + 1) * y;
}

inline void down(int x, int l, int r){
	if(t[x].cov){
		int mid = l + r >> 1;
		cover(ls(x), l, mid, t[x].cov);
		cover(rs(x), mid + 1, r, t[x].cov);
		t[x].cov = 0;
	}
}

void modify(int x, int l, int r, int ll, int rr, int d){
	if(t[x].mn >= d) return;
	if(ll <= l && r <= rr && t[x].mx < d){
		cover(x, l, r, d);
		return;
	}
	down(x, l, r);
	int mid = l + r >> 1;
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
	up(x);
}

int query(int x, int l, int r, int ll, int rr, int &d){
	if(ll <= l && r <= rr){
		if(t[x].mn > d) return 0;
		if(t[x].sum <= d){
			d -= t[x].sum;
			return r - l + 1;
		}
		if(l == r) return 0;
	}
	down(x, l, r);
	int mid = l + r >> 1, sum = 0;
	if(mid >= ll) sum += query(ls(x), l, mid, ll, rr, d);
	if(mid < rr) sum += query(rs(x), mid + 1, r, ll, rr, d);
	return sum;
}

int a[maxn];

void build(int x, int l, int r){
	if(l == r){
		t[x].sum = t[x].mx = t[x].mn = a[l];
		return;
	} 
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}

int n, q;
int opt, x, y;

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	build(1, 1, n);
	while(q--){
		scanf("%d%d%d", &opt, &x, &y);
		if(opt == 1) modify(1, 1, n, 1, x, y);
		else printf("%d\n", query(1, 1, n, x, n, y));
	}
}