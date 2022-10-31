#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
const ll DIM = 2*30000+7;
const ll INF = 10E17;
const ll MAXN = 307;

ll dp[DIM][107];
bool mc(pp a,pp b){
    return a.fi+a.sc>b.fi+b.sc;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,r;
    cin>>n>>r;
    vector<pp> ps;
    vector<pp> V;
    ll res=0;

    forn(i,n){
        ll a,b;
        cin>>a>>b;
        if (b>0)ps.pb({a,b});
        else V.pb({a,b});
    }

    sort(ps.begin(),ps.end());
    for(pp to:ps){
        if (to.fi>r)break;
        res++;
        r+=to.sc;
    }
    sort(V.begin(),V.end(),mc);
    ll ans = 0;
    for(ll i = 1;i<=V.size();i++){
        for(ll k = max(V[i-1].fi,-V[i-1].sc);k<=r;k++){
            for(ll j = 0;j<i;j++){
                dp[k+V[i-1].sc][i] = max(dp[k+V[i-1].sc][i],dp[k][j]+1);
                ans = max(ans,dp[k+V[i-1].sc][i]);
            }
        }
    }
    cout<<res+ans<<endl;
    return 0;
}
// 9 7+2