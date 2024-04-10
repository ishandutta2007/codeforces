#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int sum[maxn << 2];
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

void modify(int x, int l, int r, int pos, int d){
	sum[x] = min(sum[x], d);
	if(l == r) return;
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos, d);
	else modify(rs(x), mid + 1, r, pos, d); 
}

int query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return sum[x];
	int mid = l + r >> 1, ans = 1e9;
	if(mid >= ll) ans = min(ans, query(ls(x), l, mid, ll, rr));
	if(mid < rr) ans = min(ans, query(rs(x), mid + 1, r, ll, rr));
	return ans;
}

void build(int x, int l, int r){
	sum[x] = 1e9;
	if(l == r) return;
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
}

int t; 
int n;
int a[maxn], f[maxn], g[maxn];
int st[maxn][25], lg[maxn];
int ans[maxn];

inline int Query(int l, int r){
	return max(st[l][lg[r - l + 1]], st[r - (1 << lg[r - l + 1]) + 1][lg[r - l + 1]]);
}

int main(){
	for(int i = 2;i < maxn;i++) lg[i] = lg[i >> 1] + 1;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		build(1, 0, n);
		for(int i = 1;i <= n;i++) st[i][0] = min(n, i + a[i]);
		for(int j = 1;j <= 20;j++){
			for(int i = 1;i + (1 << j) - 1 <= n;i++){
				st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);	
			}
		}
		for(int i = 1;i <= n;i++){
			g[i] = query(1, 0, n, max(0, i - a[i] - 1), f[i - 1]);
			if(g[i] == 1e9) f[i] = f[i - 1], g[i] = 0;
			else{
				f[i] = max(i - 1, g[i] + 1 <= i - 1 ? Query(g[i] + 1, i - 1) : 0);
				if(!g[g[i]]) f[i] = max(f[i], g[i] + a[g[i]]);
			}
			if(f[i - 1] >= i){
				if(max(f[i - 1], i + a[i]) >= f[i]){
					f[i] = max(f[i - 1], i + a[i]);
					g[i] = 0;
				}
			}
			modify(1, 0, n, f[i] = min(f[i], n), i);
		}
		if(f[n] < n){
			puts("NO"); 
			continue;
		}
		puts("YES");
		for(int i = 1;i <= n;i++) ans[i] = 0;
		int x = n;
		while(x){
			if(!g[x]) x--;
			else ans[x] = 1, x = g[x];
		}
		for(int i = 1;i <= n;i++) printf(ans[i] ? "L" : "R");
		puts("");
	}
}