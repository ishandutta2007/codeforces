#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef int ll;
typedef double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2000+7;
const ll INF = 10E17;
const ll maskszm = po(12);
ll n,m,A[13][DIM],dp[maskszm],olddp[maskszm],curdp[maskszm],po[30];
vector<pp> V;

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll te;
    scanf("%d",&te);
    po[0] = 1;
    forn(i,29)po[i] = po[i-1]*2;
    while(te--){
        scanf("%d%d",&n,&m);
        ll masksz = po[n];
        forn(i,n)forn(j,m)scanf("%d",&A[i][j]);
        forn(j,m){
            ll mx = 0;
            forn(i,n)mx = max(mx,A[i][j]);
            V.pb({mx,j});
        }
        sort(V.begin(),V.end(),greater<pp>());
        while(V.size()>n)V.pop_back();
        memset(curdp,0,sizeof(curdp));
        for(pp to:V){
            ll i = to.sc;
            for(ll mask = 1;mask<masksz;++mask){
                olddp[mask] = curdp[mask];
                dp[mask] = olddp[mask];
                curdp[mask] = 0;
            }
            forn(shift,n){
                for(ll mask = 1;mask<masksz;++mask){
                    for(ll bit = 1;bit<=n;bit++){
                        ll pos = bit+shift-1;
                        if (pos>n)pos-=n;
                        dp[mask|po[bit-1]] = max(dp[mask|po[bit-1]],dp[mask-(mask&po[bit-1])]+A[pos][i]);
                    }

                }
                for(ll mask = 1;mask<masksz;++mask){
                    curdp[mask] = max(curdp[mask],dp[mask]);
                    dp[mask] = olddp[mask];
                }
                //rotate(i);
            }
        }

        printf("%d\n",curdp[masksz-1]);
        V.clear();
    }

    return 0;
}