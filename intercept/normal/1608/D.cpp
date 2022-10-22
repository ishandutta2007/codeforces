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
int n;
char s[M][2];
int main(){
    cin>>n;
    int wb=1,bw=1,w=0,b=0;
    for(int i=1;i<=n;++i){
        cin>>s[i];
        if(s[i][0]=='B'||s[i][1]=='W')wb=0;
        if(s[i][0]=='W'||s[i][1]=='B')bw=0;
        for(int o=0;o<2;++o){
            if(s[i][o]=='B')b++;
            if(s[i][o]=='W')w++;
        }
    }
    pre();
    int ans=c(n*2-w-b,n-w),rex=1;
    for(int i=1;i<=n;++i){
        if(s[i][0]=='B'&&s[i][1]=='B')rex=0;
        if(s[i][0]=='W'&&s[i][1]=='W')rex=0;
        if(s[i][0]=='?'&&s[i][1]=='?')rex=2ll*rex%mod;
    }
    rex=rex-wb-bw;
    ans=(ans+mod-rex)%mod;
    cout<<ans<<endl;
    return 0;
}