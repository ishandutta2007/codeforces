#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

#define b(x) (1ull<<((x)-1))

int i,j,k,n,m,t,res,vis[100500],fa2[100500];
ll a[100500],w[100500],dep[100500],lg[100500],fa[100500][20],lim;
vector<int> v[100500];

int find(int x){return (x==fa2[x])?x:fa2[x]=find(fa2[x]);}

void dfs1(int x,int f){
	w[x]=w[f]+a[x];
	fa[x][0]=f;dep[x]=dep[f]+1;
	for(int i=1;i<=lg[dep[x]];i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(auto i:v[x]){
		if(i==f){continue;}
		dfs1(i,x);
	}
}

void add(int x,int y){
	int i,j,k;
	while(1){
		k=find(x);k=fa[k][0];
		if(dep[k]<dep[y]){return;}
		vis[k]=1;
		fa2[fa2[x]]=k;x=k;
	}
}

void dfs(int x){
	for(auto i:v[x]){
		dfs(i);
	}
	if(vis[x]){return;}
	
	int i,j,k,cur=x;
	res++;vis[x]=1;
	for(i=18;i>=0;i--){
		k=fa[cur][i];
		if(!k||w[x]-w[k]+a[k]>lim||dep[x]-dep[k]+1>m){
			continue;
		}
		cur=k;
	}
	//printf("a%d %d %d %d\n",x,vis[x],cur,w[x]);
	add(x,cur);
}

int main(){
	for(i=1;i<=100050;i++){lg[i]=lg[i>>1]+1;fa2[i]=i;}
	scanf("%d%d%lld",&n,&m,&lim);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>lim){puts("-1");return 0;}
	}
	for(i=2;i<=n;i++){
		scanf("%d",&k);v[k].push_back(i);
	}
	dfs1(1,0);
	dfs(1);
	printf("%d",res);
}