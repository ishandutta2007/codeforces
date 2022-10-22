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
int n,k;
ll pre[M][2],suf[M][2];
ll a[M];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
    for(int i=1;i<=n;++i){
        pre[i][0]=pre[i-1][0]+(a[i]?a[i]:-k);
        pre[i][1]=pre[i-1][1]+(a[i]?a[i]:k);
    }
    for(int i=n;i>=1;--i){
        suf[i][0]=suf[i+1][0]+(a[i]?a[i]:-k);
        suf[i][1]=suf[i+1][1]+(a[i]?a[i]:k);
    }
    if(pre[n][0]>0||pre[n][1]<0){
        puts("-1");
        return 0;
    }
    ll mi=1ll<<60,ma=-1ll<<60,ans=0;
    if(pre[n][0]==0){
        for(int i=1;i<=n;++i){
            ma=max(ma,pre[i][0]);
            mi=min(ma,pre[i][0]);
        }
        ans=max(ans,ma-mi);
    }
    for(int i=1;i<=n;++i){
        ll l=0,r=0;
        for(int j=i;j<=n;++j){
            if(a[j])l+=a[j],r+=a[j];
            else{
                l-=k;
                r+=k;
            }
            ll L=-pre[i-1][1]-suf[j+1][1];
            ll R=-pre[i-1][0]-suf[j+1][0];
            ll pl=max(l,L),pr=min(r,R);
            if(pl<=pr)ans=max({ans,abs(pl),abs(pr)});
        }
    }
    printf("%lld\n",ans+1);
    return 0;
}
/*
1
2
*.
..
*/