#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dep[100001],par[100001][17],dist[100001];
bool red[100001];
vector<int> g[100001];
#define SIZE 1000
int q[SIZE],w[SIZE];
void setup(int x,int p){
    dist[x]=dep[x];
    for(int y:g[x]){
        if(y==p)continue;
        dep[y]=dep[x]+1;
        par[y][0]=x;
        setup(y,x);
    }
}
void dfs(int x,int p){
    if(red[x])dist[x]=0;
    for(int y:g[x]){
        if(y==p)continue;
        dist[y]=min(dist[y],dist[x]+1);
        dfs(y,x);
        dist[x]=min(dist[x],dist[y]+1);
    }
}
int dis(int a,int b){
    int i,x,y;
    x=a,y=b;
    int dif=dep[a]-dep[b];
    if(dif>0)for(i=0;i<17;i++)if((dif>>i)&1)a=par[a][i];
    if(dif<0)for(dif=-dif,i=0;i<17;i++)if((dif>>i)&1)b=par[b][i];
    for(i=16;i>=0;i--)if(par[a][i]!=par[b][i])a=par[a][i],b=par[b][i];
    if(a==b)return dep[x]+dep[y]-2*dep[a];
    else return dep[x]+dep[y]-2*dep[a]+2;
}
int main(){
    int n,qq,i,j,k,a,b,ans;
    scanf("%d%d",&n,&qq);
    for(i=0;i<n-1;i++)scanf("%d%d",&a,&b),g[a].push_back(b),g[b].push_back(a);
    par[1][0]=1;
    setup(1,0);
    for(i=1;i<17;i++)for(j=1;j<=n;j++)par[j][i]=par[par[j][i-1]][i-1];
    for(i=0;i*SIZE<qq;i++){
        for(j=0;j<SIZE&&j+i*SIZE<qq;j++){
            dis(5,3);
            scanf("%d%d",q+j,w+j);
            if(q[j]==1){red[w[j]]=1;continue;}
            ans=dist[w[j]];
            for(k=0;k<j;k++){
                if(q[k]==2)continue;
                ans=min(ans,dis(w[j],w[k]));
            }
            printf("%d\n",ans);
        }
        dfs(1,0);
        dfs(1,0);
    }
}