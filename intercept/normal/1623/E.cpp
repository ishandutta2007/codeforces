#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=2e5+9;
int n,k,num;
int c[M][2],f[M],id[M],va[M],fa[M][20],dep[M],p[M],vis[M];
char s[M];
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
int get(int u){
    for(int i=18;i>=0;--i){
        if(!p[fa[u][i]])u=fa[u][i];
    }
    return fa[u][0];
}
void dfs(int u){
    for(int i=1;i<=18;++i)fa[u][i]=fa[fa[u][i-1]][i-1];
    if(c[u][0])fa[c[u][0]][0]=u,dfs(c[u][0]);
    id[++num]=u;
    va[num]=s[u]-'a';
    if(c[u][1])fa[c[u][1]][0]=u,dfs(c[u][1]);
}
void solve(int u,int lf,int deep){
    dep[u]=deep;
    if(c[u][0])solve(c[u][0],lf,deep+1);
    int ff=get(u);
    if(vis[find(u)]&&p[lf]&&dep[u]-dep[ff]<=k){
        int x=u;
        while(!p[x]){
            p[x]=1;
            k--;
            x=fa[x][0];
        }
    }
    if(c[u][1])solve(c[u][1],u,deep+1);
}
int main(){
    scanf("%d%d%s",&n,&k,s+1);
    for(int i=1;i<=n;++i){
        f[i]=i;
        int u,v;
        scanf("%d%d",&u,&v);
        c[i][0]=u;
        c[i][1]=v;
    }
    dfs(1);
    for(int i=2;i<=num;++i){
        if(va[i]==va[i-1]){
            int x=find(id[i]),y=find(id[i-1]);
            if(x!=y)f[x]=y;
        }
        else{
            if(va[i]>va[i-1]){
                vis[find(id[i-1])]=1;
            }
        }
    }
    p[0]=1;
    solve(1,0,1);
    for(int i=1;i<=num;++i){
        putchar(va[i]+'a');
        if(p[id[i]])putchar(va[i]+'a');
    }
    return 0;
}