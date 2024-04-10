#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long LL;

LL sum[maxn];
LL mx[maxn << 2], mn[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

void build(int x, int l, int r){
	if(l == r){
		mx[x] = mn[x] = sum[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	mx[x] = max(mx[ls(x)], mx[rs(x)]);
	mn[x] = min(mn[ls(x)], mn[rs(x)]);
}

LL queryMax(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return mx[x];
	int mid = l + r >> 1;
	LL ans = -1e18;
	if(mid >= ll) ans = max(ans, queryMax(ls(x), l, mid, ll, rr));
	if(mid < rr) ans = max(ans, queryMax(rs(x), mid + 1, r, ll, rr));
	return ans;
}

LL queryMin(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return mn[x];
	int mid = l + r >> 1;
	LL ans = 1e18;
	if(mid >= ll) ans = min(ans, queryMin(ls(x), l, mid, ll, rr));
	if(mid < rr) ans = min(ans, queryMin(rs(x), mid + 1, r, ll, rr));
	return ans;
}

int n, q;
LL a[maxn], x;

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	for(int i = 1;i <= n;i++) scanf("%lld", &x), a[i] -= x, sum[i] = sum[i - 1] + a[i];
	build(1, 1, n);
	while(q--){
		int x, y;
		scanf("%d%d", &x, &y);
		if(sum[y] - sum[x - 1] != 0 || queryMax(1, 1, n, x, y) - sum[x - 1] > 0){
			puts("-1");
			continue;
		}
		printf("%lld\n", abs(queryMin(1, 1, n, x, y) - sum[x - 1]));
	}
}