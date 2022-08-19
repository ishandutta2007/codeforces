#include<bits/stdc++.h>
using namespace std;
namespace game_on_tree{
	const int N=1e5;
	int n;
	vector<int>e[N];
	double ans;
	void dfs(int u,int fa,int dep){
		ans+=1.0/(dep+1);
		for(auto v:e[u]){
			if(v!=fa){
				dfs(v,u,dep+1);
			}
		}
	}
	int main(){
		scanf("%d",&n);
		for(int i=0;i<n-1;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u-1].push_back(v-1);
			e[v-1].push_back(u-1);
		}
		dfs(0,-1,0);
		printf("%.20lf\n",ans);
	}
}
int main(){
	game_on_tree::main();
	return 0;
}