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

const int maxn = 218 * 1000;

vector<ii> g[maxn];

int64 d1[maxn];
int64 d2[maxn];

void dfs1(int x, int p = -1) {
    d1[x] = 1;
    for (int i = 0; i < sz(g[x]); ++i) {
        if (g[x][i].first == p) continue;
        dfs1(g[x][i].first, x);
        d1[x] += d1[g[x][i].first];
    }
}

void dfs2(int x, int p = -1) {
    d2[x] = 0;
    for (int i = 0; i < sz(g[x]); ++i) {
        if (g[x][i].first == p) continue;
        dfs2(g[x][i].first, x);
        if (g[x][i].second == 1)
            d2[x] += d1[g[x][i].first];
        else
            d2[x] += d2[g[x][i].first];
    }
}

int64 res;

int64 total;

void dfs(int x, int p = -1, int64 up = 0) {
    int64 cur = up;
    cur += d2[x];
    res += (cur * (cur - 1LL));
    for (int i = 0; i < sz(g[x]); ++i) {
        if (g[x][i].first == p) continue;
        int64 add;
        if (g[x][i].second == 1)
            add = total - d1[g[x][i].first];
        else
            add = cur - d2[g[x][i].first];
        dfs(g[x][i].first, x, add);
    }
}

int main()
{
    vector<int64> v;

    for (int i = 1; i <= 12; ++i) {
        for (int mask = 0; mask < (1 << i); ++mask) {
            int64 x = 0;
            for (int j = 0; j < i; ++j) {
                x *= 10;
                if ((mask >> j) & 1)
                    x += 7;
                else
                    x += 4;
            }
            v.pb(x);
        }
    }
    
    sort(all(v));
    v.erase(unique(all(v)), v.end());

    
    int n;
    cin >> n;
    total = n;

    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        --x, --y;
        z = binary_search(all(v), (int64)z) ? 1 : 0;
        g[x].pb(ii(y, z));
        g[y].pb(ii(x, z));
    }

    memset(d1, -1, sizeof(d1));
    dfs1(0);
    memset(d2, -1, sizeof(d2));
    dfs2(0);

    res = 0;
    dfs(0);
    cout << res << "\n";
    return 0;
}