#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld pi = acos(-1.0);
const int BIG = 1e9;
const ll INF = 1e18;
const int M = 1e5 + 1;
const int L = 18;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif // ONLINE_JUDGE
    int n;
    cin >> n;
    if (n < 10)
    {
        cout << 1;
        return 0;
    }
    int nn = n;
    int x = 1;
    int t = 1;
    while (n)
    {
        n /= 10;
        x *= 10;
        if (0 < n && n < 10)
            t = n;
    }
    x /= 10;
    if (t * x == n)
    {
        cout << 1;
        return 0;
    }
    cout << ((t + 1) * x - nn);
    return 0;
}