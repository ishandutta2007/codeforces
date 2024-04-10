#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
int n;
ll s, sum;
int x, y, z;
vector<pair<int, int> > v[maxn], a;
int siz[maxn];

priority_queue<pair<ll, int> > q; 

void dfs(int i, int fa){
	siz[i] = 0;
	bool leaf = true;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first;
		if(to == fa) continue;
		leaf = false;
		dfs(to, i);
		a.push_back({v[i][j].second, siz[to]});
		siz[i] += siz[to];
		sum += 1ll * v[i][j].second * siz[to];
	}
	if(leaf) siz[i] = 1;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%lld", &n, &s);
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 1;i < n;i++){
			scanf("%d%d%d", &x, &y, &z);
			v[x].push_back({y, z}), v[y].push_back({x, z});
		}
		while(!q.empty()) q.pop();
		a.clear(), sum = 0;
		dfs(1, 0);
		for(int i = 0;i < a.size();i++) q.push({1ll * (a[i].first - a[i].first / 2) * a[i].second, i});
		int ans = 0;
		while(sum > s){
			pair<ll, int> p = q.top();q.pop();
			sum -= p.first;
			a[p.second].first /= 2;
			if(a[p.second].first) q.push({1ll * (a[p.second].first - a[p.second].first / 2) * a[p.second].second, p.second});
			ans++;
		}
		printf("%d\n", ans);
	}
}