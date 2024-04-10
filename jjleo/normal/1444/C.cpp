#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

typedef long long ll;

int n, m, k, N;
int a[maxn];
vector<int> b[maxn];
int x, y;
vector<int> v[maxn];
bool tag[maxn];
vector<pair<int, int> > w;
int c[maxn];
map<int, vector<pair<int, int> > > mp[maxn];

int fa[maxn], dep[maxn], siz[maxn];
int find(int x){
	return x == fa[x] ? x : find(fa[x]);
}

int dis(int x){
	return dep[x] ^ (x == fa[x] ? 0 : dis(fa[x]));
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), b[a[i]].push_back(i);
	while(m--){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
	}
	for(int i = 1;i <= n;i++) fa[i] = i, dep[i] = 0, siz[i] = 1;
	N = k;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < v[i].size();j++){
			int to = v[i][j];
			if(a[i] ^ a[to]) continue;
			if(tag[a[i]]) continue;
			int x = find(i), y = find(to), dx = dis(i), dy = dis(to);
			if(x == y){
				if(dx ^ dy ^ 1){
					tag[a[i]] = true;
					N--;
				}
			}else{
				if(siz[x] > siz[y]) swap(x, y);
				fa[x] = y, siz[y] += siz[x], dep[x] = dx ^ dy ^ 1;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(tag[a[i]]) continue;
		for(int j = 0;j < v[i].size();j++){
			int to = v[i][j];
			if(a[to] == a[i]) continue;
			mp[a[i]][a[to]].push_back({i, to});
		}
	}
	//for(int i = 1;i <= n;i++) printf("%d %d %d--\n", i, find(i), dis(i));
	ll ans = 1ll * N * (N - 1);
	for(int i = 1;i <= k;i++){
		if(tag[i]) continue;
		for(map<int, vector<pair<int, int> > >::iterator it = mp[i].begin();it != mp[i].end();++it){
			if(tag[it->first]) continue;
			vector<pair<int, int> > v = it->second;
			bool flag = false;
			for(int j = 0;j < v.size();j++){
				int I = v[j].first, to = v[j].second;
				int x = find(I), y = find(to), dx = dis(I), dy = dis(to);
				if(x == y){
					if(dx ^ dy ^ 1){
						flag = true;
						//printf("%d %d--\n", a[I], a[to]);
						ans--;
					}
				}else{
					if(siz[x] > siz[y]) swap(x, y);
					w.push_back({x, dep[x]});
					fa[x] = y, siz[y] += siz[x], dep[x] = dx ^ dy ^ 1;
				}
				if(flag) break;
			}
			while(!w.empty()){
				int x = w.back().first, d = w.back().second;
				dep[x] = d, siz[fa[x]] -= siz[x], fa[x] = x;
				w.pop_back();
			}
		}
	}
	printf("%lld", ans / 2);
}