#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

typedef long long ll;

int n, m, x;
vector<pair<int, int> > v[maxn]; 

int fa[maxn];
ll a[maxn];
set<pair<ll, int> > st;

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main(){
	scanf("%d%d%d", &n, &m, &x);
	ll sum = 0;
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]), st.insert({a[i], i}), sum += a[i], fa[i] = i;
	if(sum < 1ll * (n - 1) * x) return printf("NO"), 0;
	for(int i = 1;i <= m;i++){
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back({y, i}), v[y].push_back({x, i});
	}
	puts("YES");
	while(!st.empty()){
		int i = st.rbegin()->second;st.erase({a[i], i});
		while(!v[i].empty() && i == find(v[i].back().first)) v[i].pop_back();
		if(v[i].empty()) continue;
		printf("%d\n", v[i].back().second);
		int j = find(v[i].back().first);
		st.erase({a[j], j});
		v[i].pop_back();
		if(v[i].size() > v[j].size()) swap(i, j);
		fa[i] = j, a[j] += a[i] - x;
		while(!v[i].empty()) v[j].push_back(v[i].back()), v[i].pop_back();
		st.insert({a[j], j});
	}
}