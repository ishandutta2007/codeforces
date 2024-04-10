#include <bits/stdc++.h>
#define maxn 200086
using namespace std;

struct Node{
	int sum[32];
	
	Node(){
		memset(sum, -0x3f, sizeof(sum));
	}
	
	inline int & operator [] (int i){
		return sum[i];
	}
	
}t[maxn << 2];


#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	for(int i = 0;i < 32;i++) t[x][i] = max(t[ls(x)][i], t[rs(x)][i]);
} 

void modify(int x, int l, int r, int pos, Node d){
	if(l == r){
		t[x] = d;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos, d);
	else modify(rs(x), mid + 1, r, pos, d);
	up(x);
}

Node query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return t[x];
	int mid = l + r >> 1;
	Node a, b;
	if(mid >= ll){
		b = query(ls(x), l, mid, ll, rr);
		for(int i = 0;i < 32;i++) a[i] = max(a[i], b[i]);
	}
	if(mid < rr){
		b = query(rs(x), mid + 1, r, ll, rr);
		for(int i = 0;i < 32;i++) a[i] = max(a[i], b[i]);
	}
	return a;
}

int n, k, x, y;
int q, opt;
Node a;


int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++){
		memset(a.sum, 0, sizeof(a.sum));
		for(int j = 0;j < k;j++){
			scanf("%d", &x);
			for(int l = 0;l < 32;l++){
				if(l & (1 << j)) a[l] += x;
				else a[l] -= x;
			}
		}
		modify(1, 1, n, i, a);
	}
	scanf("%d", &q);
	while(q--){
		scanf("%d", &opt);
		if(opt == 1){
			int i;
			scanf("%d", &i);
			memset(a.sum, 0, sizeof(a.sum));
			for(int j = 0;j < k;j++){
				scanf("%d", &x);
				for(int l = 0;l < 32;l++){
					if(l & (1 << j)) a[l] += x;
					else a[l] -= x;
				}
			}
			modify(1, 1, n, i, a);
		}else{
			scanf("%d%d", &x, &y);
			a = query(1, 1, n, x, y);
			int ans = -1e9;
			for(int i = 0;i < (1 << k);i++) ans = max(ans, a[i] + a[(1 << k) - 1 - i]);
			printf("%d\n", ans);
		}
	} 
}