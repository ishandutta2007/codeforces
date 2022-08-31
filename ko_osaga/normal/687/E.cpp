#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

vector<int> gph[5005], rev[5005];
vector<int> dfn;

int n, m;
int comp[5005], p, vis[5005], csize[5005];
int outdeg[5005];

void dfs(int x){
	if(vis[x]) return;
	vis[x] = 1;
	for(auto &i : gph[x]){
		dfs(i);
	}
	dfn.push_back(x);
}

void rdfs(int x, int p){
	if(comp[x]) return;
	comp[x] = p;
	csize[p]++;
	for(auto &i : rev[x]){
		rdfs(i, p);
	}
}

int bfs(int s, int e){
	queue<int> que;
	int vis[5005] = {}, dist[5005] = {};
	que.push(s);
	vis[s] = 1;
	while(!que.empty()){
		int x = que.front();
		que.pop();
		for(auto &i : gph[x]){
			if(!vis[i]){
				vis[i] = 1;
				dist[i] = dist[x] + 1;
				que.push(i);
			}
		}
	}
	return dist[e];
}

int mincyc[5005];

int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int s, e;
		cin >> s >> e;
		gph[s].push_back(e);
		rev[e].push_back(s);
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]) dfs(i);
	}
	reverse(dfn.begin(), dfn.end());
	for(auto &i : dfn){
		if(!comp[i]) rdfs(i, ++p);
	}
	for(int i=1; i<=n; i++){
		for(auto &j : gph[i]){
			if(comp[i] != comp[j]){
				outdeg[comp[i]]++;
			}
		}
	}
	memset(mincyc, 0x3f, sizeof(mincyc));
	for(int i=1; i<=n; i++){
		for(auto &j : gph[i]){
			if(comp[i] == comp[j] && outdeg[comp[i]] == 0){
				mincyc[comp[i]] = min(mincyc[comp[i]], bfs(j, i) + 1);
			}
		}
	}
	int ret = n;
	for(int i=1; i<=p; i++){
		if(csize[i] == 1) continue;
		if(outdeg[i] == 0) ret += mincyc[i] * 998 + 1;
	}
	cout << ret;
}