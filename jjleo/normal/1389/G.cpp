#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

typedef long long ll;

vector<pair<int, int> > v1[maxn], v2[maxn];

int val[maxn], sk[maxn], top, sum, dep[maxn];
int col[maxn], cnt;

void dfs1(int i, int fa){
	sk[++top] = i, dep[i] = dep[fa] + 1;
	for(int j = 0;j < v1[i].size();j++){
		int to = v1[i][j].first;
		if(to == fa) continue;
		if(dep[to]){
			if(dep[to] < dep[i]){
				val[i]++, val[to]--;
			}
		}else{
			dfs1(to, i);
			val[i] += val[to];
		}
	}
	//sum += val[i];
	
	if(!val[i]){
		++cnt;
		while(1){
			int x = sk[top--];
			col[x] = cnt;
			if(x == i) break;
		}
	}
}

int n, m, k;
bool tag[maxn], Tag[maxn];
int x, y;
int c[maxn], w[maxn];
ll C[maxn], f[maxn];

int Fa[maxn];

int find(int x){
	return x == Fa[x] ? x : Fa[x] = find(Fa[x]);
}

void dfs2(int i, int fa){
	for(int j = 0;j < v2[i].size();j++){
		int to = v2[i][j].first;
		if(to == fa) continue;
		dfs2(to, i);
		Tag[i] |= Tag[to];
	}
	if(!Tag[i]){
		C[fa] += C[i];
		Fa[i] = fa;
	}
	//printf("%d %d--\n", i, Tag[i]);
}

void dfs3(int i, int fa){
	for(int j = 0;j < v2[i].size();j++){
		int to = v2[i][j].first;
		if(to == fa || !Tag[to]) continue;
		dfs3(to, i);
		f[i] += max(0ll, f[to] - v2[i][j].second);
	}
	f[i] += C[i];
	
}

void dfs4(int i, int fa){
	for(int j = 0;j < v2[i].size();j++){
		int to = v2[i][j].first;
		if(to == fa || !Tag[to]) continue;
		f[to] += max(0ll, f[i] - max(0ll, f[to] - v2[i][j].second) - v2[i][j].second);
		dfs4(to, i);
	}
}


int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1;i <= k;i++){
		scanf("%d", &x);
		tag[x] = true;
	}
	for(int i = 1;i <= n;i++) scanf("%d", &c[i]);
	for(int i = 1;i <= m;i++) scanf("%d", &w[i]);
	for(int i = 1;i <= m;i++){
		scanf("%d%d", &x, &y);
		v1[x].push_back({y, w[i]}), v1[y].push_back({x, w[i]});
	}
	dfs1(1, 0);
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < v1[i].size();j++){
			int to = v1[i][j].first;
			if(col[i] == col[to]) continue;
			v2[col[i]].push_back({col[to], v1[i][j].second});
			//printf("%d %d--\n", col[i], col[to]);
		}
		//printf("%d %d-----\n", i, col[i]);
		Tag[col[i]] |= tag[i];
		C[col[i]] += c[i];
	}
	int rt;
	for(int i = 1;i <= cnt;i++){
		if(Tag[i]) rt = i;
		Fa[i] = i;
	}
	//printf("%d--\n", rt);
	dfs2(rt, 0);
	dfs3(rt, 0);
	dfs4(rt, 0);
	for(int i = 1;i <= n;i++) printf("%lld ", f[find(col[i])]);
}