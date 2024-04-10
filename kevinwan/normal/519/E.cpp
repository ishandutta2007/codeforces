#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dep[100001],par[100001][17],siz[100001];
vector<int> g[100001];
void dfs(int x,int p){
    siz[x]=1;
    for(int y:g[x]){
        if(y==p)continue;
        par[y][0]=x;
        dep[y]=dep[x]+1;
        dfs(y,x);
        siz[x]+=siz[y];
    }
}
int anc(int x,int y){
    for(int i=0;y;i++,y>>=1)if(y&1)x=par[x][i];
    return x;
}
int main(){
    int n,m,a,b,i,j,x,y,lca,dif,dist,mid;
    scanf("%d",&n);
    for(i=0;i<n-1;i++)scanf("%d%d",&a,&b),g[a].push_back(b),g[b].push_back(a);
    par[1][0]=1;
    dfs(1,0);
    for(i=1;i<17;i++)for(j=1;j<=n;j++)par[j][i]=par[par[j][i-1]][i-1];
    scanf("%d",&m);
    while(m--){
        scanf("%d%d",&a,&b);
        if(a==b){printf("%d\n",n);continue;}
        x=a,y=b;
        dif=dep[x]-dep[y];
        if(dif>0)x=anc(x,dif);
        else y=anc(y,-dif);
        for(i=16;i>=0;i--)if(par[x][i]!=par[y][i])x=par[x][i],y=par[y][i];
        if(x==y)lca=x;
        else lca=par[x][0];
        dist=dep[a]+dep[b]-2*dep[lca];
        if(dist&1){printf("0\n");continue;}
        if(dep[a]-dep[lca]==dist/2){
            printf("%d\n",siz[1]-siz[x]-siz[y]);
            continue;
        }
        if(dep[a]>dep[b]){
            mid=anc(a,dist/2);
            printf("%d\n",siz[mid]-siz[anc(a,dist/2-1)]);
        }
        else{
            mid=anc(b,dist/2);
            printf("%d\n",siz[mid]-siz[anc(b,dist/2-1)]);
        }
    }
}