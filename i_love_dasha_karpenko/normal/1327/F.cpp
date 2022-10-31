#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef int  ll;
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
const ll DIM = 5E5+7;
const long long MOD = 998244353 ;
const ll LOG = 30;
ll n,k,m;
ll pr[LOG+5][DIM];
long long dp[DIM];
ll st[LOG+5][DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d%d%d",&n,&k,&m);
    forn(i,m){
        ll l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        ll bit = 0;

        while(bit<k){
            if (x&1){
                st[bit][l]++;
                st[bit][r+1]--;
            }
            else{
                pr[bit][r+1] = max(pr[bit][r+1],l);
            }
            x/=2;
            bit++;
        }
    }

    long long res = 1;
    for(ll bit = 0;bit<k;bit++){
        ll cnt = 0;
        dp[0] = 1;
        ll flag = 0;
        forn(i,n+1){
            cnt+=st[bit][i];

            pr[bit][i] = max(pr[bit][i],pr[bit][i-1]);
            dp[i] = dp[i-1];
            if (cnt==0)dp[i]=(dp[i]+dp[i-1]-dp[pr[bit][i]-1])%MOD;
            if (dp[i]<0)dp[i]+=MOD;
        }
        ll mult = dp[n+1]-dp[n];
        if (mult<0)mult+=MOD;
        res = (res*mult)%MOD;
    }
    printf("%lld\n",res);
    return 0;
}