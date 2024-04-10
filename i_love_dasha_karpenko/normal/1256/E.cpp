#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2E5+1;
const ll INF = 1e18;
pp A[DIM];
pp dp[DIM];
ll ans[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n){
        cin>>A[i].fi;
        A[i].sc = i;
    }
    sort(A+1,A+1+n);
    pp mi = {INF,0};
    for(ll i = 3;i<=5;++i){
        dp[i].fi = A[i].fi-A[1].fi;
        dp[i].sc =0;
    }
    for(ll i = 6;i<=n;++i){
        if (dp[i-3].fi-A[i-2].fi<mi.fi){
            mi.fi = dp[i-3].fi-A[i-2].fi;
            mi.sc = i-3;
        }
        dp[i].fi = A[i].fi+mi.fi;
        dp[i].sc = mi.sc;
    }
    cout<<dp[n].fi<<' ';
    ll cnt = 0;
    ll state = n;
    while(state>0){
        cnt++;
        ll to = dp[state].sc;
        while(state>to){
            ans[A[state].sc] = cnt;
            state--;
        }
    }
    cout<<cnt<<endl;
    forn(i,n)cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}