#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 1e9 + 7;

struct Node{
	int son[2], sum;
}t[maxn * 200];

int cnt;

#define ls(x) (t[x].son[0])
#define rs(x) (t[x].son[1])

inline void up(int x){
	t[x].sum = 1ll * t[ls(x)].sum * t[rs(x)].sum % p;
}

void modify(int x, int l, int r, int pos, int d){
	if(l == r){
		t[x].sum = 1ll * t[x].sum * d % p;
		return;
	}
	int mid = l + r >> 1, y = ++cnt;
	if(mid >= pos) t[y] = t[ls(x)], modify(ls(x) = y, l, mid, pos, d);
	else t[y] = t[rs(x)], modify(rs(x) = y, mid + 1, r, pos, d);
	up(x);
}

int query(int x, int l, int r, int ll, int rr){
	if((ll <= l && r <= rr) || !x) return t[x].sum;
	int mid = l + r >> 1, sum = 1;
	if(mid >= ll) sum = 1ll * sum * query(ls(x), l, mid, ll, rr) % p;
	if(mid < rr) sum = 1ll * sum * query(rs(x), mid + 1, r, ll, rr) % p;
	return sum;
}


int prm[maxn], tot;
bool tag[maxn];
int inv[maxn];

int n, q;
int l, r, x, last;
int pre[maxn];

int main(){
	for(int i = 2;i <= 450;i++){
		if(!tag[i]) prm[++tot] = i;
		for(int j = 1;i * prm[j] <= 450;j++){
			tag[i * prm[j]] = true;
			if(i % prm[j] == 0) break;
		}
	}
	inv[1] = 1;for(int i = 2;i < maxn;i++) inv[i] = 1ll * (p - p / i) * inv[p % i] % p; 
	scanf("%d", &n);
	cnt = n, t[0].sum = 1;
	for(int i = 1;i <= n;i++){
		scanf("%d", &x), t[i] = t[i - 1];
		modify(i, 1, n, i, x);
		for(int j = 1;j <= tot;j++){
			int k = 1;
			while(x % prm[j] == 0){
				x /= prm[j];
				k *= prm[j];
				if(pre[k]) modify(i, 1, n, pre[k], inv[prm[j]]);
				pre[k] = i;
			}
		}
		if((x ^ 1) && pre[x]) modify(i, 1, n, pre[x], inv[x]);
		pre[x] = i;
	}
	scanf("%d", &q);
	while(q--){
		scanf("%d%d", &l, &r);
		l = (l + last) % n + 1, r = (r + last) % n + 1;
		if(l > r) swap(l, r);
		printf("%d\n", last = query(r, 1, n, l, r));
	}
}