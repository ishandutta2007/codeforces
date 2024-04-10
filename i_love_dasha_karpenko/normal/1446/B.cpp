#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll INF = 1E17;
const ll DIM = 5E3+7;

ll A[DIM],B[DIM],dp[DIM][DIM];
ll gi(char ch){
    return ch-'a';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(ll i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        A[i]=gi(ch);
    }
    for(ll i = 1;i<=m;++i){
        char ch;
        cin>>ch;
        B[i] = gi(ch);
    }
    ll res = 0;
    for(ll i = 1;i<=n;++i){
        for(ll j = 1;j<=m;++j){
            dp[i][j] = max(dp[i-1][j]-1,dp[i][j-1]-1);
            if (A[i]==B[j])dp[i][j] = max(dp[i][j],dp[i-1][j-1]+2);
            dp[i][j] = max(0ll,dp[i][j]);
            res = max(res,dp[i][j]);
        }
    }
    cout<<res<<endl;

    return 0;
}