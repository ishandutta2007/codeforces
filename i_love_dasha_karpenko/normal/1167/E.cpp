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
const ll DIM = 1E6+7;
const ll INF = 1e8;

ll A[DIM],M[DIM];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,x;
    cin>>n>>x;
    ll mx = 0;
    set<ll> S;
    forn(i,n){
        ll x;
        cin>>x;
        if (!S.empty() && (*S.rbegin())>x){
            A[x] = (*S.rbegin());
            M[x] = (*S.upper_bound(x));
        }
        S.insert(x);
    }
    ll pos = x;
    for(ll i = x;i>=1;i--){

        if (A[i]!=0)break;
        if (i!=1)
        pos--;
    }
    forn(i,x){
        if (M[i]==0)M[i] = x;
    }
    ll res = 0;
   // pos++;
    ll to = x;
    for(ll i = 1;i<=to;i++){
        res+=(x-pos+1);
        pos = max(pos,A[i]);
        pos = max(pos,i+1);
        to = min(to,M[i]);
    }
    cout<<res<<endl;
    return 0;
}