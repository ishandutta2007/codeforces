#include <bits/stdc++.h>
#define maxn 600086

using namespace std;

const int p = 1e9 + 7, inv2 = 500000004;
int sum[maxn], inv[maxn];
int a[maxn], c[maxn][2], pos[maxn];
pair<int, int> b[maxn];

struct Node{
	int val, siz, lval, rval;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].val = (t[ls(x)].val + t[rs(x)].val + 1ll * t[ls(x)].lval * t[rs(x)].rval % p * inv[t[ls(x)].siz]) % p;
	t[x].siz = t[ls(x)].siz + t[rs(x)].siz;
	t[x].lval = (t[ls(x)].lval + 1ll * t[rs(x)].lval * sum[t[ls(x)].siz]) % p;
	t[x].rval = (t[ls(x)].rval + 1ll * t[rs(x)].rval * inv[t[ls(x)].siz]) % p;
} 

void modify(int x, int l, int r, int pos, int d){
	if(l == r){
		if(d == 1){
			t[x].val = 0, t[x].siz = 1, t[x].lval = b[l].first, t[x].rval = 1ll * b[l].first * inv[1] % p;
		}else{
			t[x].val = t[x].siz = t[x].lval = t[x].rval = 0;
		}
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos, d);
	else modify(rs(x), mid + 1, r, pos, d);
	up(x);
}



int n, q, n0;

int main(){
	scanf("%d", &n), n0 = n;
	sum[0] = inv[0] = 1;
	for(int i = 1;i <= n;i++) sum[i] = (sum[i - 1] << 1) % p, inv[i] = 1ll * inv[i - 1] * inv2 % p;
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), b[i] = {a[i], i};
	scanf("%d", &q);
	for(int i = 1;i <= q;i++) scanf("%d%d", &c[i][0], &c[i][1]), ++n0, b[n0] = {c[i][1], n0};
	sort(b + 1, b + 1 + n0);
	for(int i = 1;i <= n0;i++){
		pos[b[i].second] = i;
	}
	for(int i = 1;i <= n;i++) modify(1, 1, n0, a[i] = pos[i], 1);
	printf("%d\n", t[1].val);
	for(int i = 1;i <= q;i++){
		modify(1, 1, n0, a[c[i][0]], -1);
		modify(1, 1, n0, a[c[i][0]] = pos[i + n], 1);
		printf("%d\n", t[1].val);
	}
}