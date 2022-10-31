#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,m,t,k,sb[100500],dep[100500],vis[100500],fa[100500],x,y,it,m0,m1,st0[100500],st1[100500];
vector<int> v[100500];

void dfs(int x,int f){
	vis[x]=1;fa[x]=f;dep[x]=dep[f]+1;
	if(!sb[x]){for(auto i:v[x]){sb[i]=1;}}
	for(auto i:v[x]){
		int y=dep[x]-dep[i]+1;
		if(dep[i]&&y<=k&&y>2){
			printf("2\n%d\n",dep[x]-dep[i]+1);
			it=x;
			while(1){
				printf("%d ",it);
				if(it==i){exit(0);}it=fa[it];
			}
		}
		if(vis[i]){continue;}
		dfs(i,x);
	}
	if(sb[x]){st1[++m1]=x;}
	else{st0[++m0]=x;}
}

void dfs2(int x){
	vis[x]=1;
	for(auto i:v[x]){
		int y=dep[x]-dep[i]+1;
		if(y>k){
			puts("1");
			it=x;j=0;
			while(1){
				printf("%d ",it);j++;
				if(j==(k+1)/2){exit(0);}it=fa[fa[it]];
			}
		}
		if(vis[i]){continue;}
		dfs2(i);
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	memset(vis,0,sizeof(vis));
	dfs2(1);
	k=(k+1)/2;
	puts("1");
	if(m1>m0){
		for(i=1;i<=k;i++){printf("%d ",st1[i]);}
	}
	else{
		for(i=1;i<=k;i++){printf("%d ",st0[i]);}
	}
}