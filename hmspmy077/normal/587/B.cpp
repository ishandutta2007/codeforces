#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <cassert>
#include <map>
#include <set>
#include <ctime>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(X) ((int)((X).size()))

const double eps = 1e-8;
const int inf = 1000000000;

const int N = 1000005;
const int mo = 1000000000 + 7;

vector<int> edge[N];

long long n, l, k;
long long f[N];
pair<int, int> a[N];

long long fix(long long x)
{
    x %= mo;
    while (x < 0) x += mo;
    return x;
}

long long getID(int i, int j)
{
    return i * k + j;
}

void work()
{
    cin >> n >> l >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].x;
        a[i].y = i + 1;
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
        f[getID(i, 0)] = 1;
    for (int i = 1; i < k; ++i)
    {
        long long s = 0;
        for (int l = 0; l < n; ++l)
        {
            int r = l;
            while (r + 1 < n && a[r + 1].x == a[r].x) ++r;
            for (int j = l; j <= r; ++j)
                s = fix(s + f[getID(j, i - 1)]);
            for (int j = l; j <= r; ++j)
                f[getID(j, i)] = s;
            l = r;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k; ++j)
        {
            long long p = l - (n * j + a[i].y);
            if (p < 0) continue;
            ans = fix(ans + (p / n + 1) % mo * f[getID(i, j)]);
        }
    cout << ans << endl;
}

int main()
{
    #ifdef LOCAL_TEST
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    work();
    return 0;
}