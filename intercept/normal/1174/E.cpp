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
const int M=1000009;
int n;
int inv[M],fac[M];
int c(int x,int y){
    if(x<y||y<0)return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void pre(){
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<M;++i){
        fac[i]=1ll*fac[i-1]*i%mod;
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
    for(int i=2;i<M;++i)inv[i]=1ll*inv[i]*inv[i-1]%mod;
}
int p[M],num,ans=0;
void dfs(int x){
    if(x==1){
        int rex=1,a=0,b=0;
        for(int i=num;i>=1;--i){
            a=p[i];
            rex=1ll*fac[a]*rex%mod*(c(a+b,a)+mod-c(a+b-1,a))%mod;
            b+=a;
        }
        ans=(ans+rex)%mod;
        return;
    }
    if(x%2==0){
        p[++num]=n/(x/2)-n/x;
        dfs(x/2);
        num--;
    }
    if(x%3==0){
        p[++num]=n/(x/3)-n/x;
        dfs(x/3);
        num--;
    }
}
int main(){
    pre();
    cin>>n;
    int l=1;
    while(l<=n)l<<=1;
    l>>=1;
    int r=l/2*3;
    p[num=1]=1;
    dfs(l);
    p[num=1]=n/r;
    dfs(r);
    cout<<ans<<endl;
    return 0;
}
/*
8 2000
100 100 100 100 100 900 900 900
*/