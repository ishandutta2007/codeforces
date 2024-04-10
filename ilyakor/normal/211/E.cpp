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

const int maxn = 5700;

vi g[maxn];
int n;

bool u[maxn];
bool d[maxn];
vi res;

int dfs(int x, int p = -1) {
    int res = 1;
    vi vc;
    for (int i = 0; i < sz(g[x]); ++i)
        if (g[x][i] != p) {
            int val = dfs(g[x][i], x);
            vc.pb(val);
            res += val;
        }
    vc.pb(n - res);
    memset(d, 0, sizeof(d));
    d[0] = true;
    for (int i = 0; i < sz(vc); ++i)
        for (int j = n; j >= vc[i]; --j)
            if (d[j - vc[i]]) d[j] = true;
    for (int i = 0; i <= n; ++i)
        if (d[i]) u[i] = true;
    return res;
}

int main() {    
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(0);
    for (int i = 1; i < n - 1; ++i)
        if (u[i]) res.pb(i);
    printf("%d\n", sz(res));
    for (int i = 0; i < sz(res); ++i)
        printf("%d %d\n", res[i], n - res[i] - 1);
    return 0;
}