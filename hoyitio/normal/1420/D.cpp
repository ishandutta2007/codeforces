
#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
    int l,r;
};
bool cmp(point a,point b){
    return a.l<b.l;
}
bool cmp2(point a,point b){
    return a.r<b.r;
}
ll a[333333],b[333333],dp[333333];
int mod=998244353;
ll power(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
ll inv(ll x){
    return power(x,mod-2);
}
long long f(long long x,int k){
    if(x<k)return 0;
    return dp[x];
}
int main(){
    ll n,i,j=0,t,k,low=1;

    cin>>n>>k;
     dp[k-1]=1;
    for(i=k;i<=3e5;i++){
        dp[i]=dp[i-1];
        dp[i]=dp[i]*i%mod*inv(low)%mod;
        low++;
    }
  //  for(i=2;i<=10;i++)cout<<i<<" "<<dp[i]<<endl;
    for(i=0;i<n;i++)cin>>a[i]>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    long long cnt=0,res=0;
    for(i=0;i<n;i++){
        cnt++;
        while(j<n&&b[j]<a[i]){
            j++,cnt--;
        }
       // cout<<cnt<<endl;
        res+=f(cnt-1,k-1);
        res%=mod;
    }
    cout<<res;

}