#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const long long MOD = 998244353;

long long ans, n, k;
long long a[500000];
long long dp[2][500000];

long long run(vector<int> c)
{
    long long r = 1;
    if (c[0] == -1 && c[c.size() - 1] == -1)
    {
        for (int i = 0; i < c.size() - 1; i++)
        {
            r = r * (k - 1) % MOD;
        }
        r = r * k % MOD;
        //cout << r << endl;
        return r;
    }
    if (c.size() == 1)
    {
        return 1;
    }
    if (c[0] != -1 && c[c.size() - 1] == -1)
        reverse(c.begin(), c.end());
    for (int i = 0; i < c.size(); i++)
    {
        dp[0][i] = 0, dp[1][i] = 0;
    }
    if (c[0] != -1 && c[c.size() - 1] != -1)
    {
        dp[0][0] = 1;
        dp[1][0] = 0;
        if (c[0] == c[c.size() - 1])
        {
            swap(dp[1][0], dp[0][0]);
        }
    }
    else
    {
        dp[0][0] = k - 1;
        dp[1][0] = 1;
    }
    for (int i = 1; i + 1 < c.size(); i++)
    {
        dp[1][i] = dp[0][i - 1];
        dp[0][i] = (dp[0][i - 1] * (k - 2) + dp[1][i - 1] * (k - 1)) % MOD;
    }
    return dp[0][c.size() - 2];
}

long long get(vector<int> c)
{
    long long res = 1;
    vector<int> cn;
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i] == -1)
        {
            cn.push_back(c[i]);
        }
        else
        {
            cn.push_back(c[i]);
            if (cn.size() >= 1)
                res = res * run(cn);
            if (res >= MOD) res %= MOD;
            cn.resize(0);
            cn.push_back(c[i]);
        }
    }
    if (cn.size() >= 1)
       res = res * run(cn);
    if (res >= MOD) res %= MOD;
    return res;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> c1, c2;
    for (int i = 0; i < n; i+=2)
    {
        c1.push_back(a[i]);
    }
    for (int i = 1; i < n; i+=2)
    {
        c2.push_back(a[i]);
    }
    //cout << get(c1) << endl << endl;
    //cout << get(c2) << endl << endl;
    ans = get(c1) * get(c2) % MOD;
    cout << ans;
}