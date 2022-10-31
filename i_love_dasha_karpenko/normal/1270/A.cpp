#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> satan_set;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
#define x1 dsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 5000+7;
const ll INF = 10e16;
const ll MOD = 998244353 ;
const ll MAXN = 1000000000;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    forn(query,t){
        ll n; cin>>n;
        ll k1,k2; cin>>k1>>k2;
        ll mx1 = 0,mx2 = 0;
        forn(i,k1){
            ll x; cin>>x; mx1 = max(mx1,x);
        }
        forn(i,k2){
            ll x; cin>>x; mx2 = max(mx2,x);
        }
        if (mx1<mx2){
            cout<<"NO\n";
        }
        else cout<<"YES\n";
    }
    return 0;

}