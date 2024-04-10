#include <bits/stdc++.h>
using namespace std;
const int mn=1e6+10;
vector<vector<int>>t;
int val[mn];
bool comp(const int&a,const int&b){
    return val[a]>val[b];
}
int p[mn];
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
vector<int>g[mn],gg[mn];
int o[mn],dep[mn];
bool vis[mn];
void dfs(int x){
    dep[x]=vis[x]=1;
    for(int y:gg[x]){
        if(!vis[y])dfs(y);
        dep[x]=max(dep[x],dep[y]+1);
    }
}
int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    t.resize(n);
    for(i=0;i<n;i++){
        t[i].resize(m);
        for(j=0;j<m;j++)scanf("%d",&t[i][j]);
    }
    iota(p,p+mn,0);
    for(i=0;i<n;i++){
        iota(o,o+m,0);
        for(j=0;j<m;j++)val[j]=t[i][j];
        sort(o,o+m,comp);
        for(j=0;j<m-1;j++){
            if(val[o[j]]==val[o[j+1]])p[f(i*m+o[j])]=f(i*m+o[j+1]);
            else g[f(i*m+o[j])].push_back(i*m+o[j+1]);
        }
    }
    for(i=0;i<m;i++){
        iota(o,o+n,0);
        for(j=0;j<n;j++)val[j]=t[j][i];
        sort(o,o+n,comp);
        for(j=0;j<n-1;j++){
            if(val[o[j]]==val[o[j+1]])p[f(o[j]*m+i)]=f(o[j+1]*m+i);
            else g[o[j]*m+i].push_back(o[j+1]*m+i);
        }
    }
    for(i=0;i<m*n;i++)for(int j:g[i])gg[f(i)].push_back(f(j));
    for(i=0;i<m*n;i++)if(!vis[i])dfs(i);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)printf("%d ",dep[f(i*m+j)]);
        printf("\n");
    }
}