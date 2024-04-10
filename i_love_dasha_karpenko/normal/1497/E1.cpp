//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 2E5+7;

void solve(){
    ll n,k;
    cin>>n>>k;
    set<ll> S;
    ll res = 1;
    for(ll i = 1;i<=n;++i){
        ll need = 1;
        ll x;
        cin>>x;
        for(ll div = 2;div*div<=x;++div){
            if (x%div)continue;
            ll cnt = 0;
            while(x%div==0){
                x/=div;
                cnt^=1;
            }
            if (cnt)need*=div;
        }
        if (x!=1)need*=x;
        if (S.count(need)){
            ++res;
            S.clear();
        }
        S.insert(need);
    }
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}