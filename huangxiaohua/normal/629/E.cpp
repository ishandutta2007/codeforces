#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y,lg[100500],fa[100500][20],fa2;
vector<int> v[100500];
ll f2[100500],f3[100500],dep[100500];
double res,f1[100500];

int lca(int x, int y) {
	if(dep[x]<dep[y]){swap(x, y);}
	while(dep[x]>dep[y]){
		int tmp=lg[dep[x]-dep[y]] - 1;
		if(fa[x][tmp]==y){if(!tmp){fa2=x;return y;}else{x=fa[x][tmp-1];}}
		else{x=fa[x][tmp];}
	}
	for(int k = lg[dep[x]] - 1; k >= 0; --k)
		if(fa[x][k] != fa[y][k])
			x = fa[x][k], y = fa[y][k];
	return fa[x][0];
}

void dfs0(int x,int f){
	f1[x]++;fa[x][0]=f;dep[x]=dep[f]+1;
	for(int i=1;i<=lg[dep[x]];i++){fa[x][i]=fa[fa[x][i-1]][i-1];}
	for(auto i:v[x]){if(i==f){continue;}dfs0(i,x);f1[x]+=f1[i];f2[x]+=f1[i]+f2[i];}
}

void dfs1(int x,int fa){
	for(auto i:v[x]){
		if(i==fa){continue;}f3[i]=f3[x]+n-f1[i]*2;dfs1(i,x);
	}
}

int main(){
	dep[0]=-1;for(i=1;i<=100000;i++){lg[i]=lg[i>>1]+1;}
	scanf("%d%d",&n,&t);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs0(1,0);f3[1]=f2[1];dfs1(1,0);
	while(t--){
		scanf("%d%d",&x,&y);
		k=lca(x,y);
		if(k==x||k==y){
			if(k==y){swap(x,y);}
			printf("%.20lf\n",(dep[y]-dep[x]+1)+f2[y]/f1[y]+(f3[x]-f2[fa2]-f1[fa2])/(n-f1[fa2]));
		}
		else{
			printf("%.20lf\n",(dep[x]+dep[y]-2*dep[k]+1)+f2[y]/f1[y]+f2[x]/f1[x]);
		}
	}
}