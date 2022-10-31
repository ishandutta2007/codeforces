#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
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
const ll DIM = 100+7;
const ll INF = 10E17;
const ll maskszm = po(4);
ll n,m,A[5][DIM],dp[maskszm],olddp[maskszm];
void rotate(ll pos){
    ll p = A[n][pos];
    for(ll i = n;i>1;i--)A[i][pos] = A[i-1][pos];
    A[1][pos] = p;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll te;
    cin>>te;
    while(te--){
        cin>>n>>m;
        ll masksz = po(n);
        forn(i,n)forn(j,m)cin>>A[i][j];
        memset(dp,0,sizeof(dp));
        forn(i,m){
            for(ll mask = 1;mask<masksz;++mask){
                olddp[mask] = dp[mask];
                dp[mask] = 0;
            }
            forn(rot,n){
                for(ll mask = 1;mask<masksz;++mask){
                    for(ll submask = 0;submask<=mask;++submask){
                        if ((mask|submask)!=mask)continue;
                        ll sum = 0;
                        for(ll bit = 1;bit<=n;bit++){
                            if (submask&po(bit-1)){
                                sum+=A[bit][i];
                            }
                        }
                        sum+=olddp[mask^submask];
                        dp[mask] = max(dp[mask],sum);
                    }
                }
                rotate(i);
            }
        }

        cout<<dp[masksz-1]<<endl;
    }

    return 0;
}