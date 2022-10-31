//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 2E5+7;
const ll INF = 1E18;
const ll MOD = 1E9+7;
ll B[DIM];
void solve(){
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i)
        cin>>B[i];
    ll sum = 0;
    ll res = 1;
    map<ll,ll> M;

    ll pref = 0;
    for(ll i = 1;i<=n;++i){
        ll val =(sum-M[pref])%MOD;
        if (pref!=0)val++;
        res = (res+val)%MOD;
        M[pref]=(M[pref]+val)%MOD;
        sum = (sum+val)%MOD;
        pref+=B[i];
    }
    if (res<0)res+=MOD;
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