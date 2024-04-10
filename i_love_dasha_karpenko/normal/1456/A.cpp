#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E5+7;
const ll INF = 1E15+7;
ll A[DIM],dp[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,p,k;
        cin>>n>>p>>k;
        dp[0] = INF;
        for(ll i = 1;i<=n;++i){
            char ch;
            cin>>ch;
            A[i] = ch-'0';
            A[i] = 1-A[i];
            dp[i] = INF;
        }
        for(ll i = n+1;i<=n*2;++i)dp[i] = INF;
        ll x,y;
        cin>>x>>y;
        dp[p] = 0;

        for(ll i = p+1;i<=n;++i){
            dp[i] = min(dp[i],(i-p)*y);
            if (i>=k)
                dp[i] = min(dp[i],dp[i-k]+A[i-k]*x);
        }
        ll res = INF;
        for(ll i = max(p,n-k+1);i<=n;++i)res = min(res,dp[i]+A[i]*x);
        cout<<res<<endl;
    }
    return 0;
}