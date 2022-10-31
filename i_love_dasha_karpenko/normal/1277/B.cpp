#include <bits/stdc++.h>

using namespace std;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pp;
const ll DIM = 10E5+7;
const ll INF = 10E18+173;

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll n; cin>>n;
        set<ll> S;
        forn(i,n){
            ll x; cin>>x;
            if (x%2==0)S.insert(x);
        }
        auto it = S.rbegin();
        ll res = 0;
        while(it!=S.rend()){
            ll x = *it;
            S.erase(x);
            res++;
            if (x%4==0)S.insert(x/2);
        }
        cout<<res<<endl;

    }
    return 0;
}
// 5 4 1 2 3 4 5 2 1 3