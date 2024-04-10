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
ll s[500000];
ll iz[500000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll ans = 0;
    cin >> n >> m >> k;
    for (int i = 1; i<= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    forn(i, k)
    {
        int p;
        cin >> p;
        int t = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == s[p] && a[i] > a[p])
            {
                t++;
            }
        }
        if (t > 0)
        {
            ans++;
        }
    }
    cout << ans;
}