#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2E5+7;
const ll INF = 1e9;
const ll MOD = 998244353 ;
ll po[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    ll res = 0;
    po[0] = 1;

    forn(i,n){
        po[i] = po[i-1]*10%MOD;

    }
    forn(len,n-1){
        ll combs = po[n-len-1]*18%MOD;
        combs = (combs+(n-len-1)*po[n-len-2]*81)%MOD;
        combs= (combs*10)%MOD;
        cout<<combs<<' ';
    }
    cout<<10<<endl;
    //cout<<po[n]<<endl;
    return 0;
}