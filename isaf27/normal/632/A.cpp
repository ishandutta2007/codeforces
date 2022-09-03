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

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    long long n, p, a[50];
    cin >> n >> p;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "halfplus")
            a[i] = 1;
        else
            a[i] = 0;
    }
    long long now = 0;
    long long ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i])
        {
            ans += p / 2 + p * now;
            now = 2 * now + 1;
            continue;
        }
        ans += p * now;
        now *= 2;
    }
    cout << ans;
    return 0;
}