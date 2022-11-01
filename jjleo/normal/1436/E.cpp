#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

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

int n, x;
int a[maxn];
bool tag[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		if(x != 1 && query(1, 1, n, 1, x - 1) > a[x]) tag[x] = true;
		if(x != 1) tag[1] = true;
		modify(1, 1, n, x, i);
		a[x] = i;
	}
	for(int i = 2;i <= n + 1;i++){
		if(query(1, 1, n, 1, i - 1) > a[i]) tag[i] = true;
	}
	for(int i = 1;i <= n + 2;i++) if(!tag[i]) return printf("%d", i), 0;
}