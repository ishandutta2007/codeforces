#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9+7;
const ll inf = 0x3f3f3f3f3f3f3f3f;

pair<ll,ll> a[N];
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    return a.first>b.first;
}

int main(){
    ios::sync_with_stdio(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans=0;
        for(ll i=1;i<=n;i++) {
            cin>>a[i].first;
            ans+=a[i].first;
            a[i].second=-1;
        }
        for(ll i=1;i<n;i++){
            ll aa,bb;
            cin>>aa>>bb;
            a[aa].second++;
            a[bb].second++;
        }
        sort(a+1,a+1+n,cmp);
        vector<ll> v;
        v.push_back(ans);
        ll p=1;
        for(ll i=2;i<n;i++){
            while(a[p].second==0) p++;
            ans+=a[p].first;
            a[p].second--;
            v.push_back(ans);
        }
        for(auto x:v) cout<<x<<' ';
        cout<<endl;
    }
}