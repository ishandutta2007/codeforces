#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int x, y;
vector<int> v[maxn];

vector<pair<int, int> > a, b;
bool del[maxn];
int id[maxn];

void dfs(int i, int fa){
	id[i] = 0;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs(to, i);
		if(del[to]) continue;
		if(del[i]){
			a.push_back({i, to});
			b.push_back({to, id[to]});
			continue;
		}
		if(!id[i]) id[i] = id[to];
		else{
			del[i] = true;
			if(fa) a.push_back({i, fa});
			b.push_back({id[i], id[to]});
		}
	}
	if(!id[i]) id[i] = i;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) v[i].clear(), del[i] = false;
		a.clear(), b.clear();
		for(int i = 1;i < n;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		dfs(1, 0);
		if(!del[1]) b.push_back({1, id[1]});
		printf("%d\n", a.size());
		for(int i = 0;i < a.size();i++) printf("%d %d %d %d\n", a[i].first, a[i].second, b[i].second, b[i + 1].first);
	}
}