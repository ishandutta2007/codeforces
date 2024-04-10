#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 100+7;
const ll INF = 1E16;
const ld eps = 0.00001;

ll h,c,t;
ld F(ll step){
    ld temp = ld(h*(step/2+step%2)+c*(step/2))/ld(step);
    return abs(ld(t)-temp);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll xx;
    cin>>xx;

    while(xx--){


        cin>>h>>c>>t;

        ld mid = ld(h+c)/2.0;
        ld delta = t-mid;
        ll moves = ld(ld(h)/2.0-ld(c)/2.0)/delta;


        vector<ll> V = {1,2,3};
        for(ll i = max(3ll,moves-100);i<=moves+100;++i){
            V.pb(i);
        }
        ll ans = 1;
        for(ll to:V){
            if (F(ans)>F(to))ans = to;
        }
        cout<<ans<<endl;
    }
    return 0;
}