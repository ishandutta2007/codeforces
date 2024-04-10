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
const ll DIM = 100+14;
const ll INF = 1E19;

ll dp[DIM][DIM],A[DIM][DIM];
ll ch(ll num){
    ll mi = INF,mx = -INF;
    while(num>0){
        mi = min(mi,num%10);
        mx = max(mx,num%10);
        num/=10;
    }
    return mi==0;
}
ll next(ll num){
    ll mi = INF,mx = -INF;
    while(num>0){
        mi = min(mi,num%10);
        mx = max(mx,num%10);
        num/=10;
    }
    return mi*mx;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        while(!ch(n) && --k){
            n += next(n);
        }
        cout<<n<<endl;
    }

    return 0;
}