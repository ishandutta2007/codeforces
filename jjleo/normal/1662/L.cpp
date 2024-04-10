#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

typedef long long ll;

int n, vv;
int t[maxn], x[maxn];
vector<ll> v;

int b[maxn];
	
inline void add(int x, int y){
	for(;x < maxn;x += x & -x) b[x] = max(b[x], y);
}

inline int query(int x){
	int sum = -0x3f3f3f3f;
	for(;x;x -= x & -x) sum = max(sum, b[x]);
	return sum;
}

inline void clear(int x){
	for(;x < maxn;x += x & -x) b[x] = -0x3f3f3f3f;
}

int f[maxn];
pair<int, int> a[maxn];
int F[maxn], G[maxn];

void solve(int l, int r){
	if(l == r){
		if(abs(x[l]) <= 1ll * vv * t[l]) f[l] = max(f[l], 1);
		return;
	}
	int mid = l + r >> 1;
	solve(l, mid);
	for(int i = l;i <= r;i++) a[i] = {x[i], i};
	sort(a + l, a + r + 1);
	for(int i = l;i <= r;i++){
		int j = a[i].second;
		if(j <= mid) add(F[j], f[j]);
		else f[j] = max(f[j], query(F[j]) + 1);
	}
	for(int i = l;i <= r;i++){
		int j = a[i].second;
		if(j <= mid) clear(F[j]);
	}
	for(int i = l;i <= r;i++) a[i] = {x[i], -i};
	sort(a + l, a + r + 1);
	for(int i = r;i >= l;i--){
		int j = -a[i].second;
		if(j <= mid) add(G[j], f[j]);
		else f[j] = max(f[j], query(G[j]) + 1);
	}
	for(int i = l;i <= r;i++){
		int j = -a[i].second;
		if(j <= mid) clear(G[j]);
	}
	solve(mid + 1, r);
}

int main(){
	scanf("%d%d", &n, &vv);
	for(int i = 1;i <= n;i++) scanf("%d", &t[i]);
	for(int i = 1;i <= n;i++) scanf("%d", &x[i]);
	for(int i = 1;i <= n;i++){
		v.push_back(x[i] + 1ll * vv * t[i]);
		v.push_back(-(x[i] - 1ll * vv * t[i]));
	}
	v.push_back(0);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 1;i <= n;i++){
		F[i] = lower_bound(v.begin(), v.end(), -(x[i] - 1ll * vv * t[i])) - v.begin() + 1;
		G[i] = lower_bound(v.begin(), v.end(), x[i] + 1ll * vv * t[i]) - v.begin() + 1;
	}
	memset(f, -0x3f, sizeof(f));
	memset(b, -0x3f, sizeof(b));
	solve(1, n);
	printf("%d", max(0, *max_element(f + 1, f + 1 + n)));
}