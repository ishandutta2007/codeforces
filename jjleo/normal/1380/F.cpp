#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

const int p = 998244353;

struct Node{
	int sum[2][2], l, r;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].l = t[ls(x)].l, t[x].r = t[rs(x)].r;
	for(int i = 0;i <= 1;i++){
		for(int j = 0;j <= 1;j++){
			t[x].sum[i][j] = 1ll * t[ls(x)].sum[i][1] * t[rs(x)].sum[1][j] % p;
			int y = t[ls(x)].r * 10 + t[rs(x)].l;
			if(y >= 10 && y <= 18){
				t[x].sum[i][j] += 1ll * t[ls(x)].sum[i][0] * t[rs(x)].sum[0][j] % p * (9 - (y - 9) + 1) % p;
				if(t[x].sum[i][j] >= p) t[x].sum[i][j] -= p;
			}
		}
	}
}

int a[maxn];

void build(int x, int l, int r){
	if(l == r){
		t[x].l = t[x].r = a[l];
		t[x].sum[1][1] = t[x].l + 1;
		t[x].sum[0][0] = 0, t[x].sum[0][1] = t[x].sum[1][0] = 1;
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}

void modify(int x, int l, int r, int pos, int d){
	if(l == r){
		t[x].l = t[x].r = d;
		t[x].sum[1][1] = t[x].l + 1;
		t[x].sum[0][0] = 0, t[x].sum[0][1] = t[x].sum[1][0] = 1;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos, d);
	else modify(rs(x), mid + 1, r, pos, d);
	up(x);
}

int n, m;
int x, y;
char s[maxn];

int main(){
	scanf("%d%d%s", &n, &m, s + 1);
	for(int i = 1;i <= n;i++) a[i] = s[i] - '0';
	build(1, 1, n);
	while(m--){
		scanf("%d%d", &x, &y);
		modify(1, 1, n, x, y);
		printf("%d\n", t[1].sum[1][1]);
	}
}