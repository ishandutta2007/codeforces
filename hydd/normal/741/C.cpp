#include<bits/stdc++.h>
using namespace std;
int n,col[210000],u[110000],v[110000];
vector<int> vec[210000];
void dfs(int u,int c){
	if (col[u]) return;
	col[u]=c;
	for (int v:vec[u]) dfs(v,3-c);
}
int main(){
	scanf("%d",&n); int x,y;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		u[i]=x; v[i]=y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for (int i=1;i<=n;i++){
		x=(i<<1)-1; y=(i<<1);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for (int i=1;i<=(n<<1);i++)
		if (!col[i]) dfs(i,1);
	for (int i=1;i<=n;i++) printf("%d %d\n",col[u[i]],col[v[i]]);
	return 0;
}