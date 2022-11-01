#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n, m;
int x, y, z, sum;
bool a[1086][1086];
struct Edge{
	int x, y, z;
	
	inline bool operator < (const Edge &e) const {
		return z < e.z;
	}
}e[maxn];

int fa[maxn], siz[maxn];
bool tag[maxn];

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

vector<int> v[maxn];

inline bool merge(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return false;
	if(siz[x] > siz[y]) swap(x, y);
	fa[x] = y, siz[y] += siz[x]; 
	return true;
}

int main(){
	scanf("%d%d", &n, &m);
	if(1ll * n * (n - 1) / 2 - m <= n - 1){
		for(int i = 1;i <= m;i++){
			scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].z);
			sum ^= e[i].z;
			a[min(e[i].x, e[i].y)][max(e[i].x, e[i].y)] = true;
		}
		sort(e + 1, e + 1 + m);
		vector<pair<int, int> > v;
		for(int i = 1;i <= n;i++) for(int j = i + 1;j <= n;j++) if(!a[i][j]) v.push_back({i, j});
		ll ans = 1e18;
		for(int i = 0;i < v.size();i++){
			for(int j = 1;j <= n;j++) fa[j] = j, siz[j] = 1;
			ll val = 0;
			for(int j = 0;j < v.size();j++){
				if(i ^ j) merge(v[j].first, v[j].second);
			}
			bool tag = false;
			for(int j = 1;j <= m;j++){
				if(!tag && sum <= e[j].z){
					if(merge(v[i].first, v[i].second)) val += sum;
					tag = true;
				}
				if(merge(e[j].x, e[j].y)) val += e[j].z;
			}
			ans = min(ans, val);
		}
		return printf("%lld", ans), 0;
	}
	for(int i = 1;i <= n;i++) fa[i] = i, siz[i] = 1;
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d", &x, &y, &z);
		v[x].push_back(y), v[y].push_back(x);
		e[i] = (Edge){x, y, z};
	}
	x = 1;
	for(int i = 2;i <= n;i++) if(v[i].size() < v[x].size()) x = i;
	for(int i = 0;i < v[x].size();i++) tag[v[x][i]] = true;
	for(int i = 1;i <= n;i++) if(!tag[i]) merge(x, i);
	for(int i = 0;i < v[x].size();i++){
		int to = v[x][i];
		for(int j = 1;j <= n;j++) tag[j] = false;
		for(int j = 0;j < v[to].size();j++) tag[v[to][j]] = true;
		for(int j = 1;j <= n;j++) if(!tag[j]) merge(j, to);
	}
	sort(e + 1, e + 1 + m);
	ll ans = 0;
	for(int i = 1;i <= m;i++){
		if(merge(e[i].x, e[i].y)) ans += e[i].z;
	}
	printf("%lld", ans);
}