#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int C = 12;
ll dp[C][2][2];

vector<int> to_vector(int n)
{
    vector<int> res;
    while(n)
    {
        res.push_back(n % 10);
        n /= 10;
    }
    while(res.size() < C)
    {
        res.push_back(0);
    }
    reverse(res.begin(), res.end());
    return res;
}

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
    while(t--)
    {
        int n;
        cin >> n;
        auto a = to_vector(n);
        memset(dp, 0, sizeof(ll) * C * 4);
        for(int i = 0; i < C; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                for(int k = 0; k < 2; k++)
                {
                    int second = j;
                    if(i == 0)
                    {
                        if(j == 0 && k == 0)
                        {
                            dp[i][j][k] = 1;
                        }
                        continue;
                    }
                    for(int up = 0; up < 10; up++)
                    {
                        for(int down = 0; down < 10; down++)
                        {
                            if((up + down + k) % 10 == a[i])
                            {
                                dp[i][j][k] += dp[i - 1][(up + down + k) / 10][second];
                            }
                        }
                    }
                }
            }
        }
        cout << dp[C - 1][0][0] - 2 << '\n';
    }
}