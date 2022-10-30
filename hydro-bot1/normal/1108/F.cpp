// Hydro submission #61970ae4d28d95852ab3535f@1637288677094
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m,dep[N],f[N][30],g[N][30],fa[N],b[N];
struct Edge{int x,y,z;}a[N];
vector<pair<int,int> > e[N];
int getanc(int k){return fa[k]==k?k:fa[k]=getanc(fa[k]);}
void dfs(int x,int fath){
    f[x][0]=fath;
    for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1],g[x][i]=max(g[x][i-1],g[f[x][i-1]][i-1]);
    for(auto i:e[x]){
        int y=i.first,z=i.second;
        if(y==fath) continue;
        dep[y]=dep[x]+1;
        g[y][0]=z;
        dfs(y,x);
    }
}
int get(int x,int y){
    int ans=0;
    if(dep[x]<dep[y])swap(x,y);
    for(int i=20;i>=0;i--)if(dep[f[x][i]]>=dep[y])ans=max(ans,g[x][i]),x=f[x][i];
    if(x==y)return ans;
    for(int i=20;i>=0;i--)if(f[x][i]!=f[y][i])ans=max(ans,max(g[x][i],g[y][i])),x=f[x][i],y=f[y][i];
    return max(ans,max(g[x][0],g[y][0]));
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
    sort(a+1,a+m+1,[](Edge a,Edge b){return a.z<b.z;});
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int fx=getanc(a[i].x),fy=getanc(a[i].y);
        if(fx!=fy){
            b[i]=1;
            fa[fx]=fy;
            e[a[i].x].emplace_back(a[i].y,a[i].z);
            e[a[i].y].emplace_back(a[i].x,a[i].z);
        }
    }
    dfs(1,0);
    int ans=0;
    for(int i=1;i<=m;i++){
        if(b[i])continue;
        if(a[i].z==get(a[i].x,a[i].y))ans++;
    }
    printf("%d",ans);
    return 0;
}