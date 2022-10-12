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

long long n;
pair<int, int> ab[500000];

long long ans = 0;

bool comp1(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

bool comp2(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

long long fact[500000];

signed main()
{
    fact[0] = 1;
    ans = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
        ans = ans * i % MOD;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> ab[i].first >> ab[i].second;
    }
    sort(ab, ab + n, comp1);
    long long dec = 1;
    for (int i = 0; i < n; i++)
    {
        int d = ab[i].first;
        int j = i;
        while (j + 1 < n && ab[j + 1].first == d)
        {
            j++;
        }
        dec = dec * fact[j - i + 1] % MOD;
        i = j;
    }
    sort(ab, ab + n, comp2);
    ans = (ans + MOD - dec) % MOD;
    dec = 1;
    for (int i = 0; i < n; i++)
    {
        int d = ab[i].second;
        int j = i;
        while (j + 1 < n && ab[j + 1].second == d)
        {
            j++;
        }
        dec = dec * fact[j - i + 1] % MOD;
        i = j;
    }
    ans = (ans + MOD - dec) % MOD;

    int t = 1;
    for (int i = 1; i < n; i++)
    {
        if (ab[i].first >= ab[i - 1].first && ab[i].second >= ab[i - 1].second)
            ;
        else
            t = 0;
    }

    if (t == 1)
    {
        dec = 1;
        for (int i = 0; i < n; i++)
        {
            int d = ab[i].second;
            int e = ab[i].first;
            int j = i;
            while (j + 1 < n && ab[j + 1].second == d && ab[j + 1].first == e)
            {
                j++;
            }
            dec = dec * fact[j - i + 1] % MOD;
            i = j;
        }
        ans = (ans + MOD + dec) % MOD;
    }

    cout << ans;
}