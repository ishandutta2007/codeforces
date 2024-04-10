#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 3E5+7;
const ll INF = 1E18;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n,d;
        cin>>n>>d;
        pair<ll,ll> mi = {INF,INF};
        ll mx = 0;
        for(ll i = 1;i<=n;++i){
            ll x;
            cin>>x;
            mx = max(mx,x);
            mi.second = min(mi.second,x);
            if (mi.first>mi.second)swap(mi.first,mi.second);
        }
        if (mi.first+mi.second<=d || mx<=d)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}