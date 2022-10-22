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
const int M=2e5+9;
int n,m;
int b[10];
int dp[1<<10],p[1<<10];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        b[u]|=1<<v;
        b[v]|=1<<u;
    }
    int ans=0;
    dp[0]=1;
    for(int i=1;i<=n;++i){
        for(int s=0;s<1<<10;++s){
            for(int x=0;x<10;++x){
                int t=(s&b[x])|(1<<x);
                if((t&-t)>=1<<x){
                    p[t]=(p[t]+dp[s])%mod;
                }
            }
        }
        for(int s=0;s<1<<10;++s)dp[s]=p[s];
        memset(p,0,sizeof(p));
    }
    for(int s=0;s<1<<10;++s)ans=(ans+dp[s])%mod;
    printf("%d\n",ans);
    return 0;
}
/*
2
??
1
a

*/