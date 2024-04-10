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
const ll DIM = 10+1;
const ll INF = 1e8;
ll fact[30];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0] = 1;
    for(ll i = 1;i<=29;++i)fact[i] = fact[i-1]*i;
    ll t;
    cin>>t;
    while(t--){
        ll k;
        cin>>k;
        map<ll,ll> M;
        ll x = k;
        ll div = 2,n = 0;
        while(x>0){
            M[x%div]++;
            x/=div;
            div++;
            n++;
        }

        ll res = 0;
        n++;
        for(pp tt:M){
            ll cnt = 1  ,r = 1;
            if (tt.fi==0)continue;
            for(auto it = M.rbegin();it!=M.rend();it++){
                pp to = *it;
                if (to==tt)to.sc--;
                if (to.fi==0)to.fi++;
                if (n-to.fi-cnt-to.sc<0){
                    r = 0;
                    break;
                }

                r*=fact[n-to.fi-cnt]/(fact[to.sc]*fact[n-to.fi-cnt-to.sc]);

                cnt+=to.sc;
            }
            res+=r;
            //cout<<r<<endl;
        }
        cout<<res-1<<endl;
    }
    return 0;
}