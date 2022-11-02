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

const int maxn = 5700;

vector<ii> g[maxn];
vi cur[maxn];

vi pr;
int n;

bool cmp(int x, int y) {
    return pr[x] > pr[y];
}

void dfs(int x, int par, int c) {
    if (par != -1) {
        sort(all(cur[x]), cmp);
        for (int i = 0; i < c && sz(cur[x]); ++i) {
            cur[par].pb(cur[x][sz(cur[x]) - 1]);
            cur[x].pop_back();
        }
    }
    for (int i = 0; i < sz(g[x]); ++i)
        if (g[x][i].first != par)
            dfs(g[x][i].first, x, g[x][i].second);
}

int main()
{
    cin >> n;
    pr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> pr[i];
        cur[i].pb(i);
    }
    for (int i = 0; i < n - 1; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        --x, --y;
        g[x].pb(ii(y, c));
        g[y].pb(ii(x, c));
    }
    vi d(n, 1000 * 1000 * 1000);
    d[0] = 0;
    int T = 0;
    while (sz(cur[0]) < n) {
        ++T;
        dfs(0, -1, -1);
        for (int i = 0; i < sz(cur[0]); ++i)
            d[cur[0][i]] = min(d[cur[0][i]], T);
    }
    
    for (int i = 0; i < n; ++i)
        cout << d[i] << " ";
    cout << "\n";
    return 0;
}