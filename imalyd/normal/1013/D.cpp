#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,q,vx[N],vy[N],ans,vis[N];
vector<int>e[N];
struct node{int x,y,id;}nod[N];
bool cmpx(node x,node y){return x.x<y.x;}
bool cmpy(node x,node y){return x.y<y.y;}
bool cmpid(node x,node y){return x.id<y.id;}
void addedge(node x,node y){
	e[x.id].push_back(y.id);
	e[y.id].push_back(x.id);
}
void dfs(int v){
	if(vis[v])return;
	vx[nod[v].x]=vy[nod[v].y]=vis[v]=1;
	for(int i=0;i<(int)e[v].size();i++)dfs(e[v][i]);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<q;i++)nod[i].id=i,scanf("%d%d",&nod[i].x,&nod[i].y);
	sort(nod,nod+q,cmpx);
	for(int i=1;i<q;i++)if(nod[i].x==nod[i-1].x)addedge(nod[i],nod[i-1]);
	sort(nod,nod+q,cmpy);
	for(int i=1;i<q;i++)if(nod[i].y==nod[i-1].y)addedge(nod[i],nod[i-1]);
	sort(nod,nod+q,cmpid);
	/*for(int i=0;i<q;i++){
		printf("%d: ",i);
		for(int j=0;j<(int)e[i].size();j++)printf("%d ",e[i][j]);
		printf("\n");
	}*/
	for(int i=0;i<q;i++)if(!vis[i])++ans,dfs(i);
	ans=max(0,ans-1);
	int cx=0;
	for(int i=1;i<=n;i++)if(!vx[i])++cx;
	for(int i=1;i<=m;i++)if(!vy[i])++cx;
	ans+=cx;if(cx==n+m)--ans;
	printf("%d",ans);
	return 0;
}