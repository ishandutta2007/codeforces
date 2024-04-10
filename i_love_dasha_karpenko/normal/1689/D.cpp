#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e3+7;
int A[N][N],dp[N][N],mx[N][N];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i+=1){
        for(int j = 1;j<=m;j+=1){
            char ch;
            cin>>ch;
            A[i][j] = ch=='B';
        }
    }
    for(int i = 1;i<=n;i+=1){
        for(int j = 1;j<=m;j+=1){
            dp[i][j] = -1;
            if (A[i][j]==1){
                dp[i][j] = 0;
            }
            if (dp[i-1][j]!=-1){
                dp[i][j] = max(dp[i][j],dp[i-1][j] + 1);
            }
            if (dp[i][j-1]!=-1){
                dp[i][j] = max(dp[i][j],dp[i][j-1] + 1);
            }
            mx[i][j] = max(mx[i][j],dp[i][j]);
        }
    }
    for(int i = 1;i<=n;i+=1){for(int j = 1;j<=m;j+=1){ dp[i][j] = -1; }}
    for(int i = 1;i<=n;i+=1){
        for(int j = m;j>=1;j-=1){
            dp[i][j] = -1;
            if (A[i][j]==1){
                dp[i][j] = 0;
            }
            if (dp[i-1][j]!=-1){
                dp[i][j] = max(dp[i][j],dp[i-1][j] + 1);
            }
            if (dp[i][j+1]!=-1){
                dp[i][j] = max(dp[i][j],dp[i][j+1] + 1);
            }
            mx[i][j] = max(mx[i][j],dp[i][j]);
        }
    }
    for(int i = 1;i<=n;i+=1){for(int j = 1;j<=m;j+=1){ dp[i][j] = -1; }}
    for(int i = n;i>=1;i-=1){
        for(int j = 1;j<=m;j+=1){
            dp[i][j] = -1;
            if (A[i][j]==1){
                dp[i][j] = 0;
            }
            if (dp[i+1][j]!=-1){
                dp[i][j] = max(dp[i][j],dp[i+1][j] + 1);
            }
            if (dp[i][j-1]!=-1){
                dp[i][j] = max(dp[i][j],dp[i][j-1] + 1);
            }
            mx[i][j] = max(mx[i][j],dp[i][j]);
        }
    }
    for(int i = 1;i<=n;i+=1){for(int j = 1;j<=m;j+=1){ dp[i][j] = -1; }}
    for(int i = n;i>=1;i-=1){
        for(int j = m;j>=1;j-=1){
            dp[i][j] = -1;
            if (A[i][j]==1){
                dp[i][j] = 0;
            }
            if (dp[i+1][j]!=-1){
                dp[i][j] = max(dp[i][j],dp[i+1][j] + 1);
            }
            if (dp[i][j+1]!=-1){
                dp[i][j] = max(dp[i][j],dp[i][j+1] + 1);
            }
            mx[i][j] = max(mx[i][j],dp[i][j]);
        }
    }
    for(int i = 1;i<=n;i+=1){for(int j = 1;j<=m;j+=1){ dp[i][j] = -1; }}
    int mi = n+m;
    pair<int,int> ans;
    for(int i = 1;i<=n;i+=1){
        for(int j = 1;j<=m;j+=1){
            if (mx[i][j]<mi){
                mi = mx[i][j];
                ans = {i,j};
            }
            mx[i][j] = 0;
        }
    }
    cout<<ans.first<<' '<<ans.second<<endl;
}
signed main()
{
    memset(dp,-1,sizeof(dp));
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}