#include <bits/stdc++.h>
#define maxn 500086
using namespace std;

int sum[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	sum[x] = __gcd(sum[ls(x)], sum[rs(x)]);
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

int query(int x, int l, int r, int ll, int rr, int d){
	if(sum[x] % d == 0) return 0;
	if(l == r) return 1;
	int mid = l + r >> 1, ans = 0;
	if(mid >= ll) ans += query(ls(x), l, mid, ll, rr, d);
	if(ans > 1) return ans;
	if(mid < rr) ans += query(rs(x), mid + 1, r, ll, rr, d);
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
int opt, x, y, z;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	build(1, 1, n);
	scanf("%d", &q);
	while(q--){
		scanf("%d", &opt);
		if(opt == 1){
			scanf("%d%d%d", &x, &y, &z);
			puts(query(1, 1, n, x, y, z) <= 1 ? "YES" : "NO");
		}else{
			scanf("%d%d", &x, &y);
			modify(1, 1, n, x, y);
		}
	}
}