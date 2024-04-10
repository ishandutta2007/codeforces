#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int n;
int a[maxn], b[maxn];
vector<pair<int, int> > v;
vector<int> ans;
int f[maxn];
pair<int, int> g[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), f[i] = 1e9;
	for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
	f[n] = 0, v.push_back({n - a[n], n});
	for(int i = n - 1;i;i--){
		int x = i + b[i];
		if(v.back().first > i) continue;
		int l = 0, r = v.size() - 1, mid;
		while(l < r){
			mid = l + r >> 1;
			if(v[mid].first <= i) r = mid;
			else l = mid + 1;
		}
		int k = v[l].second;
		if(f[k] + 1 < f[x]){
			f[x] = f[k] + 1;
			g[x] = {k, i};
		}
		if(x - a[x] < v.back().first) v.push_back({x - a[x], x});
	}
	int x = 0;
	for(int i = 1;i <= n;i++) if(i - a[i] == 0 && (x == 0 || f[x] > f[i])) x = i;
	if(x == 0 || f[x] == 1e9) return printf("-1"), 0;
	ans.push_back(0);
	while(x < n){
		ans.push_back(g[x].second);
		x = g[x].first;
	} 
	printf("%d\n", ans.size());
	for(int i = ans.size() - 1;~i;i--) printf("%d ", ans[i]);
}