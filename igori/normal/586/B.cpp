#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <time.h>
//
using namespace std;
//
#define int long long
//
int n, a[102], b[102], c[102];
//
signed main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    int ans = 1e9 + 9;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                int res = 0;
                for (int k = 0; k < i; k++)
                    res += a[k];
                for (int k = i; k < n - 1; k++)
                    res += b[k];
                res += c[i];
                for (int k = 0; k < j; k++)
                    res += a[k];
                for (int k = j; k < n - 1; k++)
                    res += b[k];
                res += c[j];
                ans = min(ans, res);
            }
        }
    }
    cout << ans;
}