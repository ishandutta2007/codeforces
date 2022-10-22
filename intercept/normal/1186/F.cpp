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
const int M=1000009;
int n,m;
int f[M];
set<int>g[M],e[M];
int t[M<<1],s[M<<1];
void push(int x,int y,int *T){
    for(T[x+=n-1]=y;x;x>>=1)T[x>>1]=f[T[x]]>f[T[x^1]]?T[x]:T[x^1];
}
int main(){
    scanf("%d%d",&n,&m);
    int k=m;
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].insert(v);
        g[v].insert(u);
    }
    for(int i=1;i<=n;++i)f[i]=g[i].size()/2,push(i,i,t);
    while(1){
        int u=t[1];
        if(f[u]==0)break;
        push(u,0,t);
        for(auto v:g[u]){
            push(v,v,s);
        }
        while(1){
            int v=s[1];
            if(f[v]==0||f[u]==0)break;
            k--;
            f[v]--;
            push(v,v,t);
            push(v,0,s);
            f[u]--;
            e[u].insert(v);
            e[v].insert(u);
        }
        for(auto v:g[u]){
            push(v,0,s);
        }
        f[u]=0;
    }
    printf("%d\n",k);

    for(int u=1;u<=n;++u){
        for(auto o:e[u]){
            g[u].erase(o);
        }
        for(auto v:g[u]){
            if(v>u)printf("%d %d\n",u,v);
        }
    }
    return 0;
}
/*

1
5
5 4 3 2 1

*/