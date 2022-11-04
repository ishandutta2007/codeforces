#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[501][501][2][2];



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    for(int i = 0; i <= 500; i++) // pairs
    {
        for(int j = 0; j <= 500; j++) // own
        {
            for(int k = 0; k < 2; k++) // mid
            {
                for(int l = 0; l < 2; l++) // can_vert
                {
                    dp[i][j][k][l] = -1000000;
                    if(i * 2 + j + k > 1000)
                    {
                        continue;
                    }
                    if(i == 0 && j == 0 && k == 0)
                    {
                        dp[i][j][k][l] = 0;
                        continue;
                    }
                    if(k == 1)
                    {
                        dp[i][j][k][l] = max(dp[i][j][k][l], -1 - dp[i][j][0][1]);
                    }
                    if(l == 1 && j != 0)
                    {
                        dp[i][j][k][l] = max(dp[i][j][k][l], -dp[i][j][k][0]);
                    }
                    if(j > 0)
                    {
                        dp[i][j][k][l] = max(dp[i][j][k][l], -1 - dp[i][j - 1][k][1]);
                    }
                    if(i > 0)
                    {
                        dp[i][j][k][l] = max(dp[i][j][k][l], -1 - dp[i - 1][j + 1][k][1]);
                    }
                }
            }
        }
    }
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int own = 0;
        int pairs = 0;
        int mid = 0;
        if(n % 2 == 1 && s[n / 2] == '0')
        {
            mid = 1;
        }
        for(int i = 0; i < n / 2; i++)
        {
            if(s[i] == '0' && s[n - i - 1] == '0')
            {
                pairs++;
            }
            else if(s[i] == '0' || s[n - i - 1] == '0')
            {
                own++;
            }
        }
        if(dp[pairs][own][mid][1] > 0)
        {
            cout << "ALICE\n";
        }
        else if(dp[pairs][own][mid][1] < 0)
        {
            cout << "BOB\n";
        }
        else
        {
            cout << "DRAW\n";
        }
    }
}