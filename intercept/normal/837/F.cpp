#include<bits/stdc++.h>
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
#define ll long long
#define i128 __int128_t
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
const int M=2e5+9;
int n;
ll m;
int a[M];
i128 b[M];
bool check(ll k){
    b[0]=1;
    for(int i=1;i<n;++i){
        if(b[i-1]>0)b[i]=b[i-1]*(k-1+i)/i;
        else b[i]=-1;
        if(b[i]>1e18)b[i]=-1;
    }
    i128 ma=0;
    for(int i=0;i<n;++i){
        ma+=b[i]*a[n-1-i];
        if(ma>=m||(b[i]==-1&&a[n-1-i]))return 1;
    }
    return 0;
}
int main(){
    scanf("%d%lld",&n,&m);
    for(int i=0;i<n;++i)scanf("%d",&a[i]);
    for(int i=0;i<n;++i){
        if(a[i]>=m){
            puts("0");
            return 0;
        }
    }
    ll l=1,r=1e18;
    while(l<r){
        ll mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    printf("%lld\n",l);
    return 0;
}
/*
2 2
11

*/