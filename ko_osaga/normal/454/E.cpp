#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

struct disj{
	int pa[100005];
	void init(int n){
		for(int i=0; i<=n; i++) pa[i] = i;
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
}disj;

vector<int> gph[100005];
vector<int> lis;
deque<int> dap;

int n, m, chk[100005];
int sz[100005];

void dfs(int x, int p){
	sz[x] = chk[x];
	for(auto &i : gph[x]){
		if(i == p) continue;
		dfs(i, x);
		sz[x] += sz[i];
	}
}

void dfs2(int x, int p){
	for(auto &i : gph[x]){
		if(i == p) continue;
		if(sz[i] % 2 == 1){
			dap.push_back(i);
			dfs2(i, x);
			dap.push_back(x);
		}
		else{
			dap.push_back(i);
			dap.push_back(x);
			dap.push_back(i);
			dfs2(i, x);
			dap.push_back(x);
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);
	disj.init(n);
	for(int i=0; i<m; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		if(disj.uni(s, e)){
			gph[s].push_back(e);
			gph[e].push_back(s);
		}
	}
	for(int i=1; i<=n; i++){
		scanf("%d",&chk[i]);
		if(chk[i]) lis.push_back(i);
	}
	for(int i=1; i<lis.size(); i++){
		if(disj.uni(lis[i], lis[i-1])){
			puts("-1");
			return 0;
		}
	}
	if(lis.empty()){
		puts("0");
		return 0;
	}
	if(lis.size() % 2 == 1){
		gph[lis.back()].push_back(0);
		gph[0].push_back(lis.back());
		lis.push_back(0);
		chk[0] = 1;
	}
	dap.push_back(lis.back());
	dfs(lis.back(), -1);
	dfs2(lis.back(), -1);
	if(dap.front() == 0) dap.pop_front();
	if(dap.back() == 0) dap.pop_back();
	for(auto &i : dap){
		chk[i] ^= 1;
	}
	while(!dap.empty() && chk[dap.back()]){
		chk[dap.back()] ^= 1;
		dap.pop_back();
	}
	printf("%d\n", dap.size());
	for(auto &i : dap) printf("%d ", i);
//	for(int i=1; i<=n; i++) printf("%d ", chk[i]);
}