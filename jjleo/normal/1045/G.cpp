#include <bits/stdc++.h>
#define maxn 100086
using namespace std;

struct Node{
	int son[2], val, pri, siz;
}t[maxn];

int cnt;
int root[maxn];


inline int rand()
{
    static int seed=12345;
    return seed=(int)seed*482711LL%2147483647;
}

inline int ls(int x){
	return t[x].son[0];
}

inline int rs(int x){
	return t[x].son[1];
}

void up(int x){
	t[x].siz = t[ls(x)].siz + t[rs(x)].siz + 1;
}

int newnode(int val){
	cnt++;
	t[cnt].val = val;
	t[cnt].pri = rand();
	t[cnt].siz = 1;
	return cnt;
}

void split(int x, int val, int &a, int &b){//x val a b 
	if(!x){
		a = b = 0;
		return;
	}
	if(t[x].val <= val) a = x, split(rs(x), val, t[x].son[1], b);
	else b = x, split(ls(x), val, a, t[x].son[0]);
	up(x);
} 

int merge(int x, int y){// 
	if(x == 0 || y == 0) return x + y;
	if(t[x].pri > t[y].pri){
		t[x].son[1] = merge(rs(x), y);
		up(x);
		return x;
	}else{
		t[y].son[0] = merge(x, ls(y));
		up(y);
		return y;
	}
} 

int n, k;

struct N{
	int x, r, q;
}a[maxn];

inline bool cmp(N x, N y){
	return x.r > y.r;
}

long long ans;

int b[maxn], n0;
int A, B, C, D;

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%d%d%d", &a[i].x, &a[i].r, &a[i].q), b[i] = a[i].q;
	sort(a + 1, a + 1 + n, cmp); 
	sort(b + 1, b + 1 + n);
	n0 = unique(b + 1, b + 1 + n) - (b + 1);
	for(int i = 1;i <= n;i++){
		int x = lower_bound(b + 1, b + 1 + n0, a[i].q) - b;
		for(int j = x;j <= n0 && b[j] - b[x] <= k;j++){
			split(root[j], a[i].x - a[i].r - 1, A, B);
			split(B, a[i].x + a[i].r, C, D);
			ans += t[C].siz;
			root[j] = merge(A, merge(C, D));
		}
		for(int j = x - 1;j && b[x] - b[j] <= k;j--){
			split(root[j], a[i].x - a[i].r - 1, A, B);
			split(B, a[i].x + a[i].r, C, D);
			ans += t[C].siz;
			root[j] = merge(A, merge(C, D));
		}
		split(root[x], a[i].x, A, B);
		root[x] = merge(A, merge(newnode(a[i].x), B));
	}
	printf("%lld", ans);
} //