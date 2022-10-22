#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=3e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll seed;
ll rnd(){
    ll ret=seed;
    seed=(seed*7+13)%mod;
    return ret;
}
ll a[mn];
ll po(ll a,ll b,ll m){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=m)if(b&1)ans*=a,ans%=m;
    return ans;
}
int main(){
    int n,m,vm;
    scanf("%d%d%lld%d",&n,&m,&seed,&vm);
    for(int i=1;i<=n;i++)a[i]=rnd()%vm+1;
    map<ll,ll>s;
    for(int i=1;i<=n;i++)s.insert({i,a[i]});
    while(m--){
        ll op=rnd()%4+1;
        ll l=rnd()%n+1,r=rnd()%n+1;
        if(l>r)swap(l,r);
        ll x,y;
        if(op==3)x=rnd()%(r-l+1)+1;
        else x=rnd()%vm+1;
        if(op==4)y=rnd()%vm+1;
        r++;
        auto st=--s.lower_bound(l+1);
        if(st->first!=l)st=s.insert({l,st->second}).first;
        auto en=--s.lower_bound(r+1);
        if(en->first!=r)en=s.insert({r,en->second}).first;
        if(op==1){
            for(auto it=st;it!=en;++it)it->second+=x;
        }
        else if(op==2){
            st->second=x;
            st++;
            for(auto it=st;it!=en;it=s.erase(it));
        }
        else if(op==3){
            vector<pll>v;
            ll lst=-1;
            for(auto it=st;it!=en;++it){
                if(lst!=-1)v.back().second=it->first-lst;
                v.push_back({it->second,0LL});
                lst=it->first;
            }
            v.back().second=en->first-lst;
            sort(v.begin(),v.end());
            ll cnt=0;
            for(pll p:v){
                cnt+=p.second;
                if(cnt>=x){
                    printf("%lld\n",p.first);
                    break;
                }
            }
        }
        else{
            vector<pll>v;
            ll lst=-1;
            for(auto it=st;it!=en;++it){
                if(lst!=-1)v.back().second=it->first-lst;
                v.push_back({po(it->second%y,x,y),0LL});
                lst=it->first;
            }
            v.back().second=en->first-lst;
            ll ans=0;
            for(pll p:v)ans+=1LL*p.first*p.second,ans%=y;
            printf("%lld\n",ans);
        }
    }
}