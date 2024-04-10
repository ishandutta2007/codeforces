#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1e6+10;
const ll mod=1e9+7;
int h[mn];
ll pr=0;
void solve(int l,int r){
    if(r<l)return;
    ll ans=0,lv=0,rv=0;
    int m=(l+r)>>1;
    ans=h[m];
    ll cur=1;
    for(int i=m+1;i<=r;i++){
        rv+=cur*min(h[i-1],h[i]),rv%=mod;
        if(i)cur*=min(min(h[i-1],h[i]),h[i+1]),cur%=mod;
    }
    cur=1;
    for(int i=m-1;i>=l;i--){
        lv+=cur*min(h[i+1],h[i]),lv%=mod;
        if(i)cur*=min(min(h[i-1],h[i]),h[i+1]),cur%=mod;
    }
    if(m)ans+=min(min(h[m-1],h[m]),h[m+1])*lv%mod*rv%mod,ans%=mod;
    ans+=min(h[m],h[m+1])*rv,ans%=mod;
    if(m)ans+=min(h[m],h[m-1])*lv,ans%=mod;
    pr+=ans,pr%=mod;
    if(l!=r){
        solve(l,m-1);
        solve(m+1,r);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",h+i),h[i]--;
    solve(0,n-1);
    printf("%lld",pr);
}