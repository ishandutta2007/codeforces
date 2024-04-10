#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;

ld binpow (ld x, int p)
{
    if (p == 0) return 1;
    if (p == 1) return x;
    ld ans = 1;
    while (p != 1)
    {
        if (p & 1) ans *= x;
        x *= x;
        p >>= 1;
    }
    return ans * x;
}

int main()
{

    int m, n;
    cin >> m >> n;

    ld ans = 0;

    for (int k = 1; k <= m; k++)
        ans += k * (binpow(k * 1.0 / m, n) - binpow((k - 1) * 1.0 / m, n));

    cout.precision(5);
    cout << fixed << ans;

}