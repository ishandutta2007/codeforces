#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int n;
int lg[maxn], st[maxn][25];
int a[maxn];

int query(int l, int r){
	return max(st[l][lg[r - l + 1]], st[r - (1 << lg[r - l + 1]) + 1][lg[r - l + 1]]);
}

int mn[maxn << 2];
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

void modify(int x, int l, int r, int ll, int rr, int d){
	if(ll <= l && r <= rr) {
		mn[x] = min(mn[x], d);
		return;
	}
	int mid = l + r >> 1;
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
}

void build(int x, int l, int r, int val){
	val = min(val, mn[x]);
	if(l == r){
		if(val == 1e9) printf("-1 ");
		else printf("%d ", val - l);
		if(l == n) exit(0);
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid, val), build(rs(x), mid + 1, r, val);
}

int main(){
	for(int i = 0;i < (maxn << 2);i++) mn[i] = 1e9;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), a[i + n] = a[i + n * 2] = a[i];
	for(int i = 2;i < maxn;i++) lg[i] = lg[i >> 1] + 1;
	for(int i = 1;i <= n * 3;i++) st[i][0] = a[i];
	for(int j = 1;j <= 20;j++) for(int i = 1;i + (1 << j) - 1 <= n * 3;i++) st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	for(int i = 2;i <= n * 3;i++){
		if(a[i] * 2 >= query(1, i - 1)) continue;
		int l = 1, r = i - 1, mid;
		while(l < r){
			mid = (l + r >> 1) + 1;
			if(a[i] * 2 < query(mid, i - 1)) l = mid;
			else r = mid - 1;
		}
		modify(1, 1, n * 3, 1, l, i);
	}
	build(1, 1, n * 3, 1e9);
}