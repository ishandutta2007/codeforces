#include<bits/stdc++.h>
using namespace std;
int dp[71][70][36][70];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k1;
    cin >> n >> m >> k1;
    vector<vector<int> > mass(n);
    for(int i = 0; i < n; i++)
    {
        mass[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            cin >> mass[i][j];
        }
    }
    for(int i = 0; i < 71; i++)
    {
        for(int j = 0; j < 70; j++)
        {
            for(int k = 0; k < 36; k++)
            {
                for(int l = 0; l < 70; l++)
                {
                    dp[i][j][k][l] = -500000;
                }
            }
        }
    }
    dp[0][0][0][0] = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int k = 0; k <= m / 2; k++)
            {
                for(int l = 0; l < k1; l++)
                {
                    if(k > m / 2)
                    {
                        continue;
                    }
                    if(j != m - 1)
                    {
                        dp[i][j + 1][k][l] = max(dp[i][j + 1][k][l], dp[i][j][k][l]);
                        if(k < m / 2)
                        {
                            dp[i][j + 1][k + 1][(l + mass[i][j]) % k1] = max(dp[i][j + 1][k + 1][(l + mass[i][j]) % k1],
                                                                        dp[i][j][k][l] + mass[i][j]);
                        }
                    }
                    else
                    {
                        dp[i + 1][0][0][l] = max(dp[i + 1][0][0][l], dp[i][j][k][l]);
                        if(k < m / 2)
                        {
                            dp[i + 1][0][0][(l + mass[i][j]) % k1] = max(dp[i + 1][0][0][(l + mass[i][j]) % k1],
                                                                        dp[i][j][k][l] + mass[i][j]);
                        }
                    }
                }
            }
        }
    }
    cout << max(0, dp[n][0][0][0]);
}