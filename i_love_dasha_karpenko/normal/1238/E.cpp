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
//#define po(x) (1ll<<x)
const ll DIM = 10E4+7;
const ll DIM2 = 22;
const ll INF = 10E17;
const ll masksz = 1<<20;
ll n,m,in[DIM2][DIM2],cnt[DIM2][masksz],dp[masksz],po[47],ct[masksz];
ll A[DIM];
ll gi(char ch){
    return ch-'a'+1;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    po[0] = 1;
    forn(i,40)po[i] = po[i-1]*2;
    cin>>n>>m;
    forn(i,n){
        char ch;
        cin>>ch;
        A[i] = gi(ch);
    }
    for(ll i = 2;i<=n;i++){
        in[A[i-1]][A[i]]++;
        in[A[i]][A[i-1]]++;
    }

    for(ll mask = 1;mask<po[m];mask++){
        ll bit,submask;
        for(ll i = 0;i<m;i++){
            if (!(mask&po[i]))continue;
            submask = mask^po[i];
            bit = i+1;
        }
        forn(last,m){
            cnt[last][mask] = cnt[last][submask]+in[bit][last];
        }
    }

      for(ll mask = 1;mask<po[m];mask++){
        dp[mask] = INF;
        ll add = 0;
        for(ll bit =1;bit<=m;bit++){
            if (!(mask&po[bit-1]))continue;
            add+=cnt[bit][(po[m]-1)^mask];
        }
        for(ll last = 1;last<=m;last++){
            if (!(mask&po[last-1]))continue;
            ll submask = mask^po[last-1];
            ll res = dp[submask]+add;

            dp[mask] = min(dp[mask],res);
        }
    }
    cout<<dp[po[m]-1]<<endl;
    return 0;
}