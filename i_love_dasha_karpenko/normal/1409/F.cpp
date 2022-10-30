#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 200+7;
const ll INF = 1E19;
const ll MAXN = 26;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
ll dp[DIM][DIM][DIM],A[DIM];
pp suf[DIM];
ll gi(char ch){
    return ch-'a'+1;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,k;
    cin>>n>>k;
    forn(i,n){
        char ch;
        cin>>ch;
        A[i] = gi(ch);
    }
    char ch;
    cin>>ch;
    pp st;
    st.fi = gi(ch);
    cin>>ch;
    st.sc = gi(ch);
    ll res = 0;

    for(ll i = n;i>=1;--i){
        suf[i] = suf[i+1];
        if (A[i]==st.fi)suf[i].fi++;
        if (A[i]==st.sc)suf[i].sc++;
    }
    if (st.fi==st.sc){
        ll val = suf[1].fi;
        val = min(n,val+k);
        cout<<val*(val-1)/2<<endl;
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0][0] = 0;
    forn(i,n){
        for(ll j = 0;j<=k;++j){
            for(ll val = 0;val<=i;++val){
                dp[i][j][val] = dp[i-1][j][val];
                if (val==0)continue;

                if (A[i]==st.fi){
                    if (dp[i-1][j][val-1]!=-1){
                        dp[i][j][val] = max(dp[i][j][val],dp[i-1][j][val-1]);
                    }
                }
                else{
                    if (j>0 && dp[i-1][j-1][val-1]!=-1){
                        dp[i][j][val] = max(dp[i][j][val],dp[i-1][j-1][val-1]);
                    }
                }
                if (A[i]==st.sc){
                    if (dp[i-1][j][val]!=-1)
                    dp[i][j][val]  =max(dp[i-1][j][val]+val,dp[i][j][val]);
                }
                else{
                    if (j>0 && dp[i-1][j-1][val]!=-1){
                        dp[i][j][val] = max(dp[i-1][j-1][val]+val,dp[i][j][val]);
                    }
                }
                if (dp[i][j][val]<0)continue;
                ll g = min(n-i,suf[i+1].sc+k-j);
                if (dp[i][j][val]+val*g>3){
                    ll h;
                    ++h;
                }

                res = max(res,dp[i][j][val]+val*g);
            }
        }
    }
    cout<<res<<endl;
    return 0;
}