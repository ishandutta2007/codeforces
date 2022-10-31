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
const ll DIM = 3000+7;
const ll INF = 1e19;
const ll MOD = 998244353;

ll dp[DIM],re[DIM],oldre[DIM],olddp[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s,t;
    cin>>s>>t;
    ll n = s.length();
    ll m = t.length();
    s = '?'+s;
    t = '?'+t;
    olddp[0] = 1;

    ll res = 0;
    for(ll pos = 1;pos<=n;++pos){
        char cur = s[pos];
        if (pos==1){
            forn(i,m-1){
                if (cur==t[i])re[i] = 1;
            }
        }
        forn(i,m-pos){
            //if (pos+i-1>m)re[i]=(re[i]+oldre[i])%MOD;
            if (t[i]==cur)re[i]=(re[i]+oldre[i+1])%MOD;
            if (i+pos-1<=m && t[i+pos-1]==cur)re[i] = (re[i]+oldre[i])%MOD;
        }
        //if (pos>=m)res = (res+re[1])%MOD;
        for(ll i = 1;i<=m;++i){
            if (t[m-i+1]==cur)dp[i]=(dp[i]+olddp[i-1])%MOD;
            if (t[m-i+1]==cur && m-i+pos>=m )dp[i]=(dp[i]+oldre[m-i+2])%MOD;
            if (m-i+pos-1>=m)dp[i] = (dp[i]+oldre[m-i+1])%MOD;
            if (m-i+pos==m && t[m]==cur)dp[i] = (dp[i]+oldre[m-i+1]);
            dp[i] = (dp[i]+olddp[i])%MOD;

        }
        dp[0] = (olddp[0]*2)%MOD;
        if (pos==1)dp[0] = 1;
        res = (res+dp[m])%MOD;
        for(ll i = 0;i<=m+1;++i){
           // cout<<re[i]<<' ';
            olddp[i] = dp[i];
            oldre[i] = re[i];
            dp[i] = re[i] = 0;
        }
        //cout<<endl;
    }
    res = (res*2)%MOD;
    cout<<res<<endl;
    return 0;
}