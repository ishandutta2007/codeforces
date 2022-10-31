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
const ll DIM = 1E5+7;
const ll INF = 1e18;


ll A[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        forn(i,n)cin>>A[i];
        ll cur = A[1];
        ll res = 0;
        for(ll i = 2;i<=n;++i){
            ll dif = A[i]-cur;
            if (dif<0){
                dif*=-1;
                ll p = 0;
                while(dif>0){
                    dif/=2;
                    ++p;
                }
                res = max(res,p);
            }
            else{
                cur = A[i];
            }
        }
        cout<<res<<endl;
    }
    return 0;
}