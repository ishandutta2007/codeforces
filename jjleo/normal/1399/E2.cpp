#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

struct Edge{
	int x, y, z;
};

int t;
int n;
ll s, sum;
int x, y, z, c;
vector<Edge> v[maxn];
vector<pair<int, int> > a[2];
int siz[maxn];
vector<ll> V[2];

priority_queue<pair<ll, int> > q[2]; 

void dfs(int i, int fa){
	siz[i] = 0;
	bool leaf = true;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].x;
		if(to == fa) continue;
		leaf = false;
		dfs(to, i);
		a[v[i][j].z].push_back({v[i][j].y, siz[to]});
		siz[i] += siz[to];
		sum += 1ll * v[i][j].y * siz[to];
	}
	if(leaf) siz[i] = 1;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%lld", &n, &s);
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 1;i < n;i++){
			scanf("%d%d%d%d", &x, &y, &z, &c);
			c--;
			v[x].push_back((Edge){y, z, c}), v[y].push_back((Edge){x, z, c});
		}
		while(!q[0].empty()) q[0].pop();a[0].clear(), V[0].clear();
		while(!q[1].empty()) q[1].pop();a[1].clear(), V[1].clear();
		sum = 0;
		dfs(1, 0);
		for(int j = 0;j <= 1;j++){
			for(int i = 0;i < a[j].size();i++) q[j].push({1ll * (a[j][i].first - a[j][i].first / 2) * a[j][i].second, i});
			ll x = 0;
			V[j].push_back(0);
			while(sum - x > s && !q[j].empty()){
				pair<ll, int> p = q[j].top();q[j].pop();
				x += p.first;
				V[j].push_back(x);
				a[j][p.second].first /= 2;
				if(a[j][p.second].first) q[j].push({1ll * (a[j][p.second].first - a[j][p.second].first / 2) * a[j][p.second].second, p.second});
			}
		}
		int ans = 1e9;
		//if(sum - V[0].back() <= s) ans = min(ans, (int)V[0].size() - 1);
		//if(sum - V[1].back() <= s) ans = min(ans, ((int)V[1].size() - 1) * 2);
		for(int i = 0;i < V[0].size();i++){
			ll x = sum - s - V[0][i];
			if(V[1].back() < x) continue;
			int j = lower_bound(V[1].begin(), V[1].end(), x) - V[1].begin();
			ans = min(ans, i + j * 2);
		}
		printf("%d\n", ans);
	}
}