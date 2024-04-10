#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,cnt,ans,l,r,mid,u,v,cost,tot;
int Ans[1100000],num[1100000],que[1100000],deg[1100000],vis[1100000];
int edgenum,vet[2100000],Next[2100000],Head[1100000],val[2100000];
void addedge(int u,int v,int cost){
    vet[++edgenum]=v; val[edgenum]=cost;
    Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
inline bool check(int mid){
    memset(deg,0,sizeof(deg));
    memset(vis,0,sizeof(vis));
    tot=0;
	int head=1,tail=0;
    for (int i=1;i<=n;i++)
	    for (int e=Head[i];e;e=Next[e]){
	        if (val[e]<=mid) continue;
	        deg[vet[e]]++;
	    }
    for (int i=1;i<=n;i++)
		if (!deg[i]) que[++tail]=i;
    while (head<=tail){
    	int u=que[head++];
        num[u]=++tot; vis[u]=1;
        for (int e=Head[u];e;e=Next[e]){
            if (val[e]<=mid) continue;
            deg[vet[e]]--;
			if (!deg[vet[e]]) que[++tail]=vet[e];
        }
    }
    for (int i=1;i<=n;i++)
		if (!vis[i]) return false;
    cnt=0;
    for (int i=1;i<=n;i++)
    	for (int e=Head[i];e;e=Next[e])
			if (num[vet[e]]<num[i]&&val[e]<=mid) Ans[++cnt]=e;
    return true;
}
int main(){
	scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&cost);
        addedge(u,v,cost); r=max(r,cost);
    }
    while (l<=r){
        mid=(l+r)>>1;
        if (check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%d %d\n",ans,cnt);
    sort(Ans+1,Ans+cnt+1);
    for (int i=1;i<=cnt;i++) printf("%d ",Ans[i]);
    return 0;
}