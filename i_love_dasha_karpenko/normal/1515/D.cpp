//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 2E5+100;
ll L[DIM],R[DIM];
void solve(){
    ll n,l,r;
    cin>>n>>l>>r;
    for(ll i = 1;i<=l;++i){
        ll x;
        cin>>x;
        L[x]++;
    }
    for(ll i = l+1;i<=n;++i){
        ll x;
        cin>>x;
        R[x]++;
    }
    for(ll i = 1;i<=n;++i){
        ll g = min(L[i],R[i]);
        L[i]-=g;
        R[i]-=g;
        l-=g;
        r-=g;
    }
    ll res = 0;
    ll sum = 0;
    for(ll i = 1;i<=n;++i){
        while (l<r && R[i]>=2){
            R[i]-=2;
            ++res;
            r-=2;
        }
        while(r<l && L[i]>=2){
            L[i]-=2;
            ++res;
            l-=2;
        }
        sum+=(L[i]+R[i]);
    }
    res+=abs(l-r)/2+sum/2;
    cout<<res<<endl;
    for(ll i = 1;i<=n;++i){
        L[i] = R[i] = 0;
    }

}
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}