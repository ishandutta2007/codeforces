//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
//#define int ll
const int N = 1e5+7;
int A[N];
pair<int,ll> dp[2][N][2];
void solve(){
    int n;
    cin>>n;
    for(int c1 = 0;c1<2;c1+=1)
    for(int i = 0;i<=n+2;i+=1){
        for(int c2 = 0;c2<2;c2+=1){
            dp[c1][i][c2] = {0,0};
        }
    }
    for(int i = 1;i<=n;i+=1){
        cin>>A[i];
    }
   for(int i = n;i>=1;i-=1){
       for(int c = 0;c<2;c+=1){
           dp[0][i][c] = dp[0][i+1][c];
       }
       dp[0][i][i%2].first += (1<i && i<n);
       dp[0][i][i%2].second -= max({0,A[i-1]-A[i]+1,A[i+1]-A[i]+1})*(1<i && i<n);
   }
   for(int i = 1;i<=n;i+=1){
       if (i>1)
       for(int c = 0;c<2;c+=1){
           dp[1][i][c] = dp[1][i-1][c];
       }
       dp[1][i][i%2].first += (1<i && i<n);
       dp[1][i][i%2].second -= max({0,A[i-1]-A[i]+1,A[i+1]-A[i]+1})*(1<i && i<n);
   }
    pair<int,ll> ans = {0,0};
   ans = min({ans,dp[0][1][0],dp[0][1][1]});
   for(int i = 1;i<=n;i+=1){
       pair<int,ll> cur = dp[1][i][i%2];
       cur.first += dp[0][i+2][1-i%2].first;
       cur.second += dp[0][i+2][1-i%2].second;
       ans = max(ans,cur);
   }
   cout<<-ans.second<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}