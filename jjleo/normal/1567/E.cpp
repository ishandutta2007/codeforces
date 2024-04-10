#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long LL;

int a[maxn];

struct Node{
	LL sum;
	int llen, rlen, l, r;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline LL S(int n){
	return 1ll * n * (n + 1) / 2;
}

inline Node up(const Node &l, const Node &r){
	Node x;
	x.sum = l.sum + r.sum;
	x.l = l.l, x.r = r.r;
	if(l.r - l.l + 1 == l.llen && r.r - r.l + 1 == r.rlen){
		if(a[l.r] <= a[r.l]) x.llen = x.rlen = l.llen + r.rlen;
		else x.llen = l.llen, x.rlen = r.rlen;
	}else if(l.r - l.l + 1 == l.llen){
		if(a[l.r] <= a[r.l]) x.llen = l.llen + r.llen;
		else x.llen = l.llen, x.sum += S(r.llen);
		x.rlen = r.rlen;
	}else if(r.r - r.l + 1 == r.rlen){
		if(a[l.r] <= a[r.l]) x.rlen = r.rlen + l.rlen;
		else x.rlen = r.rlen, x.sum += S(l.rlen);
		x.llen = l.llen;
	}else{
		if(a[l.r] <= a[r.l]) x.sum += S(l.rlen + r.llen);
		else x.sum += S(l.rlen) + S(r.llen);
		x.llen = l.llen, x.rlen = r.rlen;
	}
	return x;
}

void modify(int x, int l, int r, int pos){
	if(l == r) return;
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos);
	else modify(rs(x), mid + 1, r, pos);
	t[x] = up(t[ls(x)], t[rs(x)]);
}

Node query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return t[x];
	int mid = l + r >> 1;
	if(mid < ll) return query(rs(x), mid + 1, r, ll, rr);
	if(mid >= rr) return query(ls(x), l, mid, ll, rr);
	return up(query(ls(x), l, mid, ll, rr), query(rs(x), mid + 1, r, ll, rr));
}

void build(int x, int l, int r){
	if(l == r){
		t[x].llen = t[x].rlen = 1;
		t[x].l = l, t[x].r = r;
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	t[x] = up(t[ls(x)], t[rs(x)]);
}

int n, q;
int opt, x, y; 

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	build(1, 1, n);
	while(q--){
		scanf("%d%d%d", &opt, &x, &y);
		if(opt == 1){
			a[x] = y;
			modify(1, 1, n, x);
		}else{
			Node a = query(1, 1, n, x, y);
			if(a.r - a.l + 1 == a.llen) printf("%lld\n", S(a.llen));
			else printf("%lld\n", a.sum + S(a.llen) + S(a.rlen));
		}
	}
}