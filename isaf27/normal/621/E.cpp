#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const long long MOD = 1000000007;

vector<vector<long long> > e;

vector<vector<long long> > transpose(vector<vector<long long> > a)
{
    int n = a[0].size();
    vector<vector<long long> > ans(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[i].push_back(0LL);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[j][i] = a[i][j];
    return ans;
}

vector<vector<long long> > multiply(vector<vector<long long> > a, vector<vector<long long> > b)
{
    vector<vector<long long> > bt = transpose(b);
    int n = a[0].size();
    vector<vector<long long> > ans(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[i].push_back(0LL);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                ans[i][j] += a[i][k] * bt[j][k];
                ans[i][j] %= MOD;
            }
    return ans;
}

vector<vector<long long> > power(vector<vector<long long> > a, long long n)
{
    if (n == 0)
        return e;
    if (n == 1)
        return a;
    if (n % 2 == 0)
    {
        vector<vector<long long> > g = power(a, n / 2);
        return multiply(g, g);
    }
    vector<vector<long long> > g = power(a, n / 2);
    return multiply(multiply(g, g), a);
}

int n, b, k, x, a[10];

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    cin.sync_with_stdio(0);
    cin >> n >> b >> k >> x;
    for (int i = 0; i < 10; i++)
        a[i] = 0;
    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;
        a[u]++;
    }
    e.resize(x);
    for (int i = 0; i < x; i++)
        for (int j = 0; j < x; j++)
            e[i].push_back(0);
    for (int i = 0; i < x; i++)
        e[i][i] = 1;
    vector<vector<long long> > m(x);
    for (int i = 0; i < x; i++)
        for (int j = 0; j < x; j++)
            m[i].push_back(0);
    for (int i = 0; i < x; i++)
        for (int c = 0; c < 10; c++)
            m[i][(10 * i + c) % x] += a[c];
    m = power(m, b);
    /*for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }*/
    cout << m[0][k];
    return 0;
}