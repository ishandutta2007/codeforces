#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int n,m,u[21000],v[21000],dis[11000],tot[11000],cnt[11000];
int edgenum,vet[21000],val[21000],Next[21000],Head[11000];
bool vis[11000];
queue<int> que;
void addedge(int u,int v,int cost){
    vet[++edgenum]=v; val[edgenum]=cost;
    Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
bool SPFA(int s){
	memset(dis,0x3f,sizeof(dis));
    dis[s]=0; que.push(s);
    while (!que.empty()){
        int u=que.front(); que.pop();
        if (cnt[u]>n) return false;
        cnt[u]++; vis[u]=false;
        for (int e=Head[u];e;e=Next[e]){
            int v=vet[e],cost=val[e];
            if (dis[v]>dis[u]+cost){
                dis[v]=dis[u]+cost;
                if (!vis[v]){
                    vis[v]=true;
                    que.push(v);
                }
            }
        }
    }
    return true;
}
void dfs1(int u){
    tot[u]++;
    if (u==n) return;
    for (int e=Head[u];e;e=Next[e])
        if (!tot[vet[e]]) dfs1(vet[e]); 
}
void dfs2(int u){
    tot[u]++;
    if (u==1) return;
    for (int e=Head[u];e;e=Next[e])
        if (tot[vet[e]]==1) dfs2(vet[e]); 
}

int main(){
	scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
        addedge(u[i],v[i],1);
    }
    dfs1(1);
    if (!tot[n]){
    	puts("No");
        return 0;
    }
    edgenum=0; memset(Head,0,sizeof(Head));
    for (int i=1;i<=m;i++) addedge(v[i],u[i],1);
    dfs2(n);
    edgenum=0; memset(Head,0,sizeof(Head));
    for (int i=1;i<=m;i++)
        if (tot[u[i]]==2&&tot[v[i]]==2) addedge(u[i],v[i],2),addedge(v[i],u[i],-1);
	if (SPFA(1)){
        puts("Yes");
        for (int i=1;i<=m;i++){
            if (tot[u[i]]==2&&tot[v[i]]==2) printf("%d\n",dis[v[i]]-dis[u[i]]);
            else puts("1");
        }
    }
	else puts("No");
    return 0;
}