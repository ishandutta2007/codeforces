#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long ll;

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
#define log sdfdsfdsf

const ll DIM = 2E5+7;
const ll MOD = 1e9+7;

const ll INF = 1E13;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
const ll alsz = 20;
const ll masksz = po(20);
ll vis[alsz+7],ne[alsz+7],po[DIM];
ll inmask[masksz],dp[masksz];
ll gi(char ch){
    return ch-'a';
}
void solve(){
    ll n;
    cin>>n;
    string A,B;
    cin>>A>>B;

    ll res = 0;
    for(ll i = 0;i<n;++i){
        if (A[i]!=B[i])
        vis[gi(B[i])]|=po[gi(A[i])];
        ne[gi(A[i])]|=po[gi(B[i])];
    }
    for(ll mask = 1;mask<masksz;++mask){
        dp[mask] = INF;
        inmask[mask] = 0;
        for(ll last = 0;last<alsz;++last){
            if (!(mask&po[last]))continue;
            inmask[mask]|=vis[last];

            ll submask = mask^po[last];
            ll need = vis[last]^(inmask[submask]&vis[last]);
            ll msk = inmask[submask];

            dp[mask] = min(dp[mask],dp[submask]+__builtin_popcount(need)+(msk!=0));
            if (vis[last])
            inmask[mask]|=po[last];

        }
        for(ll i = 0;i<alsz;++i){
            if (po(i)&inmask[mask]){
                if ((ne[i]&mask)==ne[i])inmask[mask]^=po[i];
            }
        }

    }
    cout<<dp[masksz-1]<<endl;
    for(ll i = 0;i<=20;++i){
        vis[i] = 0;
        ne[i] = 0;

    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    po[0] = 1;
    forn(i,DIM-1)po[i] = po[i-1]*2;
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}