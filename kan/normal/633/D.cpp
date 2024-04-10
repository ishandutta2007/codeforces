#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define fi first
#define se second

const int maxn = 1005;

int n;
int a[maxn];
int cnt[maxn];
int have[maxn];
int was[maxn];
int ct = 0;

inline bool canset(int x)
{
//     cout << "canset " << x << endl;
    int wh = lower_bound(a, a + n, x) - a;
//     cout << "was[1] = " << was[1] << endl;
    if (wh >= n || a[wh] != x) return false;
//     cout << "was[1] = " << was[1] << endl;
//     cout << "hhe " << wh << ' ' << was[wh] << ' ' << ct << endl;
    if (was[wh] == ct)
    {
        if (!have[wh]) return false;
        have[wh]--;
//         cout << x << " rem " << have[wh] << endl;
        return true;
    } else
    {
        have[wh] = cnt[wh] - 1;
//         cout << "set " << wh << ' ' << ct << endl;
        was[wh] = ct;
//         cout << "was[1] = " << was[1] << endl;
        return true;
    }
}

inline int getcnt(int x)
{
    int wh = lower_bound(a, a + n, x) - a;
    return have[wh];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    int last = 0;
    cnt[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1]) cnt[last]++;
        else
        {
            last++;
            a[last] = a[i];
            cnt[last] = 1;
        }
    }
    n = last + 1;
//     cout << cnt[1] << endl;
//     cout << n << endl;
    int answer = 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
//             cout << "step " << i << ' ' << j << endl;
            ct++;
            int f = a[i];
            int s = a[j];
            canset(f);
            if (!canset(s)) continue;
            int curans = 2;
            while (true)
            {
                if (!canset(f + s)) break;
                curans++;
                int t = f + s;
                f = s;
                s = t;
                if (f == 0 && s == 0)
                {
                    curans += getcnt(0);
                    break;
                }
            }
            answer = max(answer, curans);
//             cout << "try " << a[i] << ' ' << a[j] << ' ' << curans << endl;
        }
    }
    cout << answer << endl;
    return 0;
}