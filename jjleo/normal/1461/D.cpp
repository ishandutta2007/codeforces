#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int n, q;
int t;
map<ll, bool> mp;
int a[maxn], x;
int b[maxn], c[maxn];

void dfs(int l, int r){
	if(l > r) return;
	ll sum = 0;
	int mx = 0, mn = 1e9;
	for(int i = l;i <= r;i++) sum += a[i], mx = max(mx, a[i]), mn = min(mn, a[i]);
	mp[sum] = true;
	if(l == r) return;
	int mid = mx + mn >> 1;
	int cnt1 = 0, cnt2 = 0;
	for(int i = l;i <= r;i++){
		if(a[i] <= mid) b[++cnt1] = a[i];
		else c[++cnt2] = a[i];
	}
	if(!cnt2) return;
	for(int i = 1;i <= cnt1;i++) a[l + i - 1] = b[i];
	for(int i = 1;i <= cnt2;i++) a[l + cnt1 + i - 1] = c[i];
	dfs(l, l + cnt1 - 1), dfs(l + cnt1, r);
}

int main(){
	scanf("%d", &t);
	while(t--){
		mp.clear();
		scanf("%d%d", &n, &q);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		dfs(1, n);
		while(q--){
			scanf("%d", &x);
			puts(mp[x] ? "Yes" : "No");
		}
	}
}