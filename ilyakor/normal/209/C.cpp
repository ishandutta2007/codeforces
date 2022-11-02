#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <bitset>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;

template<class T> T abs(T x) { return x > 0 ? x : -x; }
template<class T> T sqr(T x) { return x * x; }

const int maxn = 2 * 1000 * 1000;

vi g[maxn];
bool u[maxn];

int dfs(int x) {
    u[x] = true;
    int res = sz(g[x]) % 2;
    for (int i = 0; i < sz(g[x]); ++i)
        if (!u[g[x][i]]) res += dfs(g[x][i]);
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        g[x].pb(y);
        g[y].pb(x);
    }
    vi v;
    for (int i = 0; i < n; ++i)
        if ((i == 0 || sz(g[i])) && !u[i]) {
            int val = dfs(i);
            v.pb(val);
        }
    int s = 0;
    int z = 0;
    for (int i = 0; i < sz(v); ++i) {
        s += v[i];
        if (v[i] == 0) ++z;
    }
    int res = 0;
    if (z == 0) res = s / 2;
    else if (s == 0) res = z <= 1 ? 0 : z;
    else {
        res = s / 2 + z;
    }
    cout << res << "\n";
    return 0;
}