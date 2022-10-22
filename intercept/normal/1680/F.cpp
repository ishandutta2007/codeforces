#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
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
const int M=1e6+9;
int n,m,flag=0;
vector<int>g[M];
int ans[M],vis[M],dep[M],in[M],s[M],top=0;
int x,y,l;
int cnt[M][2];
void dfs(int u){
    vis[u]=1;
    for(auto v:g[u]){
        if(vis[v]){
            if(dep[v]<dep[u]-1){
                int o=(dep[u]-dep[v])%2;
                cnt[u][o]++;
                cnt[v][o]--;
                if(o==0)x=u,y=v,flag++;
            }
        }  
        else dep[v]=dep[u]+1,dfs(v),cnt[u][0]+=cnt[v][0],cnt[u][1]+=cnt[v][1];
    }
}
void solve(int u){
    vis[u]=1;
    for(auto v:g[u]){
        if(!vis[v]){
            if(v==y)ans[v]=1;
            else ans[v]=ans[u]^1;
            solve(v);
        }
    }
}
bool pd(){
    for(int i=1;i<=n;++i)vis[i]=0;
    ans[x]=1;
    solve(x);
    int sum=0;
    for(int u=1;u<=n;++u){
        for(auto v:g[u]){
            if(ans[u]==ans[v]&&v>u){
                if(ans[u]==0)return 0;
                else sum++;
                if(sum>1)return 0;
            }
        }
    }
    return 1;
}
void pfs(int u,int fa){
    vis[u]=1;
    if(cnt[u][1]==0&&cnt[u][0]==flag)x=u,y=fa;
    for(auto v:g[u]){
        if(!vis[v])pfs(v,u);
    }
}
void work(){
    x=y=1;
    flag=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)g[i].clear(),vis[i]=cnt[i][0]=cnt[i][1]=0;
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].eb(v);
        g[v].eb(u);
    }
    dfs(1);
    if(pd()){
        puts("YES");
        for(int i=1;i<=n;++i)putchar(ans[i]?'1':'0');
        puts("");
        return;
    }
    else{
        for(int i=1;i<=n;++i)vis[i]=0;
        pfs(1,0);
        if(pd()){
            puts("YES");
            for(int i=1;i<=n;++i)putchar(ans[i]?'1':'0');
            puts("");
            return;
        }
    }
    puts("NO");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}
/*
1
4 5
1 2
2 3
3 4
1 3
2 4
*/