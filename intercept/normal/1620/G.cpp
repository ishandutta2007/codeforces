#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
int kpow(int x,int y,int rex=0){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
int n,m;
int b[23][26];
int p[1<<23][26],dp[1<<23];
char s[20009];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%s",s);
        m=strlen(s);
        for(int j=0;j<m;++j){
            b[i][s[j]-'a']++;
        }
    }
    for(int i=0;i<26;++i)p[0][i]=2e4;
    for(int i=1;i<1<<n;++i){
        int j=i-(i&-i),k=__builtin_ctz(i);
        for(int t=0;t<26;++t)p[i][t]=min(p[j][t],b[k][t]);
        int sum=1;
        for(int t=0;t<26;++t)sum=1ll*sum*(p[i][t]+1)%mod;
        dp[i]=(__builtin_parity(i)?1ll:(1ll*mod-1))*sum%mod;
    }
    for(int j=0;j<n;++j){
        for(int i=1;i<1<<n;++i){
            if(i>>j&1)dp[i]=(dp[i]+dp[i^(1<<j)])%mod;
        }
    }
    ll ans=0;
    for(int i=1;i<1<<n;++i){
        int k=__builtin_popcount(i),t=0;
        for(int j=0;j<n;++j){
            if(i>>j&1)t+=j+1;
        }
        ans^=1ll*k*t*dp[i];
    }
    printf("%lld\n",ans);
    return 0;
}