#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define pb push_back
#define endl '\n'
#define po(x) (1ll<<x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 3000+7;
const ll INF = 10E16;
ll n,dp[DIM];
pp A[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n){
        cin>>A[i].fi>>A[i].sc;
    }
    sort(A+1,A+1+n);
    forn(i,n){
        dp[i] = INF;
    }
    dp[n] = A[n].sc;
    dp[n+1] = 0;
    for(ll i = n-1;i>=1;--i){
        ll sum = 0;
        for(ll j = i+1;j<=n+1;j++){
            dp[i] = min(dp[i],A[i].sc+dp[j]+sum);
            sum+=A[j].fi-A[i].fi;
        }
    }
    cout<<dp[1]<<endl;
    return 0;
}

// 1 2 3
//