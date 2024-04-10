#include <iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define itn int
#define pb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define INF 1000000
#define EPS 1e-4
#define MAXN int(1e6)

itn k,n;
int dp[1010][2020][4];


int f(int n){
    return n%998244353;
}

int main() {


    for(int j=0;j<4;j++){
                dp[0][0][j]=1;
    }

    cin >> n >> k;

    for(int i=1;i<n;i++){
        for(int u=0;u<=k;u++){
            dp[i][u][0]=f(dp[i][u][0]+dp[i-1][u][0]);
            dp[i][u][1]=f(dp[i][u][1]+dp[i-1][u][0]);
            dp[i][u][2]=f(dp[i][u][2]+dp[i-1][u][0]);
            dp[i][u+1][3]=f(dp[i][u+1][3]+dp[i-1][u][0]);
            //
            dp[i][u+1][0]=f(dp[i][u+1][0]+dp[i-1][u][1]);
            dp[i][u][1]=f(dp[i][u][1]+dp[i-1][u][1]);
            dp[i][u+2][2]=f(dp[i][u+2][2]+dp[i-1][u][1]);
            dp[i][u+1][3]=f(dp[i][u+1][3]+dp[i-1][u][1]);
            //
            dp[i][u+1][0]=f(dp[i][u+1][0]+dp[i-1][u][2]);
            dp[i][u+2][1]=f(dp[i][u+2][1]+dp[i-1][u][2]);
            dp[i][u][2]=f(dp[i][u][2]+dp[i-1][u][2]);
            dp[i][u+1][3]=f(dp[i][u+1][3]+dp[i-1][u][2]);
            //
            dp[i][u+1][0]=f(dp[i][u+1][0]+dp[i-1][u][3]);
            dp[i][u][1]=f(dp[i][u][1]+dp[i-1][u][3]);
            dp[i][u][2]=f(dp[i][u][2]+dp[i-1][u][3]);
            dp[i][u][3]=f(dp[i][u][3]+dp[i-1][u][3]);

        }
    }
    ll ans=0;
    ans=f(ans);
    ans+=dp[n-1][k-1][0];
    ans=f(ans);
    ans+=dp[n-1][k-1][3];
    ans=f(ans);
    if (k>1){
    ans+=dp[n-1][k-2][2];
    ans=f(ans);
    ans+=dp[n-1][k-2][1];
    ans=f(ans);
    }
    cout << ans;






    return 0;
}