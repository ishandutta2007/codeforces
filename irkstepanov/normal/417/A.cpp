#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <queue>
#include <cstdlib>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

using namespace std;

typedef long long ll;

int main()
{

    ll ans = 1000000000ll * 1000000000ll;

    ll c, d, n, m, k;
    cin >> c >> d >> n >> m >> k;

    for (ll a = 0; a <= 5000; a++)
        for (ll b = 0; b <= 5000; b++)
        {
            ll x = a * n + b + k;
            if (x >= n * m) ans = min(ans, a * c + b * d);
        }

    cout << ans << "\n";

}