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
const ll DIM = 1000+7;
const ll INF = 10E16;
ll n,dp[DIM][DIM],A[DIM];
pp P[DIM][DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n)cin>>A[i];
    for(ll i = 0;i<=n;i++){
        for(ll j = 0;j<=n;j++)dp[i][j] = INF;
    }
    dp[1][1] = 0;
    for(ll i = 3;i<=n;i+=2){
        for(ll st = 1;st<=i;st++){
            if (st<=i-2)
                dp[i][st] = min(dp[i][st],dp[i-2][st]+max(A[i-1],A[i]));
            else{
                for(ll j = 1;j<=st;j++){
                    ll a;
                    if (st==i)a = A[i-1];
                    else a = A[i];
                    if (dp[i][st]>dp[i-2][j]+max(A[j],a)){
                        P[i][st] = {i-2,j};
                        dp[i][st]=dp[i-2][j]+max(A[j],a);
                    }
                }
            }
        }
    }
    ll res = INF;
    pp beg;
    vector<pp> ans;
    if (n%2!=0){
        //n-=2;

        forn(i,n){
            if (res>dp[n][i]+A[i]){
                res=dp[n][i]+A[i];
                beg = {n,i};
            }
        }
        cout<<res<<endl;
        ans.pb({beg.sc,-1});
    }
    else{
        ll res = INF;

        for(ll st = 1;st<=n-1;st++){
            if (res>dp[n-1][st]+max(A[st],A[n])){
                res=dp[n-1][st]+max(A[st],A[n]);
                beg = {n-1,st};
            }
        }
        cout<<res<<endl;
        ans.pb({beg.sc,n});
    }
    while(beg.fi!=1){

        if (beg.sc<=beg.fi-2){
            ans.pb({beg.fi-1,beg.fi});
            beg.fi-=2;
        }
        else{
            ll a;
            if (beg.sc==beg.fi-1)a = beg.fi;
            else a = beg.fi-1;
            ans.pb({P[beg.fi][beg.sc].sc,a});
            beg.sc = P[beg.fi][beg.sc].sc;
            beg.fi-=2;
        }

    }
    reverse(ans.begin(),ans.end());
    for(pp to:ans){
        if (to.sc==-1)cout<<to.fi<<endl;
        else cout<<to.fi<<' '<<to.sc<<endl;
    }
    return 0;
}

// 1 2 3
//