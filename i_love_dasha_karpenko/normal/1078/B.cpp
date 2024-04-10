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
const ll DIM = 100+7;
const ld INF = 1e19;
const ll MOD = 1E9+123;
ll cnt[DIM],A[DIM],dp[DIM*DIM][DIM],fact[DIM];
ll flag[DIM*DIM][DIM];
ll rev(ll x){
    ll p = MOD-2;
    ll mult = x%MOD;
    x = 1;
    while(p>0){
        if (p&1)x = (x*mult)%MOD;
        mult = (mult*mult)%MOD;
        p/=2;
    }
    return x;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    ll all = 0;
    set<ll> S;
    forn(i,n){
        cin>>A[i];
        all+=A[i];
        cnt[A[i]]++;
        S.insert(A[i]);
    }
    dp[0][0] = 1;
    ll sum = 0;
    forn(i,n){
        sum+=A[i];
        for(ll w = sum;w>=0;--w){
            for(ll num = i;num>=1;--num){
                if (w-A[i]>=0 && num-1>=0 && dp[w-A[i]][num-1]!=0){
                    dp[w][num] += dp[w-A[i]][num-1];
                    if (flag[w][num]==0){
                        if (flag[w-A[i]][num-1]==A[i] || flag[w-A[i]][num-1]==0)flag[w][num] = A[i];
                        else flag[w][num] = -1;
                    }
                    else{
                        if (flag[w][num]!=A[i] || (flag[w-A[i]][num-1]!=0 && flag[w-A[i]][num-1]!=A[i]))flag[w][num] = -1;
                    }
                }
            }
        }
    }

    ll res = 0;
    forn(i,DIM-1){
        ll r = 0;
        forn(j,cnt[i]){
            r+=i;
            if (flag[r][j]==i || dp[all-r][n-j]==1 )res = max(res,j);
        }
    }
    if (S.size()==2){
        ll st = *S.begin();
        if (dp[cnt[st]*st][cnt[st]]==1)res = n;
    }
    cout<<res<<endl;
    return 0;
}