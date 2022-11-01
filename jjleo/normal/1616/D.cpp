#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int mx[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	mx[x] = max(mx[ls(x)], mx[rs(x)]);
}

void modify(int x, int l, int r, int pos, int d){
	if(l == r){
		mx[x] = max(mx[x], d);
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos, d);
	else modify(rs(x), mid + 1, r, pos, d);
	up(x);
}

int query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return mx[x];
	int mid = l + r >> 1, sum = -1e9;
	if(mid >= ll) sum = max(sum, query(ls(x), l, mid, ll, rr));
	if(mid < rr) sum = max(sum, query(rs(x), mid + 1, r, ll, rr));
	return sum;
}

void build(int x, int l, int r){
	mx[x] = -1e9;
	if(l == r) return;
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r); 
}

int t, n, m;
int a[maxn], x;
ll sum[maxn];
int f[maxn];

int sk[maxn], top;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		scanf("%d", &x);
		for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
		build(1, 0, n);
		modify(1, 0, n, 0, 0);
		top = 0;
		int ans = 0, L = 0;
		for(int i = 1;i <= n;i++){
			f[i] = (i - 2 >= 0 ? f[i - 2] : 0) + 1;
			f[i] = max(f[i], f[i - 1]);
			if(top && sum[i] - 1ll * i * x < sum[sk[1]] - 1ll * sk[1] * x){
				int l = 1, r = top, mid;
				while(l < r){
					mid = (l + r >> 1) + 1;
					if(sum[i] - 1ll * i * x >= sum[sk[mid]] - 1ll * sk[mid] * x) r = mid - 1;
					else l = mid;
				}
				L = max(L, sk[l] + 1);
			}
			f[i] = max(f[i], query(1, 0, n, L, i - 1) + i);
			while(top && sum[i - 1] - 1ll * (i - 1) * x > sum[sk[top]] - 1ll * sk[top] * x) top--;
			sk[++top] = i - 1;
			ans = max(ans, f[i]);
			modify(1, 0, n, i, f[i - 1] - i);
		}
		printf("%d\n", ans);
	}
}