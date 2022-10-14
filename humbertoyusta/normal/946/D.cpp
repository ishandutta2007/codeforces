#include <bits/stdc++.h>
#define maxn 1005
#define db(x) cerr << #x << ": " << (x) << '\n'
using namespace std;

const int oo = 1e9+7;
char a[maxn][maxn];
int n,m,k,l,mn[maxn][maxn],dp[maxn][maxn],sol,sum[maxn];
vector<int> s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ///freopen("a.in","r",stdin);

    cin>>n>>m>>k;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
            sum[i]=sum[i]+(a[i][j]-'0');
        }
    }

    for(int i=0; i<=n; i++)
        for(int j=1; j<=m; j++){
            mn[i][j]=oo;
        }

    for(int i=1; i<=n; i++){
        s.clear();
        for(int j=1; j<=m; j++){
          if(a[i][j]=='1')
            s.push_back(j);
        }

        for(int len=1; len<=s.size(); len++){

            for(int j=0; j+len<=s.size(); j++){

                mn[i][len]=min(mn[i][len],s[j+len-1]-s[j]+1);
            }
        }
    }

    for(int i=1; i<=n; i++)
        for(int j=0; j<=k; j++)
            dp[i][j]=oo;

    for(int i=1; i<=n; i++){

        for(int j=0; j<=k; j++){

            for(int l=0; l<=k; l++){

                dp[i][j+l] = min( dp[i][j+l] , dp[i-1][j] + mn[i][max(0,sum[i]-l)] );

            }

        }
    }

    int sol = oo;
    for(int i = 0; i <= k; i++)
    sol = min(sol, dp[n][i]);
    cout << sol;

    return 0;
}