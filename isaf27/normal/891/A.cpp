#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const int BIG = 2 * 1e9 + 239;
const ld pi = acos(-1.0);
const int M = 2001;
const int L = 21;
const int two = 2;
const ll INF = 1e18 + 239;
const int T = (1 << 21);
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, a[M];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int g = 0;
    for (int i = 0; i < n; i++)
        g = __gcd(g, a[i]);
    if (g != 1)
    {
        cout << -1;
        return 0;
    }
    int kol = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == 1)
            kol++;
    if (kol != 0)
    {
        cout << n - kol;
        return 0;
    }
    int ans = n - 1;
    int now = n;
    for (int i = 0; i < n; i++)
    {
        int g = 0;
        for (int j = i; j < n; j++)
        {
            g = __gcd(a[j], g);
            if (g == 1)
            {
                now = min(now, j - i);
                break;
            }
        }
    }
    cout << ans + now;
    return 0;
}