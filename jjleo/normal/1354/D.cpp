#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int sum[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1) 

inline void up(int x){
	sum[x] = sum[ls(x)] + sum[rs(x)];
}

void add(int x, int l, int r, int pos){
	if(l == r){
		++sum[x];
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) add(ls(x), l, mid, pos);
	else add(rs(x), mid + 1, r, pos);
	up(x);
}

void erase(int x, int l, int r, int k){
	if(l == r){
		--sum[x];
		return;
	}
	int mid = l + r >> 1;
	if(sum[ls(x)] >= k) erase(ls(x), l, mid, k);
	else erase(rs(x), mid + 1, r, k - sum[ls(x)]);
	up(x);
}

int n, q;
int x;

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++) scanf("%d", &x), add(1, 1, n, x);
	while(q--){
		scanf("%d", &x);
		if(x > 0) add(1, 1, n, x);
		else erase(1, 1, n, -x);
	}
	if(!sum[1]) return printf("0"), 0;
	int l = 1, r = n, mid;
	x = 1;
	while(l < r){
		int mid = l + r >> 1;
		if(sum[ls(x)]) r = mid, x = ls(x);
		else l = mid + 1, x = rs(x);
	}
	printf("%d", l);
}