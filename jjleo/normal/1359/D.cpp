#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

struct Tree{
	int a[maxn];
	int sum[maxn << 2];
	
	#define ls(x) (x << 1)
	#define rs(x) (x << 1 | 1)
	
	inline void up(int x){
		sum[x] = min(sum[ls(x)], sum[rs(x)]);
	}
	
	void build(int x, int l, int r){
		if(l == r){
			sum[x] = a[l];
			return;
		}
		int mid = l + r >> 1;
		build(ls(x), l, mid), build(rs(x), mid + 1, r), up(x); 
	}
	
	int query(int x, int l, int r, int ll, int rr){
		if(ll <= l && r <= rr) return sum[x];
		int mid = l + r >> 1;
		int ans = 1e9;
		if(mid >= ll) ans = min(ans, query(ls(x), l, mid, ll, rr));
		if(mid < rr) ans = min(ans, query(rs(x), mid + 1, r, ll, rr));
		return ans;
	}
}t[2];

int n;
int a[maxn];
int l[maxn], r[maxn];
int sk[maxn], top;
int ans = -1e9;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++) t[0].a[i] = t[0].a[i - 1] + a[i];
	for(int i = n;i;i--) t[1].a[i] = t[1].a[i + 1] + a[i];
	t[0].build(1, 0, n), t[1].build(1, 1, n + 1);
	for(int i = 1;i <= n;i++){
		while(top && a[i] >= a[sk[top]]) --top;
		l[i] = sk[top];
		sk[++top] = i;
	}
	sk[0] = n + 1, top = 0;
	for(int i = n;i;i--){
		while(top && a[i] >= a[sk[top]]) --top;
		r[i] = sk[top];
		sk[++top] = i;
	}
	for(int i = 1;i <= n;i++){
		ans = max(ans, t[0].a[i - 1] - t[0].query(1, 0, n, l[i], i - 1) + t[1].a[i + 1] - t[1].query(1, 1, n + 1, i + 1, r[i]));
	}
	printf("%d", ans);
}