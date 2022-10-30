#include <bits/stdc++.h>
//chlen

using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pp;
const ll DIM = (10E4)*2+8;
const ll INF = 10000000007;
#define forn(i,n) for(ll i = 0;i<n;i++)
#define pb push_back

ll dp[DIM][2],A[DIM],B[DIM],n,c;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>c;
    forn(i,n-1)cin>>A[i];
    forn(i,n-1) cin>>B[i];
    dp[0][1] = c;
    cout<<"0 ";
    for(ll i = 1;i<n;i++){
        dp[i][0] = min(dp[i-1][1]+min(A[i-1],B[i-1]),dp[i-1][0]+A[i-1]);
        dp[i][1] = min(dp[i-1][1]+B[i-1],dp[i-1][0]+c+min(A[i-1],B[i-1]));
        cout<<min(dp[i][0],dp[i][1])<<' ';
    }
    cout<<endl;
    return 0;
}
//chlen