#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, x;
int a[maxn];

int sum[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	sum[x] = min(sum[ls(x)], sum[rs(x)]);
}

void modify(int x, int l, int r, int pos, int d){
	if(l == r){
		sum[x] = min(sum[x], d);
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos, d);
	else modify(rs(x), mid + 1, r, pos, d);
	up(x);
}

int query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return sum[x];
	int mid = l + r >> 1, ans = 0x3f3f3f3f;
	if(mid >= ll) ans = min(ans, query(ls(x), l, mid, ll, rr));
	if(mid < rr) ans = min(ans, query(rs(x), mid + 1, r, ll, rr));
	return ans;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &x);
		memset(sum, 0x3f, sizeof(sum));
		int ans = -1;
		modify(1, 0, x - 1, 0, 0);
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
			a[i] += a[i - 1];
			if(0 <= a[i] % x - 1) ans = max(ans, i - query(1, 0, x - 1, 0, a[i] % x - 1));
			if(a[i] % x + 1 <= x - 1) ans = max(ans, i - query(1, 0, x - 1, a[i] % x + 1, x - 1));
			modify(1, 0, x - 1, a[i] % x, i);
		}
		printf("%d\n", ans);
	}
}