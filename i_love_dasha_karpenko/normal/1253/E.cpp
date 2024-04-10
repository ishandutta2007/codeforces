#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1ll;i<=n;++i)
#define pb push_back
#define endl '\n'
#define po(x) (1ll<<x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 1*10E4 +7;
const ll INF = 10E17+7;
ll dp[DIM];
pp A[87];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m; cin>>n>>m;
    forn(i,n){
        cin>>A[i].fi>>A[i].sc;
    }
    sort(A+1,A+1+n);
    forn(i,m)dp[i] = INF;
    dp[0] = 0;
    forn(i,n){
        ll mi = INF;
        for(ll sz = m;sz>=A[i].sc;--sz){
            mi = min(mi,dp[max(A[i].fi-sz-1,0ll)]+sz-A[i].sc);
            dp[min(A[i].fi+sz,m)] = min(dp[min(A[i].fi+sz,m)],mi);
        }
        for(ll sz = min(m,A[i].fi+A[i].sc-1);sz>=1;--sz){
            dp[sz] = min(dp[sz],mi);
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}

// 1 2 3
//