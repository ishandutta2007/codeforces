#include <bits/stdc++.h>
#define maxn 250086

using namespace std;

struct Seg{
	int sum[maxn << 2];
	
	#define ls(x) (x << 1)
	#define rs(x) (x << 1 | 1)
	
	inline void up(int x){
		sum[x] = min(sum[ls(x)], sum[rs(x)]);
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
}T[2];

int t, n;
int a[maxn];
int sk[maxn], top;
int lmx[maxn], lmn[maxn], rmx[maxn], rmn[maxn];
vector<int> vmx[maxn], vmn[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		if(n == 1){
			puts("0");
			continue;
		}
		top = 0;
		for(int i = 1;i <= n;i++){
			while(top && a[i] > a[sk[top]]) top--;
			if(top) lmx[i] = sk[top];
			else lmx[i] = 0;
			sk[++top] = i;
		}
		top = 0;
		for(int i = 1;i <= n;i++){
			while(top && a[i] < a[sk[top]]) top--;
			if(top) lmn[i] = sk[top];
			else lmn[i] = 0;
			sk[++top] = i;
		}
		top = 0;
		for(int i = n;i;i--){
			while(top && a[i] > a[sk[top]]) top--;
			if(top) rmx[i] = sk[top];
			else rmx[i] = 0;
			sk[++top] = i;
		}
		top = 0;
		for(int i = n;i;i--){
			while(top && a[i] < a[sk[top]]) top--;
			if(top) rmn[i] = sk[top];
			else rmn[i] = 0;
			sk[++top] = i;
		}
		for(int i = 1;i <= n;i++) vmx[i].clear(), vmn[i].clear();
		for(int i = 1;i <= n;i++){
			if(rmx[i]) vmx[rmx[i]].push_back(i);
			if(rmn[i]) vmn[rmn[i]].push_back(i);
		}
		T[0].build(1, 1, n), T[1].build(1, 1, n);
		for(int i = 1;i <= n;i++){
			if(i == 1){
				T[0].modify(1, 1, n, i, 0);
				T[1].modify(1, 1, n, i, 0);
				continue;
			}
			for(auto j : vmx[i]) T[0].modify(1, 1, n, j, 1e9);
			for(auto j : vmn[i]) T[1].modify(1, 1, n, j, 1e9);
			int ans = min(T[0].query(1, 1, n, lmn[i] + 1, i), T[1].query(1, 1, n, lmx[i] + 1, i)) + 1;
			T[0].modify(1, 1, n, i, ans);
			T[1].modify(1, 1, n, i, ans);
			if(i == n) printf("%d\n", ans);
		}
	}
}