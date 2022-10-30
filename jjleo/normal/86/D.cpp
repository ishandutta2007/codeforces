#include <bits/stdc++.h>
#define maxn 1000086
using namespace std;

typedef long long ll;

struct Query{
	int x, y, sx, i;
}q[maxn];

inline bool cmp(Query a, Query b){
	return a.sx ^ b.sx ? a.sx < b.sx : a.sx & 1 ? a.y > b.y : a.y < b.y;
}

int n, sn, t;
int num[maxn];
ll sum, ans[maxn];
int l = 1, r = 0;

inline void modify(int x, int y){
	sum += 1ll * x * (num[x] + y) * (num[x] + y) - 1ll * x * num[x] * num[x];
	num[x] += y;
}

int a[maxn];

int main(){
	scanf("%d%d", &n, &t), sn = (int)sqrt(n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= t;i++) scanf("%d%d", &q[i].x, &q[i].y), q[i].sx = q[i].x / sn, q[i].i = i;
	sort(q + 1, q + 1 + t, cmp);
	for(int i = 1;i <= t;i++){
		while(l < q[i].x) modify(a[l++], -1);
		while(l > q[i].x) modify(a[--l], 1);
		while(r < q[i].y) modify(a[++r], 1);
		while(r > q[i].y) modify(a[r--], -1);
		ans[q[i].i] = sum;
	}
	for(int i = 1;i <= t;i++) printf("%lld\n", ans[i]);
}