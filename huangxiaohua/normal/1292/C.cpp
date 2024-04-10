#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,fa[3050][3050],x,y;
ll f[3050][3050],res,a[3050][3050];
vector<int> v[3050];

void dfs(int x,int f,int rt){
	fa[rt][x]=f;
	for(auto i:v[x]){
		if(i==f){continue;}
		dfs(i,x,rt);a[rt][x]+=a[rt][i];
	}
	a[rt][x]++;
}

ll g(int x,int y){
	if(f[x][y]||x==y)return f[x][y];
	return f[x][y]=max(g(fa[y][x],y),g(x,fa[x][y]))+a[x][y]*a[y][x];
}

int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++)
		scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	for(i=1;i<=n;i++)dfs(i,0,i);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			res=max(res,g(i,j));
	printf("%lld",res);
}