#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=3e5+10;
vector<ll>v;
int main(){
    ll l,r,k;
    scanf("%lld%lld%lld",&l,&r,&k);
    if(k==1){
        printf("%lld\n1\n%lld",l,l);
        return 0;
    }
    ll ans=0x3f3f3f3f3f3f3f3f;
    if(r-l>=2||l%2==0){
        ans=1;
    }
    if(k>=3){
        ll np=1LL<<64-__builtin_clzll(l);
        ll nx=np|(np>>1);
        if(nx<=r){
            printf("0\n3\n%lld %lld %lld",l,np+l-(np>>1),nx);
            return 0;
        }
    }
    if(k>=4&&(r-l>=4||(r-l>=3&&l%2==0))){
        if(l%2==1)l++;
        printf("0\n4\n%lld %lld %lld %lld",l,l+1,l+2,l+3);
        return 0;
    }
    if(ans==1){
        if(l%2==1)l++;
        printf("1\n2\n%lld %lld",l,l+1);
        return 0;
    }
    if(l==r||l<=(l^r))printf("%lld\n1\n%lld",l,l);
    else printf("%lld\n2\n%lld %lld",l^r,l,r);
}