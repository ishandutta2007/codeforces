#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef  double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 10E5+7;
const ll INF = 10E9;

ll n,A[DIM];
struct node{
    ll l,r;
    double val;
};
node ans[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    scanf("%lld\n",&n);
    forn(i,n){
        scanf("%lld",&A[i]);
    }
    ll t = 1;
    forn(i,n){
        node cp = {i,i,A[i]};
        ld sum = A[i];
        ll len = 1;
        while(t>1 && ans[t-1].val>sum/len){
            ll sl=ans[t-1].r-ans[t-1].l+1;
            len+=sl;
            sum+=ans[t-1].val*sl;
            cp = {i-len+1,i,sum/len};
            t--;
        }
        ans[t] = cp;
        t++;
    }
    forn(i,t-1){
        for(ll j = 0;j<=ans[i].r-ans[i].l;j++) printf("%.10f\n",ans[i].val);
    }
    return 0;
}