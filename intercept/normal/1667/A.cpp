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
int n;
ll ans=1e18;
ll b[5009],a[5009];
void solve(int x){
    b[x]=0;
    ll sum=0;
    for(int i=x-1;i>=1;--i){
        b[i]=(b[i+1]/a[i]+1)*a[i];
        sum+=b[i+1]/a[i]+1;
    }
    for(int i=x+1;i<=n;++i){
        b[i]=(b[i-1]/a[i]+1)*a[i];
        sum+=b[i-1]/a[i]+1;
    }
    ans=min(ans,sum);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        solve(i);
    }
    cout<<ans;
    return 0;
}