#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 1543;

const int64 inf = (int64)(1E16);

int a[maxn][maxn];

int64 d[maxn][maxn];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            scanf("%d", &a[i][j + 1]);
            a[i][j + 1] += a[i][j];
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            d[i][j] = -inf;
    for (int i = 0; i < m; ++i)
        d[0][i] = a[0][i + 1];
    for (int i = 1; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            int64 cur = -inf;
            for (int j = 0; j < m; ++j)
            {
                d[i][j] = cur + a[i][j + 1];
                cur = max(cur, d[i - 1][j]);
            }
        }
        else
        {
            int64 cur = -inf;
            for (int j = m - 1; j >= 0; --j)
            {
                d[i][j] = cur + a[i][j + 1];
                cur = max(cur, d[i - 1][j]);
            }
        }
    }
    int64 res = -inf;
    for (int i = 0; i < m; ++i)
        res = max(res, d[n - 1][i]);
    cout << res << "\n";
    return 0;
}