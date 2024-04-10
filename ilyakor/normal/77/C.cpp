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

const int maxn = 200 * 1000;

bool u[maxn];
vi g[maxn];
int ki[maxn];

int64 d[maxn];

int64 dfs(int x)
{
    u[x] = true;
    vector<pair<int64, int64> > v;
    for (int i = 0; i < sz(g[x]); ++i) {
        if (u[g[x][i]]) continue;
        --ki[g[x][i]];
        int64 cur = dfs(g[x][i]);
        v.pb(mp(cur, d[g[x][i]]));
    }
    sort(all(v));
    reverse(all(v));
    int64 res = 0;
    int64 l = ki[x];
    for (int i = 0; i < sz(v); ++i) {
        if (l <= 0) continue;
        res += 2 + v[i].first;
        --l;
    }
    for (int i = 0; i < sz(v); ++i) {
        int64 cur = min(l, v[i].second);
        l -= cur;
        res += 2 * cur;
    }
    d[x] = l;
    return res;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ki[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        g[x].pb(y);
        g[y].pb(x);
    }
    int s;
    cin >> s;
    --s;
    memset(u, 0, sizeof(u));
    cout << dfs(s) << "\n";
    return 0;
}