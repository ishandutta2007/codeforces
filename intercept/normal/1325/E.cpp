#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int N=1e6+9;
int n,num,ans,tot;
int pri[N],vis[N],in[N],dis[N];
vector<int>g[N];
map<int,bool>mp;
void bfs(int s){
	queue<int>q;
	q.push(s);
	in[s]=tot;
	dis[s]=0;
	while(!q.empty()){ 
		int u=q.front();	
		q.pop();
		for(auto v:g[u]){
			if(in[v]!=tot)in[v]=tot,dis[v]=dis[u]+1,q.push(v);
			else if(dis[u]!=dis[v]+1)ans=min(ans,dis[u]+1+dis[v]);
		}
	}
}
int main(){
	for(int i=2;i<N;++i){
		if(!vis[i])vis[i]=pri[++num]=i;
		for(int j=1;j<=num&&1ll*pri[j]*i<N;++j){
			vis[pri[j]*i]=pri[j];
			if(i%pri[j]==0)break;
		}
	}
	scanf("%d",&n);
	ans=n+1;
	for(int i=1;i<=n;++i){
		int x,y=1;
		scanf("%d",&x);
		int z=sqrt(x);
		if(x==z*z){printf("1\n");return 0;}
		while(x!=1){
			if(vis[x/vis[x]]==vis[x])x/=vis[x];
			else y*=vis[x];
			x/=vis[x];
		}
		if(y==1){printf("1\n");return 0;}
		if(mp[y]){ans=2;}
		mp[y]=1;
		int a=vis[y],b=y/vis[y];
		g[a].eb(b);
		g[b].eb(a);
	}
	if(ans==2&&n!=1){
		printf("%d\n",ans);
		return 0;
	}
	for(int i=1;i<=1000;++i)tot++,bfs(i);
	if(ans==n+1)ans=-1;
	printf("%d\n",ans);
	return 0;
}