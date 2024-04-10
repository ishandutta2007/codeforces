#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

typedef long long ll;

ll mx[maxn << 2][2], mn[maxn << 2][2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	mx[x][0] = max(mx[ls(x)][0], mx[rs(x)][0]), mx[x][1] = max(mx[ls(x)][1], mx[rs(x)][1]);
	mx[x][0] = max(mx[x][0], max(mx[ls(x)][1] - mn[rs(x)][1], mx[ls(x)][0] + mx[rs(x)][0]));
	mx[x][1] = max(mx[x][1], max(mx[ls(x)][0] + mx[rs(x)][1], mx[ls(x)][1] - mn[rs(x)][0]));
	mn[x][0] = min(mn[ls(x)][0], mn[rs(x)][0]), mn[x][1] = min(mn[ls(x)][1], mn[rs(x)][1]);
	mn[x][0] = min(mn[x][0], min(mn[ls(x)][1] - mx[rs(x)][1], mn[ls(x)][0] + mn[rs(x)][0]));
	mn[x][1] = min(mn[x][1], min(mn[ls(x)][0] + mn[rs(x)][1], mn[ls(x)][1] - mx[rs(x)][0]));
}

void modify(int x, int l, int r, int pos, int d){
	if(l == r){
		mx[x][0] = mn[x][0] = 0, mx[x][1] = mn[x][1] = d;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos, d);
	else modify(rs(x), mid + 1, r, pos, d);
	up(x);
}

int a[maxn];

void build(int x, int l, int r){
	if(l == r){
		mx[x][0] = mn[x][0] = 0, mx[x][1] = mn[x][1] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}

int t;

int n, q;
int x, y;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &q);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		build(1, 1, n);
		printf("%lld\n", max(mx[1][0], mx[1][1]));
		while(q--){
			scanf("%d%d", &x, &y);
			swap(a[x], a[y]);
			modify(1, 1, n, x, a[x]), modify(1, 1, n, y, a[y]);
			printf("%lld\n", max(mx[1][0], mx[1][1]));
		}
	}
}