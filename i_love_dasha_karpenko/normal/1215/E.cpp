#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
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
const ll DIM = 4*10E4 +7;
const ll INF = 10E17;
const ll DIMC = 21;
const ll masksz = po(20);
ll n,A[DIM],col[DIMC][DIMC],dp[masksz];
ll calc(ll a,ll b){
    ll ret = 0,cnt = 0;
    for(ll i = n;i>=1;i--){
        if (A[i]==a)cnt++;
        if (A[i]==b)ret+=cnt;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n)cin>>A[i];
    for(ll i = 1;i<DIMC;i++){
        for(ll j = 1;j<DIMC;j++){
            if (i==j)continue;
            col[i][j] = calc(i,j);
        }
    }

    for(ll mask = 1;mask<masksz;mask++){
        ll res = INF;
        for(ll last = 1;last<DIMC;last++){
            if ((po(last-1)&mask)==0)continue;
            ll submask = mask^po(last-1);
            ll cnt = dp[submask];
            for(ll i = 1;i<DIMC;i++){
                if (mask&po(i-1))continue;
                cnt+=col[last][i];
            }
            res = min(res,cnt);
        }
        dp[mask] = res;
    }
    cout<<dp[masksz-1]<<endl;
    return 0;
}