#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <random>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl


using namespace std;

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#else
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, m, g, r;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<int> a(m);
        for (int i = 0; i < m; i++) scanf("%d", &a[i]);
        scanf("%d%d", &g, &r);
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        m = a.size();

        int per = g + r;
        vector<vector<ll>> d(m, vector<ll>(g + 1, INF));
        vector<vector<char>> vis(m, vector<char>(per));
        d[0][0] = 0;

        vector<vector<int>> verts(per);
        verts[0].push_back(0);

        priority_queue<ll, vector<ll>, greater<>> q;
        q.push(0);

        auto upd = [&](int ni, int nct, ll nt) {
            assert(nct <= g && nt % per == nct);
            if (d[ni][nct] > nt) {
                d[ni][nct] = nt;
                if (verts[nct].empty()) {
                    q.push(nt);
                }
                verts[nct].push_back(ni);
            }
        };

        while (!q.empty()) {
            ll t = q.top();
            q.pop();

            int ct = t % per;
            assert(ct <= g);

            while (!verts[ct].empty()) {
                auto vert = verts[ct].back();
                verts[ct].pop_back();
                int ci = vert;
                if (vis[ci][ct]) continue;
                vis[ci][ct] = 1;

                if (ct == g) {
                    ll nt = t / per * per + per;
                    upd(ci, 0, nt);
                }
                if (ci > 0) {
                    int ni = ci - 1;
                    ll nt = t + a[ci] - a[ni];
                    if (nt / per == t / per && nt % per <= g) {
                        int nct = nt % per;
                        upd(ni, nct, nt);
                    }
                }
                if (ci + 1 < m) {
                    int ni = ci + 1;
                    ll nt = t + a[ni] - a[ci];
                    if (nt / per == t / per && nt % per <= g) {
                        int nct = nt % per;
                        upd(ni, nct, nt);
                    }
                }
            }
        }
        ll res = INF;
        for (ll x : d[m - 1]) res = min(res, x);

        if (res == INF) res = -1;
        cout << res << endl;
    }

    return 0;
}