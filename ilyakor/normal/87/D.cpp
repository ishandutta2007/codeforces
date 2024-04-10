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
vi gind[maxn];

vi v;

int64 opt = -1;
vi cnt;

vi G[maxn];
vi Gind[maxn];
int val[maxn];

int u[maxn];
int uc[maxn];

int get(int x) {
    if (x == u[x]) return x;
    return u[x] = get(u[x]);
}

void uni(int x, int y) {
    if (rand() % 2)
        swap(x, y);
    x = get(x), y = get(y);
    if (x == y) return;
    uc[y] += uc[x];
    u[x] = y;
}

int64 sum = 0;

bool us[maxn];

void dfs0(int x, int p = -1) {
    us[x] = true;
    sum += val[x];
    for (int i = 0; i < sz(G[x]); ++i) {
        if (G[x][i] == p) continue;
        dfs0(G[x][i], x);
    }
}

int64 dfs(int x, int p = -1) {
    int64 res = val[x];
    for (int i = 0; i < sz(G[x]); ++i) {
        if (G[x][i] == p) continue;
        int64 t = dfs(G[x][i], x);
        int64 cur = t * (sum - t);
        if (cur > opt) {
            opt = cur;
            cnt.clear();
            cnt.pb(Gind[x][i]);
        }
        else if (cur == opt) 
            cnt.pb(Gind[x][i]);
        res += t;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        u[i] = i, uc[i] = 1;
    vector<pair<ii, ii> > e;
    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        --x, --y;
        g[x].pb(ii(y, z));
        g[y].pb(ii(x, z));
        gind[x].pb(i);
        gind[y].pb(i);
        v.pb(z);
        e.pb(mp(ii(z, i), ii(x, y)));
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < sz(g[i]); ++j) {
            int l = g[i][j].second;
            l = lower_bound(all(v), l) - v.begin();
            g[i][j].second = l;
        }

    sort(all(e));
    int cur = 0;
    while (cur < sz(e)) {
        int next = cur;
        vi w;
        while (next < sz(e) && e[next].first.first == e[cur].first.first) {
            w.pb(get(e[next].second.first));
            w.pb(get(e[next].second.second));
            ++next;
        }
        sort(all(w));
        w.erase(unique(all(w)), w.end());
        int m = sz(w);
        sum = 0;
        for (int i = 0; i < m; ++i) {
            G[i].clear();
            Gind[i].clear();
            val[i] = uc[w[i]];
            sum += val[i];
            us[i] = false;
        }
        for (int i = cur; i < next; ++i) {
            int x = lower_bound(all(w), get(e[i].second.first)) - w.begin();
            int y = lower_bound(all(w), get(e[i].second.second)) - w.begin();
            G[x].pb(y);
            G[y].pb(x);
            Gind[x].pb(e[i].first.second);
            Gind[y].pb(e[i].first.second);
        }
        for (int i = 0; i < m; ++i) {
            if (us[i]) continue;
            sum = 0;
            dfs0(i);
            dfs(i);
        }
        for (int i = cur; i < next; ++i) {
            uni(e[i].second.first, e[i].second.second);
        }
        cur = next;
    }

    sort(all(cnt));
    cout << (2LL * opt) << " " << sz(cnt) << "\n";
    for (int i = 0; i < sz(cnt); ++i)
        printf("%d ", cnt[i] + 1);
    printf("\n");
    return 0;
}