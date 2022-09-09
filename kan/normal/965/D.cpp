/**
 * This line was copied from template
 * This is nk_ok.cpp
 * 
 * @author: Nikolay Kalinin
 * @date: Mon, 23 Apr 2018 23:38:49 +0300
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int maxn = 100005;
const int inf = 1e9 + 9;

int a[maxn];
int w, len;

bool can(int k)
{
//     cout << "can " << k << endl;
    int curj = 0;
    int j = 0;
    int curdiff = 0;
    for (int i = 0; i < w; i++)
    {
        while ((curdiff < k - 1 || a[j] == 0) && j < w)
        {
            if (curdiff + a[j] - curj <= k - 1)
            {
                curdiff += a[j] - curj;
                curj = 0;
                j++;
            } else
            {
                curj += k - 1 - curdiff;
                curdiff = k - 1;
            }
//             cout << "at " << i << ' ' << j << ' ' << curj << endl;
        }
        if (j > i + len) return false;
        curdiff -= a[i + 1];
        if (j == w) break;
    }
    return true;
}

int main()
{
    scanf("%d%d", &w, &len);
    for (int i = 1; i < w; i++) scanf("%d", &a[i]);
    a[w] = 1;
    int l = 0;
    int r = inf;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (can(m)) l = m;
        else r = m;
    }
    cout << l << endl;
    return 0;
}