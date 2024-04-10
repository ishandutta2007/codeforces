#include <bits/stdc++.h>
#define maxn 35086

using namespace std;

struct Node{
	int sum, tag;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].sum = min(t[ls(x)].sum ,t[rs(x)].sum);
}

inline void add(int x, int y){
	t[x].sum += y;
	t[x].tag += y;
}

inline void down(int x){
	if(!t[x].tag) return;
	add(ls(x), t[x].tag), add(rs(x), t[x].tag);
	t[x].tag = 0;
}

void modify(int x, int l, int r, int ll, int rr, int d){
	if(ll <= l && r <= rr){
		add(x, d);
		return;
	}
	int mid = l + r >> 1;
	down(x);
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
	up(x);
}

int f[maxn];

void build(int x, int l, int r){
	t[x].tag = 0;
	if(l == r){
		t[x].sum = f[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}
	
int n, k;
int a[maxn];
int last[maxn];

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	memset(f, 0x3f, sizeof(f)), f[0] = 0;
	while(k--){
		build(1, 0, n);
		for(int i = 1;i <= n;i++) last[i] = 0;
		for(int i = 1;i <= n;i++){
			if(last[a[i]]){
				modify(1, 0, n, 0, last[a[i]] - 1, i - last[a[i]]);
			}
			last[a[i]] = i;
			f[i] = t[1].sum;
		}
	}
	printf("%d", f[n]);
}