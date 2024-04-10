#include<cstdio>
#include<vector>
using namespace std;
int n,tot[2];
vector<int> vec[210000];
void dfs(int u,int fa,int d){
	tot[d]++;
	for (int v:vec[u]){
		if (v==fa) continue;
		dfs(v,u,d^1);
	}
}
int main(){
	scanf("%d",&n); int u,v;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(1,0,0);
	printf("%d\n",min(tot[0],tot[1])-1);
	return 0;
}