#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int kpow(int x,ll y,int rex=1){
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
int n,m;
int sg[M],f[M];
vector<int>g[M],p[M];
set<int>s[M];
void dfs(int u){
    if(g[u].size()==0){
        p[u].eb(0);
        p[u].eb(sg[u]=1);
        s[u].insert(0);
        s[u].insert(sg[u]);
        return;
    }
    int mi=1e9;
    for(auto v:g[u]){
        dfs(v);
        if(mi>p[v].size())mi=min(mi,(int)p[v].size());
    }
    if(g[u].size()==1){
        swap(s[u],s[g[u][0]]);
        swap(p[u],p[g[u][0]]);
        sg[u]=sg[g[u][0]];
        while(s[u].count(sg[u]))sg[u]++;
        p[u].eb(sg[u]);
        s[u].insert(sg[u]);
        return;
    }
    p[u].resize(mi);
    for(auto v:g[u]){
        for(int S=p[v].size(),i=S-1;i>=S-mi;--i){
            p[u][i-(S-mi)]^=p[v][i];
        }
    }
    for(int i=0;i<mi;++i)s[u].insert(p[u][i]);
    sg[u]=0;
    while(s[u].count(sg[u]))sg[u]++;
    s[u].insert(sg[u]);
    p[u].eb(sg[u]);
}
void work(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)s[i].clear(),p[i].clear(),g[i].clear();
    for(int i=1;i<=n;++i){
        scanf("%d",&f[i]);
        g[f[i]].eb(i);
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        if(f[i]==0)dfs(i),ans^=sg[i];
    }
    puts(ans?"YES":"NO");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}
/*
4
0 1 1 2
*/