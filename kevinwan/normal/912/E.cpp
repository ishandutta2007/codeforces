#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
typedef long long ll;
const int mn=2e5+10;
ll p[mn];
int n;
ll inf=((ll)1e9)*((ll)1e9);
vector<ll>a={1},b={1},t;
ll solve(ll x){
    ll ans=0;
    for(ll i:b)ans+=upper_bound(a.begin(),a.end(),x/i)-a.begin();
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lld",p+i);
    ll k;
    scanf("%lld",&k);
    for(int i=0;i<n/2;i++){
        t.clear();
        for(ll x:a){
            for(ll j=1;x<=inf/j;j*=p[i])t.push_back(j*x);
        }
        a=t;
    }
    for(int i=n/2;i<n;i++){
        t.clear();
        for(ll x:b){
            for(ll j=1;x<=inf/j;j*=p[i])t.push_back(j*x);
        }
        b=t;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll cur=0;
    for(ll i=1LL<<59;i;i>>=1)if(solve(cur+i)<k)cur+=i;
    printf("%lld",cur+1);
}