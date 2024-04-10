#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#define N 100005
#define inf 314000000
using namespace std;
int n,m;
int dis[N];
int unc[N],curd[N]={0};
int id[N];
vector<int> nex[N];
vector<int> up[N];
vector<int> go[N];
struct node{
	int u,d;
	int operator<(const node&b)const{
		return d>b.d;
	}
};
priority_queue<node> qu;
int vis[N]={0};

int ma[N];
void dfs(int u){
	if(vis[u]==2)return;
	if(vis[u]==1){
		ma[u]=-2;
		return;
	}
	vis[u]=1;
	int a=0;
	for (int i=0;i<go[u].size();i++){
		int x=go[u][i];
		int bo=0;
		int cur=0;
		for (int j=0;j<nex[x].size();j++)if(nex[x][j]!=-1 && dis[nex[x][j]]==-1){bo=1;break;}
		if(bo)continue;
		for (int j=0;j<nex[x].size();j++)if(nex[x][j]!=-1){
			dfs(nex[x][j]);
			if(ma[nex[x][j]]==-2){
				cur=-2;
				break;
			}else {
				cur+=ma[nex[x][j]];
				if(cur>inf)cur=inf;
			}
		}else {
			cur++;
			if(cur>inf)cur=inf;
		}
		if(cur==-2){
			a=-2;break;
		}else a=max(a,cur);
	}
	ma[u]=a;
	vis[u]=2;
}
int main()
{
	scanf("%d%d",&m,&n);
	memset(dis,-1,sizeof(dis));
	for (int i=1;i<=m;i++){
		scanf("%d",&id[i]);
		go[id[i]].push_back(i);
		int sz;scanf("%d",&sz);
		while(sz--){
			int x;scanf("%d",&x);
			nex[i].push_back(x);
			if(x!=-1){
				unc[i]++;
				up[x].push_back(i);
			}
			else curd[i]++;
		}
		if(!unc[i]){
			qu.push((node){i,curd[i]});
		}
	}
	while(!qu.empty()){
		node x=qu.top();qu.pop();
		int u=x.u;if(curd[u]!=x.d)continue;
		if(dis[id[u]]==-1 || curd[u]<dis[id[u]]){
			for (int i=0;i<up[id[u]].size();i++){
				int v=up[id[u]][i];
				if(dis[id[u]]==-1){
					unc[v]--;
					curd[v]+=curd[u];
				}else{
					curd[v]-=(dis[id[u]]-curd[u]);
				}
				if(curd[v]>inf)curd[v]=inf;
				if(unc[v]==0){
					qu.push((node){v,curd[v]});
				}
			}
			dis[id[u]]=curd[u];
		}
	}
	for (int i=1;i<=n;i++)if(dis[i]!=-1)
		dfs(i);
	for (int i=1;i<=n;i++){
		if(dis[i]==-1)printf("-1 -1\n");
		else printf("%d %d\n",dis[i],ma[i]);
	}
	return 0;
}