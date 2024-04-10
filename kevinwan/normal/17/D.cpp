#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod=1e9+7;
const ll mn=1e6+10;
ll etot(ll x){
    ll ans=x;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            ans/=i,ans*=i-1;
            while(x%i==0)x/=i;
        }
    }
    if(x!=1)ans/=x,ans*=x-1;
    return ans;
}
ll t;
ll po(ll a,ll b,ll m){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=m)if(b&1)ans*=a,ans%=m;
    return ans;
}
ll gcd(ll a,ll b){
    while(b)a%=b,swap(a,b);
    return a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string b,n;
    ll c;
    cin>>b>>n>>c;
    t=etot(c);
    ll bc=0,nt=0,rn=0;
    for(char ch:b)bc*=10,bc+=ch-'0',bc%=c;
    for(char ch:n)nt*=10,nt+=ch-'0',nt%=t,rn*=10,rn+=ch-'0',rn=min((ll)3,rn);
    ll ans;
    if(rn<3){
        ans=po(bc,rn-1,c);
    }
    else{
        ll cc=c,fr=1;
        for(ll i=2;i*i<=cc;i++){
            if(cc%i==0){
                if(bc%i==0)while(cc%i==0)cc/=i,fr*=i;
                else while(cc%i==0)cc/=i;
            }
        }
        if(cc!=1){
            if(bc%cc==0)fr*=cc;
        }
        cc=c/fr;
        ll x=po(bc,nt-1+t,cc);
        ll tt=etot(cc);
        ans=x*fr%c*po(fr,tt-1,cc)%c;
    }
    ans*=bc-1,ans%=c;
    if(ans<=0)ans+=c;
    printf("%lld\n",ans);
}