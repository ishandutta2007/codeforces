#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)


using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 1e5+5, base = 1e9+7;
const int maxC = 210;

int dp[maxC][maxC][2]; // len sum edge

int main()
{
    int n, k, d;
    scanf("%d %d %d", &n, &k, &d);
    
    for (int i = 1;  i <= k; i++){
        if (i < d)
            dp[1][i][0] = 1;
        else
            dp[1][i][1] = 1;
    }
    
    for (int len = 1; len <= 100; len++)
        for (int sum = 1; sum <= n; sum++){
            for (int edge = 1; edge <= k; edge++){
                    if (edge < d){
                        dp[len + 1][sum + edge][0] += dp[len][sum][0];
                        dp[len + 1][sum + edge][0] %= base;
                    } else {
                        dp[len + 1][sum + edge][1] += dp[len][sum][0];
                        dp[len + 1][sum + edge][1] %= base;
                    }

                    dp[len + 1][sum + edge][1] += dp[len][sum][1];
                    dp[len + 1][sum + edge][1] %= base;
            }
        }
    
    int ans = 0;
    for (int len=1; len <= 100; len++){
        ans += dp[len][n][1];
        ans %= base;
    }

    cout << ans;
}