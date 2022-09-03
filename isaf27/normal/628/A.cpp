#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

const int MAX_N = 100001;

typedef long long ll;
#define filename "test"
#define fin for (int i = 0; i < n; i++)
#define fim for (int i = 0; i < m; i++)
#define fjn for (int j = 0; j < n; j++)
#define fjm for (int j = 0; j < m; j++)

ll n, p, b;

int main()
{
    //freopen(filename".in", "r", stdin);
    //freopen(filename".out", "w", stdout);
    cin >> n >> b >> p;
    ll ans2 = n * p;
    ll ans1 = 0;
    while (n > 1)
    {
        int x = 0;
        while ((1 << x) <= n)
            x++;
        x--;
        ll k = (1 << x);
        ans1 += k / 2 + k * b;
        n = k / 2 + (n - k);
    }
    cout << ans1 << " " << ans2;
    return 0;
}