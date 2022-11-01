#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
//typedef tree(ll,null_type,less<ll>,tree_order_statistics_node_update,rb_tree_tag> super_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
const ll DIM = 10E2+7;
const ll INF = 10E17;
const ll MOD = 10E8+7;
const ll MAXN = 26;
ll A[DIM],dp[DIM],cnt[DIM],mxl = 0,mx[27];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin>>n;
    forn(i,n){
        char x;
        cin>>x;
        A[i] = x-'a'+1;
    }
    forn(i,MAXN)cin>>mx[i];
    cnt[0] = 1;
    forn(i,n){
        ll len = 0;
        dp[i] = INF;
        ll mi = INF;
        for(ll j = i;j>=1;j--){
            mi = min(mi,mx[A[j]]);
            if (len+1>mi)break;
            len++;
            cnt[i] = (cnt[i]+cnt[j-1])%MOD;
            dp[i] = min(dp[i],dp[j-1]+1);
        }

        mxl = max(mxl,len);
    }
    cout<<cnt[n]<<endl<<mxl<<endl<<dp[n]<<endl;
    return 0;
}