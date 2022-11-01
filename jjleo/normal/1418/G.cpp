#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

struct Node{
	int sum, tag;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	if(t[x].tag) t[x].sum = 0;
	else t[x].sum = t[ls(x)].sum + t[rs(x)].sum;
}

void modify(int x, int l, int r, int ll, int rr, int d){
	if(ll <= l && r <= rr){
		t[x].tag += d;
		if(l == r) t[x].sum = !t[x].tag;
		else up(x);
		return;
	}
	int mid = l + r >> 1;
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
	up(x);
}

int n, x;
int f[maxn][3];
long long ans;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		modify(1, 1, n, i, i, 0);//0 
		modify(1, 1, n, f[x][0] + 1, i, 1);
		if(f[x][2] + 1 <= f[x][1]) modify(1, 1, n, f[x][2] + 1, f[x][1], -1);
		if(f[x][2]) modify(1, 1, n, 1, f[x][2], 1);
		ans += t[1].sum;
		f[x][2] = f[x][1], f[x][1] = f[x][0], f[x][0] = i; 
	}
	printf("%lld", ans);
}