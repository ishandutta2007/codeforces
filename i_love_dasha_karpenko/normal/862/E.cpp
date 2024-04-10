//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N = 1E5+7;
const ll INF = 1E18;
ll A[N],B[N];
ll sum[2][N],dp[N];
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    ll base = 0;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        if (i%2)
            base+=A[i];
        else base-=A[i];
    }
    for(int i = 1;i<=m;++i){
        cin>>B[i];
        sum[0][i] = sum[0][i-1];
        sum[1][i] = sum[1][i-1];
        sum[i%2][i]+=B[i];
    }
    ll mi = INF,mx = -INF;


    for(int i = 1;i<=m-n+1;++i){
        dp[i] = -(sum[i%2][i+n-1]-sum[i%2][i-1]-sum[1-i%2][i+n-1]+sum[1-i%2][i-1]);
        mi = min(mi,dp[i]);
        mx = max(mx,dp[i]);
    }
    sort(dp+1,dp+1+m-n+1);
    dp[0] = dp[m-n+2] = INF;
    {
        int pos = lower_bound(dp+1,dp+1+m-n+1,-base)-dp;
        cout<<min(abs(dp[pos]+base),abs(dp[pos-1]+base))<<endl;
    }
    while(q--){
        ll l,r,val;
        cin>>l>>r>>val;
        ll positive = (r-l+1)/2;
        if (l%2 && (r-l+1)%2)
            ++positive;
        base += (positive*2-(r-l+1))*val;
        int pos = lower_bound(dp+1,dp+1+m-n+1,-base)-dp;

        cout<<min(abs(dp[pos]+base),abs(dp[pos-1]+base))<<endl;
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}