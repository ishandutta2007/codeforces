#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
const ll DIM = 200000+7;
const ll INF = 10e16;
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define po(x) (1<<x)


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll n,mi = INF,mx = -INF;
        cin>>n;
        set<ll> S;
        forn(i,n){
            S.insert(i);
        }
        ll prev = -INF,flag = 0;
        vector<ll> ans;
        forn(i,n){
            ll x; cin>>x;
            if (x<i){
                flag = 1;

            }
            if (x!=prev){
                ans.pb(x);
                S.erase(x);
            }
            else{
                ans.pb(*S.begin());
                S.erase(S.begin());
            }
            prev = x;
        }
        if (flag){
            cout<<"-1"<<endl;
            continue;
        }
        for(ll i = 0;i<ans.size();i++){ll to = ans[i];cout<<to<<' ';}
        cout<<endl;
    }
    return 0;
}