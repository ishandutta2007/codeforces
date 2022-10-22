#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<ll,ll>pll;
const int mn=3e5+10;
ll a[mn];
ll report(ll x){
    printf("%lld",x);
    exit(0);
}
ll ans=0;
ll kil=0;
ll n,m,k;
vector<pll>v;
void filt(){
    for(int i=0;i<n;i++){
        if(v.empty()||v.back().first!=a[i])v.push_back({a[i],1});
        else v.back().second++;
        if(v.back().second==k)v.pop_back(),kil+=k;
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>k>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    filt();
    int num=0;
    for(int i=0;i<v.size();i++){
        if(i==v.size()-1-i)break;
        if(v[i].first==v[v.size()-1-i].first&&v[i].second+v[v.size()-1-i].second>=k)num++;
        if(v[i].first==v[v.size()-1-i].first&&v[i].second+v[v.size()-1-i].second==k);
        else break;
    }
    ll len=0;
    for(pii p:v)len+=p.second;
    if(num==v.size()){
        if(m%2==0)report(0);
        else{
            report(len);
        }
    }
    else if(num*2+1==v.size()&&(num==0||v[num-1].second+v[num+1].second==k)){
        if(v[num].second*m%k==0)report(0);
        report(len-v[num].second+v[num].second*m%k);
    }
    else{
        assert(num*2<=v.size());
        report(len*m-k*num*(m-1));
    }
}