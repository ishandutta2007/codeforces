#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>

#define int long long
//#define double long double

using namespace std;

const long long MOD = 998244353;

string s;
long long t, n, a, b;

long long calc()
{
    vector<long long> dp0(n + 1, 1e18);
    vector<long long> dp1(n + 1, 1e18);
    long long ans = (n + 1) * b;
    dp0[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '1')
        {
            dp0[i] = 1e18;
            dp1[i] = dp1[i - 1] + a + b;
        }
        else
        {
            dp0[i] = min(dp0[i - 1] + a, dp1[i - 1] + 2 * a);
            dp1[i] = min(dp1[i - 1] + a + b, dp0[i - 1] + 2 * a + b);
        }
    }
    ans = ans + dp0[n];
    return ans;
}

signed main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> a >> b >> s;
        cout << calc() << "\n";
    }
}