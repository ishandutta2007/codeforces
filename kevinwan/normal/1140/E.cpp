#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int mn=2e5+10;
int a[mn],m;
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
ll hail(ll a,int b){
    if(a==0){
        if(b==3)return 0;
        return 1;
    }
    if(b==0)return m*po(m-1,a-1);
    else if(b==1)return po(m-1,a);
    else if(b==2)return (po(m-1,a)-((a&1)?-1:1))*po(m)%mod*(m-1)%mod+((a&1)?-1:1);
    else return (po(m-1,a)-((a&1)?-1:1))*po(m)%mod*(m-1)%mod;
}
int main(){
    int n;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    int ln=0,i;
    ll ans=1;
    for(i=0;i<n;i+=2){
        if(a[i]!=-1){
            if(ln==0)ans*=hail((i-ln)/2,1);
            else if(a[i]==a[ln-2])ans*=hail((i-ln)/2,3);
            else ans*=hail((i-ln)/2,2);
            ans%=mod;
            ln=i+2;
        }
    }
    if(ln==0)ans*=hail((i-ln)/2,0);
    else ans*=hail((i-ln)/2,1);
    ans%=mod;
    ln=1;
    for(i=1;i<n;i+=2){
        if(a[i]!=-1){
            if(ln==1)ans*=hail((i-ln)/2,1);
            else if(a[i]==a[ln-2])ans*=hail((i-ln)/2,3);
            else ans*=hail((i-ln)/2,2);
            ans%=mod;
            ln=i+2;
        }
    }
    if(ln==1)ans*=hail((i-ln)/2,0);
    else ans*=hail((i-ln)/2,1);
    ans%=mod;
    printf("%lld",ans);
}