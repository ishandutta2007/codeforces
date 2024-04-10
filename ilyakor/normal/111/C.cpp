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

const int maxn = 7;

int d[57][1 << (2 * maxn)];

int nbits[100500];

int n, m;

bool ok(int x, int x3) {
    int x2 = (x & ((1 << m) - 1));
    x >>= m;
    int x1 = x;
    x = 0;
    x |= x1;
    x |= x2;
    x |= (x2 << 1);
    x |= (x2 >> 1);
    x |= x3;

    return (x & ((1 << m) - 1)) == ((1 << m) - 1);
}

int main()
{
    for (int i = 0; i < (1 << (2 * maxn)); ++i) {
        int x = i, y = 0;
        while (x) y += x % 2, x /= 2;
        nbits[i] = y;
    }
    cin >> n >> m;
    if (n < m) swap(n, m);
    memset(d, -1, sizeof(d));
    for (int mask = 0; mask < (1 << m); ++mask)
        d[0][mask] = m - nbits[mask];
    for (int i = 0; i < n - 1; ++i) {
        for (int mask = 0; mask < (1 << (2 * m)); ++mask) {
            if (d[i][mask] == -1) continue;
            for (int nm = 0; nm < (1 << m); ++nm) if (ok(mask, nm)) {
                int x = d[i][mask] + m - nbits[nm];
                int msk = ((mask & ((1 << m) - 1)) << m) + nm;
                d[i + 1][msk] = max(d[i + 1][msk], x);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < (1 << (2 * m)); ++i)
        if (d[n - 1][i] != -1 && ok(i, 0))
            res = max(res, d[n - 1][i]);
    cout << res << "\n";
    return 0;
}