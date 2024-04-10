#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

typedef long long LL;

LL sum[maxn << 2], tag[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	sum[x] = max(sum[ls(x)], sum[rs(x)]);
}

inline void cover(int x, LL y){
	sum[x] = max(sum[x], y);
	tag[x] = max(tag[x], y);
}

inline void down(int x){
	if(tag[x] == -1e18) return;
	cover(ls(x), tag[x]), cover(rs(x), tag[x]);
	tag[x] = -1e18;
}

void modify(int x, int l, int r, int ll, int rr, LL d){
	if(ll <= l && r <= rr){
		cover(x, d);
		return;
	}
	down(x);
	int mid = l + r >> 1;
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
	up(x);
}

LL query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return sum[x];
	down(x);
	LL ans = -1e18;
	int mid = l + r >> 1;
	if(mid >= ll) ans = max(ans, query(ls(x), l, mid, ll, rr));
	if(mid < rr) ans = max(ans, query(rs(x), mid + 1, r, ll, rr));
	return ans;
}

void build(int x, int l, int r){
	sum[x] = tag[x] = -1e18;
	if(l == r) return;
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
}


int n;
int h[maxn], a[maxn], l[maxn], r[maxn];
int sk[maxn], top;
int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &h[i]);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	build(1, 0, n);
	modify(1, 0, n, 0, 0, 0);
	for(int i = 1;i <= n;i++){
		while(top && h[sk[top]] > h[i]) top--;
		if(top) l[i] = sk[top];
		else l[i] = 0;
		sk[++top] = i;
	}
	top = 0;
	for(int i = n;i;i--){
		while(top && h[sk[top]] > h[i]) top--;
		if(top) r[i] = sk[top] - 1;
		else r[i] = n;
		sk[++top] = i;
	}
	for(int i = 1;i <= n;i++){
		modify(1, 0, n, i, r[i], a[i] + query(1, 0, n, l[i], i - 1));
	}
	printf("%lld", query(1, 0, n, n, n));
}