#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
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
const ll DIM = 400+7;
const ll INF = 10E17;

ll dp[DIM][DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll te;
    cin>>te;
    forn(qe,te){
        memset(dp,-1,sizeof(dp));
        string s,t;
        cin>>s>>t;

        for(ll i = 1;i<=t.length();i++)dp[1][i] = 0;
        for(char ch:s){
            for(ll i = t.length();i>=1;--i){
                for(ll j = i;j<=t.length();j++){
                    if (ch==t[i-1]){
                        dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
                        //continue;
                    }
                    if (dp[i][j]==-1)continue;
                    if (dp[i][j]+j-1<t.length() && t[dp[i][j]+j-1]==ch)dp[i][j]++;
                }
            }
        }
        ll flag = 0;
        for(ll i = 0;i<=t.length();i++){
           // cout<<dp[i][i]<<endl;
            if (dp[i][i]==t.length()-i+1)flag = 1;
        }
        if (flag==1)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}