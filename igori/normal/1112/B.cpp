#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;
typedef long long ll;
#define re return
#define pb push_back
#define fi first
#define se second
#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
const int MAXN = 1500001;
const long long MOD = 1e9 + 7;

ll n, m, k;
ll a[500000];
ll t[500000];
ll num[500000];
ll interesting[500000];

long long round(int m, int n)
{
    long long c = 100 * m;
    if (n % 2 == 0)
        if (c % n < n / 2)
            return c / n;
        else
            return c / n + 1;
    else
        if (c % n <= n / 2)
            return c / n;
        else
            return c / n + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    int id = 0;
    int m = 0;
    fill(t, t + 150, -1);
    for (int t0 = 0; t0 < 601 * n; t0++)
    {
        for (int i = 0; i < k; i++)
        {
            if (t[i] != -1)
            {
                num[i]++;
                if (num[i] == a[t[i]] + 1)
                {
                    t[i] = -1;
                    m++;
                }
            }
        }
        for (int i = 0; i < k; i++)
        {
            if (t[i] == -1 && id < n)
            {
                t[i] = id;
                num[i] = 1;
                id++;
            }
        }
        for (int i = 0; i < k; i++)
        {
            if (t[i] != -1 && num[i] == round(m, n))
            {
                if (interesting[t[i]] == 0)
                {
                    interesting[t[i]] = 1;
                    ans++;
                    //cout << t0 << " " << t[i] << " " << num[i] << " " << m << " " << round(m, n) << endl;
                }
            }
        }
    }
    cout << ans;
}