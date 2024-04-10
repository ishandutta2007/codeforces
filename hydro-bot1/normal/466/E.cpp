// Hydro submission #6194fa0f01410992b687b714@1637153295564
#include<bits/stdc++.h>
using namespace std;
const int N=150005,M=300005;
int fa[N],f[N][25],n,m,tot,ans[M],askcnt,id[M],rd[N],dep[N];
vector<int> e[N];
vector<pair<int,int> > vec[N];
struct question{int x,y,ff;}a[M];
void clear(int maxn){for(int i=1;i<=maxn;i++)fa[i]=i;}
int getanc(int k){return fa[k]==k?k:fa[k]=getanc(fa[k]);}
void dfs(int x,int fath){
    f[x][0]=fath;
    for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1];
    for(int y:e[x]){
        if(y==fath)continue;
        dep[y]=dep[x]+1;
        dfs(y,x);
    }
}
int Lca(int x,int y){
    if(dep[x]>dep[y])swap(x,y);
    for(int i=20;i>=0;i--)if(dep[f[y][i]]>=dep[x])y=f[y][i];
    if(x==y)return x;
    for(int i=20;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
    return f[x][0];
}
int main(){
    scanf("%d%d",&n,&m);
    clear(n);
    for(int i=1;i<=m;i++){
        int T,x,y;
        scanf("%d",&a[i].ff);
        T=a[i].ff;
        if(T==1){
            scanf("%d%d",&a[i].x,&a[i].y);
            x=a[i].x,y=a[i].y;
            e[y].push_back(x);
            e[x].push_back(y);
            rd[x]=1;
        }
        if(T==2){
            scanf("%d",&a[i].x),a[i].y=++tot;
        }
        if(T==3){
            scanf("%d%d",&x,&y);
            vec[y].push_back(make_pair(i,x));
        }
    }
    for(int i=1;i<=n;i++)if(!rd[i]){
            dep[i]=1;
            dfs(i,0);
        }
    for(int i=1;i<=m;i++){
        if(!ans[i])continue;
        if(Lca(a[i].x,a[i].y)==a[i].x)ans[i]=1;
        else ans[i]=0;
    }
    for(int i=1;i<=m;i++)
        if(a[i].ff==2){
            for(auto x:vec[a[i].y]){
                if(Lca(x.second,a[i].x)==x.second&&getanc(a[i].x)==getanc(x.second))ans[x.first]=1;
                else ans[x.first]=0;
            }
 
        }else if(a[i].ff==1){
            fa[getanc(a[i].x)]=getanc(a[i].y);
        }
    for(int i=1;i<=m;i++)if(a[i].ff==3)puts(ans[i]?"YES":"NO");
}