#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,x,y,t,lg[100500],fa[100500][20],dep[100500],a[100500],sb,p1,p2,res,no;
vector<int> v[100500];

void dfs1(int x,int f){
	fa[x][0]=f;dep[x]=dep[f]+1;
	for(int i=1;i<=lg[dep[x]];i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(auto i:v[x]){
		if(i==f){continue;}
		dfs1(i,x);
		a[x]+=a[i];
	}
	a[x]++;
}

int lca(int x, int y) {
	if(dep[x]<dep[y]){swap(x, y);}
	while(dep[x]>dep[y]){x = fa[x][lg[dep[x]-dep[y]] - 1];}
	if(x == y) return x;
	for(int k = lg[dep[x]] - 1; k >= 0; --k)
		if(fa[x][k] != fa[y][k])
			x = fa[x][k], y = fa[y][k];
	return fa[x][0];
}

int get(int x){
	int tmp=dep[x]-dep[k]-sb,it=x;
	if(tmp<0){no=1;return 0;}tmp=sb-1;
	for(int i=20;i>=0;i--){
		if((1<<i)<=tmp){tmp-=(1<<i);it=fa[it][i];}
	}
	return a[it]+no*(n-a[fa[it][0]]);
}

int main(){
	for(i=1;i<=100000;i++){lg[i]=lg[i>>1]+1;}
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1,0);
	scanf("%d",&t);
	while(t--){
		res=no=0;
		scanf("%d%d",&x,&y);
		if(x==y){printf("%d\n",n);continue;}
		k=lca(x,y);
		sb=dep[x]+dep[y]-2*dep[k];
		if(sb&1){puts("0");continue;}sb=sb/2;
		if(dep[x]>dep[y]){swap(x,y);}
		res+=get(x);
		res+=get(y);
		printf("%d\n",n-res);
	}
}