#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

set<int> gph[100005];
int n, m;

int dfs(int x){
	vector<int> lis;
	while(gph[x].size()){
		int p = *gph[x].begin();
		gph[x].erase(p);
		gph[p].erase(x);
		int t = dfs(p);
		if(t != -1){
			printf("%d %d %d\n", x, p, t);
		}
		else{
			lis.push_back(p);
		}
	}
	for(int i=lis.size()%2; i<lis.size(); i+=2){
		printf("%d %d %d\n",lis[i], x, lis[i+1]);
	}
	if(lis.size() & 1) return lis[0];
	return -1;
}
int main(){
	scanf("%d %d",&n,&m);
	if(m%2 == 1){
		puts("No solution");
		return 0;
	}
	for(int i=0; i<m; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].insert(e);
		gph[e].insert(s);
	}
	dfs(1);
}