#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <set>
#include <map>

using namespace std;

const int MAX_N = 500001;

long long n, a[MAX_N], t[MAX_N], pref[MAX_N][2], suf[MAX_N][2], upr[MAX_N], usu[MAX_N];

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    char x;
    scanf("%c", &x);
    for (int i = 0; i < n; i++)
    {
        char x;
        scanf("%c", &x);
        if (x == 'A')
            t[i] = 0;
        else
            t[i] = 1;
    }
    for (int i = 0; i <= n; i++)
    {
        pref[i][0] = 0;
        pref[i][1] = 0;
        suf[i][0] = 0;
        suf[i][1] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        pref[i][t[i - 1]] = pref[i - 1][t[i - 1]] + a[i - 1];
        pref[i][(t[i - 1] + 1) & 1] = pref[i - 1][(t[i - 1] + 1) & 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        suf[i][t[i]] = suf[i + 1][t[i]] + a[i];
        suf[i][(t[i] + 1) & 1] = suf[i + 1][(t[i] + 1) & 1];
    }
    for (int i = 0; i <= n; i++)
    {
        upr[i] = pref[i][0] - pref[i][1];
        usu[i] = suf[i][0] - suf[i][1];
    }
    long long ans = pref[n][1];
    long long m = -1e18;
    for (int i = 0; i <= n; i++)
    {
        m = max(m, upr[i]);
        m = max(m, usu[i]);
    }
    cerr << ans;
    cout << m + ans;
    return 0;
}