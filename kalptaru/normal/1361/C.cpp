#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1 << 20;

int n;
int part[N][2];

bool vis[N];
vector <int> ans;
vector <PII> G[N];

//mark whole component as visited
void dfs(int u){
	vis[u] = true;
	for(auto v: G[u])
		if(!vis[v.st])
			dfs(v.st);
}

//check if the graph for a given Mask is correct
bool check(int Mask){
	for(int i = 0; i <= Mask; ++i)
		G[i].clear(), vis[i] = false;

	for(int i = 1; i <= n; ++i){
		int u = part[i][0] & Mask;
		int v = part[i][1] & Mask;
		
		G[u].push_back({v, 2 * i - 1});
		G[v].push_back({u, 2 * i - 2});
	}
	
	//calculate number of components and check if all degrees are even
	int comps = 0;
	for(int i = 0; i <= Mask; ++i){
		if(G[i].size() & 1)
			return false;
		
		if(!vis[i] && G[i].size() > 0){
			++comps;
			dfs(i);
		}
	}
	
	return comps == 1;
}

//find euler cycle
void go(int u, int prv = -1){
	while(G[u].size()){
		auto e = G[u].back();
		G[u].pop_back();

		if(vis[e.nd / 2])
			continue;
		
		vis[e.nd / 2] = true;
		go(e.st, e.nd);
	}
	
	if(prv != -1){
		ans.push_back(prv);
		ans.push_back(prv ^ 1);
	}
}

//restore the sequence corresponding to the result for given mask
//the result is already checked so the graph is built
void restore(int Mask){
	for(int i = 0; i <= n; ++i)
		vis[i] = false;
	
	for(int i = 0; i <= Mask; ++i)
		if(G[i].size()){
			go(i);
			break;
		}
	
	//cycle is reversed but thats fine
	for(int i = 0; i < n + n; ++i)
		printf("%d%c", ans[i] + 1, " \n"[i + 1 == n + n]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d %d", &part[i][0], &part[i][1]);

	for(int i = 20; i >= 0; --i)
		if(check((1 << i) - 1)){
			printf("%d\n", i);
			restore((1 << i) - 1);
			exit(0);
		}
	
	assert(false);
	return 0;
}