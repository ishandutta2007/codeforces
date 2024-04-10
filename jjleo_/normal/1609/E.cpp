#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

inline int read(){
    int x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

int n, q, x;

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

int f[maxn << 2][32];
inline void up(int x){
	for(int i = 0;i < 32;i++) f[x][i] = 1e9;
	for(int i = 0;i < 32;i++) if(f[ls(x)][i] < 1e9) for(int j = 0;j < 32;j++){
		if((i & 8) && (j & 4) || (i & 1) && (j & 16)) continue;
		int k = i | j;
		if((i & 1) && (j & 2)) k |= 8;
		if((i & 2) && (j & 4)) k |= 16;
		f[x][k] = min(f[x][k], f[ls(x)][i] + f[rs(x)][j]);
	}
}
char s[maxn], c[10];

inline void init(int x, int l){
	for(int i = 0;i < 32;i++) f[x][i] = 1e9;
	for(int i = 0;i < 3;i++) f[x][1 << i] = s[l] - 'a' == i ? 0 : 1;
}

void modify(int x, int l, int r, int pos){
	if(l == r){
		init(x, l);
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos);
	else modify(rs(x), mid + 1, r, pos);
	up(x);
}

void build(int x, int l, int r){
	if(l == r){
		init(x, l);
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}

int main(){
	n = read(), q = read();
	scanf("%s", s + 1);
	build(1, 1, n);
	while(q--){
		x = read();
		scanf("%s", c);
		s[x] = c[0];
		modify(1, 1, n, x);
		int ans = 1e9;
		for(int i = 0;i < 32;i++) ans = min(ans, f[1][i]);
		printf("%d\n", ans);
	}
}