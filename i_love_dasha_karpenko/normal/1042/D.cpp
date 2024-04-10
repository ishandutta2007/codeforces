#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>, rb_tree_tag,tree_order_statistics_node_update> satan_set;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
#define x1 dsfdsf
#define y1 fgdfgdfg
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 200000+7;
const ld INF = 10e16;
const ll MOD = 998244353 ;
const ll MAXN = 107;
ll n,t;
satan_set S;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>t;
    ll pref = 0;
    S.insert({pref,0});
    ll res = 0;
    //cout<<S.order_of_key(1)<<endl;
    forn(i,n){
        ll x; cin>>x;
        pref+=x;
        res+=S.order_of_key({t-pref,0});
        S.insert({-pref,i});
    }
    cout<<res<<endl;

    return 0;

}