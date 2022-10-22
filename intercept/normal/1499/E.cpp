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
const int M=1e3+9;
int n,m,ans;
int dp[M][M][2],ps[M],pt[M];
char s[M],t[M];
void add(int &x,int y){
    x+=y;
    if(x>=mod)x-=mod;
}
int main(){
    cin>>(s+1)>>(t+1);
    n=strlen(s+1);
    m=strlen(t+1);
    for(int i=1;i<=n;++i){
        ps[i]=1;
        if(s[i]!=s[i-1])add(ps[i],ps[i-1]);
    }
    for(int i=1;i<=m;++i){
        pt[i]=1;
        if(t[i]!=t[i-1])add(pt[i],pt[i-1]);
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(s[i]!=s[i-1])add(dp[i][j][0],dp[i-1][j][0]);
            if(s[i]!=t[j])add(dp[i][j][0],dp[i-1][j][1]);
            if(s[i]!=t[j])add(dp[i][j][1],dp[i][j-1][0]);
            if(t[j]!=t[j-1])add(dp[i][j][1],dp[i][j-1][1]);
            if(s[i]!=t[j]){
                add(dp[i][j][0],pt[j]);
                add(dp[i][j][1],ps[i]);
            }
            add(ans,dp[i][j][0]);
            add(ans,dp[i][j][1]);
        }
    }


    cout<<ans<<endl;
    return 0;
}
/*
a
a
*/