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
const ll DIM = 500+7;
const ll INF = 10E17;
const ll MOD = 998244353;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll pref[DIM],dp[DIM],A[DIM],mi[DIM][DIM];
ll rdp[DIM][DIM];
vector<ll> ran[DIM];
ll cntdp(ll l,ll r){

    if (l==r){
        mi[l][r] = A[l];
        return 1;
    }
    if (rdp[l][r]!=-1)return rdp[l][r];
    if (l==1 && r==4){
        rdp[l][r] = 0;
    }
    rdp[l][r] = 0;
    mi[l][r] = 0;
    for(ll i = l+1;i<=r;i++){
       // mi[l][r] = min(mi[l][r],A[i]);
        cntdp(l,i-1);
        cntdp(i,r);
        if (cntdp(l,i-1)==1 && mi[l][i-1]==mi[i][r] && cntdp(i,r)==1){
            mi[l][r] = mi[l][i-1]+1;
            rdp[l][r] = 1;
        }
    }
    if (rdp[l][r]==1){
        ran[r].pb(l);
        //cout<<l<<' '<<r<<endl;
    }
    return rdp[l][r];
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n){
        cin>>A[i];
        pref[i] = pref[i-1]+A[i];
    }
    memset(rdp,-1,sizeof(rdp));
    cntdp(1,n);

    forn(i,n){
        dp[i] = dp[i-1]+1;
        for(ll to:ran[i]){
            dp[i] = min(dp[i],dp[to-1]+1);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}