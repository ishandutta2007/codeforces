//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 1000+7;
const ll INF = 1E15;
const ll MOD = 998244353;
ll A[2][DIM],dp[2][DIM][DIM],len[2][DIM];
ll gi(char ch){
    return ch-'0';
}
void solve(){
    string t1,t2;
    cin>>t1>>t2;
    ll n = t1.length(),m = t2.length();
    for(ll i = 1;i<=n;++i){
        A[0][i] = gi(t1[i-1]);
    }
    for(ll i = 1;i<=m;++i){
        A[1][i] = gi(t2[i-1]);
    }

    for(ll i = 1;i<=n;++i){
        if (A[0][i]==A[0][i-1])len[0][i] = 1;
        else len[0][i] = len[0][i-1]+1;
    }
    for(ll i = 1;i<=m;++i){
        if (A[1][i]==A[1][i-1])len[1][i] = 1;
        else len[1][i] = len[1][i-1]+1;
    }
    //dp[0][1][0] = dp[1][0][1] = 1;
    ll res = 0;
    for(ll i = 0;i<=n;++i){
        for(ll j = 0;j<=m;++j){
            for(ll last = 0;last<2;++last) {
                if (last==1 && i==0 && j==3){
                    ll h;
                    ++h;
                }
                dp[last][i][j] = 0;
                ll cur;
                if (last==0)cur = A[0][i];
                else cur = A[1][j];
                ll pos;
                if (last==0)pos = i;
                else pos = j;
                if (i>0 && last==0){
                    if (A[0][i-1]!=cur)dp[last][i][j] += dp[0][i-1][j];//+ll(pos>0 && i-1ll>0);
                    if (A[1][j]!=cur)dp[last][i][j] += dp[1][i-1][j];
                }
                if (j>0 && last==1){
                    if (A[0][i]!=cur)dp[last][i][j] += dp[0][i][j-1];
                    if (A[1][j-1]!=cur)dp[last][i][j]+=dp[1][i][j-1];//+ll(pos>0 && j-1ll>0);
                }

                if (A[0][i]!=A[1][j] && i>0 && j>0) {
                    if (last==1)dp[last][i][j]+=len[0][i];
                    else dp[last][i][j]+=len[1][j];
                }
                dp[last][i][j]%=MOD;
                if (i>0 && j>0)res+=dp[last][i][j],res%=MOD;
                //cout<<last<<' '<<i<<' '<<j<<' '<<dp[last][i][j]<<endl;
            }
        }
    }
    cout<<res<<endl;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    t = 1;
    while(t--)
        solve();
    return 0;
}