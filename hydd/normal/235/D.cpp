#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,rt,bel[3100],dis[3100];
int cnt,q[3100],num[3100],fa[3100];
bool flag,vis[3100];
int edgenum,vet[6100],Next[6100],Head[3100];
double ans;
void addedge(int u,int v){
    vet[++edgenum]=v;
    Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void getcycle(int u){
    vis[u]=true;
    for(int e=Head[u];e;e=Next[e]){
        int v=vet[e];
        if (v==fa[u]) continue;
        if (vis[v]){
            if (!flag){
                flag=true;
                int t=u;
                while (t!=v){
                    q[++cnt]=t; num[t]=cnt;
                    t=fa[t];
                }
                q[++cnt]=v; num[v]=cnt;
            }
        }
        else fa[v]=u,getcycle(v);
    }
}
void dfs(int u){
	bel[u]=rt; vis[u]=true;
	for (int e=Head[u];e;e=Next[e])
		if (!vis[vet[e]]){
			dis[vet[e]]=dis[u]+1;
			dfs(vet[e]);
		}
}
void solve(int u,int dep){
	vis[u]=true;
	if (u!=rt){
		if (bel[u]==bel[rt]) ans+=1.0/dep;
		else{
			int a=dis[rt]+dis[u],b=abs(num[bel[u]]-num[bel[rt]])-1,c=cnt-2-b;
			ans+=1.0/(a+b)+1.0/(a+c)-1.0/(a+b+c);
		}
	}
	for (int e=Head[u];e;e=Next[e])
		if (!vis[vet[e]]) solve(vet[e],dep+1);
}
int main(){
	scanf("%d",&n); int u,v;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&u,&v); u++; v++;
		addedge(u,v); addedge(v,u);
	}
	getcycle(1);
    for (int i=1;i<=cnt;i++){
    	for (int j=1;j<=n;j++) vis[j]=(num[j]!=0);
        rt=q[i]; dis[q[i]]=1; dfs(q[i]);
    }
    for (int i=1;i<=n;i++){
        memset(vis,false,sizeof(vis));
        rt=i; solve(i,1);
    }
    ans+=n;
    printf("%.10lf\n",ans);
    return 0;
}