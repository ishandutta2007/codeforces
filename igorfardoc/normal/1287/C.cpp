#include<bits/stdc++.h>
using namespace std;
vector<int> mass;
int dp[100][100][100][2];

int rec(int i, int chet, int nchet, int m)
{
    if(chet < 0 || nchet < 0 || i < 0)
    {
        return 1000000;
    }
    if(dp[i][chet][nchet][m] != -1)
    {
        return dp[i][chet][nchet][m];
    }
    if(i == 0 && chet == 0 && nchet == 0)
    {
        dp[i][chet][nchet][m] = 0;
        return 0;
    }
    if(i == 0)
    {
        if((m == 0 && chet == 0) ||(m == 1 && nchet == 0))
        {
            dp[i][chet][nchet][m] = 100000;
            return dp[i][chet][nchet][m];
        }
        else
        {
            dp[i][chet][nchet][m] = 0;
            return 0;
        }
    }
    int ans = 0;
    if(mass[i] == 0 && mass[i - 1] == 0)
    {
        if(m == 0)
        {
            ans = min(rec(i - 1, chet - 1, nchet, 1) + 1, rec(i - 1, chet - 1, nchet, 0));
        }
        else
        {
            ans = min(rec(i - 1, chet, nchet - 1, 1), rec(i - 1, chet, nchet - 1, 0) + 1);
        }
    }
    else if(mass[i] == 0 && mass[i - 1] != 0)
    {
        if(m == 0)
        {
            ans = rec(i - 1, chet - 1, nchet, 1);
        }
        else
        {
            ans = rec(i - 1, chet, nchet - 1, 0);
        }
        if(m % 2 != mass[i - 1] % 2)
        {
            ans++;
        }
    }
    else if(mass[i] != 0 && mass[i - 1] != 0)
    {
        ans = rec(i - 1, chet, nchet, m);
        if(mass[i - 1] % 2 != mass[i] % 2)
        {
            ans++;
        }
    }
    else if(mass[i] != 0 && mass[i - 1] == 0)
    {
        if(mass[i] % 2 == 0)
        {
            ans = min(rec(i - 1, chet, nchet, 1) + 1, rec(i - 1, chet, nchet, 0));
        }
        else
        {
            ans = min(rec(i - 1, chet, nchet, 1), rec(i - 1, chet, nchet, 0) + 1);
        }
    }
    dp[i][chet][nchet][m] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    mass.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> mass[i];
    }
    int chet = n / 2;
    int nchet = (n - 1) / 2 + 1;
    for(int i = 0; i < n; i++)
    {
        if(mass[i] != 0)
        {
            if(mass[i] % 2 == 0)
            {
                chet--;
            }
            else
            {
                nchet--;
            }
        }
    }
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            for(int k = 0; k < 100; k++)
            {
                for(int m = 0; m < 2; m++)
                {
                    dp[i][j][k][m] = -1;
                }
            }
        }
    }
    rec(n - 1, chet, nchet, 0);
    rec(n - 1, chet, nchet, 1);
    cout << min(dp[n - 1][chet][nchet][0], dp[n - 1][chet][nchet][1]);
}