#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,t,m,vis[400500],res[400500],sb1[400500],sb2[400500];
vector<int> v[400500];

void dfs(int x,int c){
	vis[x]=1;res[x]=c;
	for(auto i:v[x]){
		if(vis[i]==1){sb1[i]=1;continue;}
		if(vis[i]==2){sb2[i]=1;continue;}
		dfs(i,c);
	}
	vis[x]=2;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){v[i].clear();sb1[i]=sb2[i]=res[i]=0;}
		for(i=1;i<=m;i++){scanf("%d%d",&j,&k);v[j].push_back(k);}
		memset(vis,0,n*4+50);
		dfs(1,1);
		memset(vis,0,n*4+50);
		for(i=1;i<=n;i++){if(sb1[i]){dfs(i,-1);}}
		for(i=1;i<=n;i++){if(sb2[i]&&!vis[i]){dfs(i,2);}}
		for(i=1;i<=n;i++){printf("%d ",res[i]);}puts("");
	}
}