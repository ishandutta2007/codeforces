#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mn=2e5+10;
ll a[mn];
ll ans=0x3f3f3f3f3f3f3f3f;
int n;
void kaka(ll x){
    ll pro=0;
    for(int i=0;i<n;i++){
        if(a[i]>=x)pro+=min(a[i]%x,x-a[i]%x);
        else pro+=x-a[i];
    }
    ans=min(ans,pro);
}
void hail(ll x){
    if(!x)return;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            kaka(i);
        }
        while(x%i==0)x/=i;
    }
    if(x!=1)kaka(x);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lld",a+i);
    for(int i=0;i<20;i++){
        int x=rng()%n;
        hail(a[x]-1);
        hail(a[x]);
        hail(a[x]+1);
    }
    printf("%lld",ans);
}