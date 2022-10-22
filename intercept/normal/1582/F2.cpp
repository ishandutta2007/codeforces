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
const int M=5009;
const int S=1<<13;
int n;
vector<int>g[M];
set<int>s;
int dp[M<<1];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int x;
        scanf("%d",&x);
        g[x].eb(i);
    }
    for(int i=1;i<S;++i)dp[i]=n+1;
    for(int i=0;i<=5000;++i){
        s.clear();
        s.insert(n+1);
        for(auto o:g[i]){
            dp[i]=min(dp[i],o);
            s.insert(o);
        }
        for(int x=1;x<S;++x){
            int y=x^i;
            if(dp[x]>dp[y]){
                int t=*s.lower_bound(dp[y]);
                dp[x]=min(dp[x],t);
            }
        }
    }
    int ans=0;
    for(int i=0;i<S;++i){
        ans+=dp[i]<=n;
    }
    printf("%d\n",ans);
    for(int i=0;i<S;++i){
        if(dp[i]<=n)printf("%d ",i);
    }
    return 0;
}