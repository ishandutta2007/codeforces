#include <bits/stdc++.h>
#define maxn 100086
using namespace std;

typedef long long LL;

struct Node{
	LL sum;
	int mx;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].sum = t[ls(x)].sum + t[rs(x)].sum;
	t[x].mx = max(t[ls(x)].mx, t[rs(x)].mx);
}

LL query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return t[x].sum;
	int mid = l + r >> 1;
	LL sum = 0;
	if(mid >= ll) sum += query(ls(x), l, mid, ll, rr);
	if(mid < rr) sum += query(rs(x), mid + 1, r, ll, rr);
	return sum; 
}

void modify(int x, int l, int r, int pos, int d){
	if(l == r){
		t[x].sum = t[x].mx = d;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos, d);
	else modify(rs(x), mid + 1, r, pos, d);
	up(x); 
} 

void modulo(int x, int l, int r, int ll, int rr, int d){
	if(t[x].mx < d) return;
	if(l == r){
		t[x].sum %= d, t[x].mx %= d;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= ll) modulo(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modulo(rs(x), mid + 1, r, ll, rr, d);
	up(x);
}

int a[maxn];

void build(int x, int l, int r){
	if(l == r){
		t[x].sum = t[x].mx = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}

int n, m;
int opt, x, y, z;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	build(1, 1, n);
	while(m--){
		scanf("%d", &opt);
		switch(opt){
			case 1:
				scanf("%d%d", &x, &y);
				printf("%lld\n", query(1, 1, n, x, y));
				break;
			case 2:
				scanf("%d%d%d", &x, &y, &z);
				modulo(1, 1, n, x, y, z);
				break;
			case 3:
				scanf("%d%d", &x, &y);
				modify(1, 1, n ,x, y);
				break;	 
		}
	}
}