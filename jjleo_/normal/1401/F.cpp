#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

typedef long long LL;

LL sum[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	sum[x] = sum[ls(x)] + sum[rs(x)];
}

void modify(int x, int l, int r, int pos, int d){
	if(l == r){
		sum[x] = d;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos, d);
	else modify(rs(x), mid + 1, r, pos, d);
	up(x);
}


LL query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return sum[x];
	int mid = l + r >> 1;
	LL ans = 0;
	if(mid >= ll) ans += query(ls(x), l, mid, ll, rr);
	if(mid < rr) ans += query(rs(x), mid + 1, r, ll, rr);
	return ans;
}

int a[maxn];

void build(int x, int l, int r){
	if(l == r){
		sum[x] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}

int n, q;
int opt, x, y;
int k;

LL Query(int l, int r, int ll, int rr){
	if(ll <= l && r <= rr){
		int x = 1;
		while(x < r - l + 1) x <<= 1;
		x = ~(x - 1);
		return query(1, 0, n - 1, l ^ (k & x), r ^ (k & x));
	}
	int mid = l + r >> 1;
	LL ans = 0;
	if(mid >= ll) ans += Query(l, mid, ll, rr);
	if(mid < rr) ans += Query(mid + 1, r, ll, rr);
	return ans;
}

int main(){
	scanf("%d%d", &n, &q);
	n = 1 << n;
	for(int i = 0;i < n;i++) scanf("%d", &a[i]);
	build(1, 0, n - 1);
	while(q--){
		scanf("%d", &opt);
		switch(opt){
			case 1:
				scanf("%d%d", &x, &y);
				modify(1, 0, n - 1, (x - 1) ^ k, y);
				break;
			case 2:
				scanf("%d", &x);
				k ^= (1 << x) - 1;
				break;
			case 3:
				scanf("%d", &x);
				k ^= 1 << x;
				break;
			case 4:
				scanf("%d%d", &x, &y);
				printf("%lld\n", Query(0, n - 1, x - 1, y - 1));
				break;	
		}
	}
}