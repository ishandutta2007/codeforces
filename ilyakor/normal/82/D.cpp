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

const int64 inf = (int64)(1E15);

const int maxn = 1010;

int64 d[maxn][maxn];
ii from[maxn][maxn];

void relax(int x, int y, int64 val, ii f) {
    if (d[x][y] > val)
        d[x][y] = val, from[x][y] = f;
}

ii code(ii p, ii q) {
    int x = p.first;
    int y = p.second;
    if (q == ii(y + 1, y + 2))
        return ii(x, y);
    if (q == ii(y, y + 2))
        return ii(x, y + 1);
    assert(q == ii(x, y + 2));
    return ii(y, y + 1);
}

int main()
{
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    if (n == 1) {
        cout << v[0] << "\n1\n";
        return 0;
    }
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            d[i][j] = inf;
    d[0][1] = 0;
    int64 res = inf;
    ii rv(0, 0);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            if (d[i][j] == inf) continue;
            int64 val = d[i][j];
            if (j < n)
                relax(j + 1, j + 2, val + max(v[i], v[j]), ii(i, j));
            if (j + 1 < n)
                relax(j, j + 2, val + max(v[i], v[j + 1]), ii(i, j));
            if (j + 1 < n)
                relax(i, j + 2, val + max(v[j], v[j + 1]), ii(i, j));
            if (i >= n - 2 || j >= n - 1) {
                int tmp = 0;
                if (i < n) tmp = max(tmp, v[i]);
                if (j < n) tmp = max(tmp, v[j]);
                if (res > val + tmp)
                    res = val + tmp, rv = ii(i, j);
            }
        }
    cout << res << "\n";
    ii cur = rv;
    vector<ii> w;
    w.pb(cur);
    while (cur.first != 0 || cur.second != 1) {
        w.pb(code(from[cur.first][cur.second], cur));
        cur = from[cur.first][cur.second];
    }
    reverse(all(w));
    for (int i = 0; i < sz(w); ++i) {
        int x = w[i].first;
        if (x < n) printf("%d ", x + 1);
        x = w[i].second;
        if (x < n) printf("%d ", x + 1);
        printf("\n");
    }
    return 0;
}