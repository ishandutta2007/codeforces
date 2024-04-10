#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

const int maxn = 305;
const int inf = 1e9+100500;

int n, m, p;
vector<pii> pos[maxn*maxn];
void scan() {
    scanf("%d%d%d", &n, &m, &p);
    forn(i, n) forn(j, m) {
        int x;
        scanf("%d", &x);
        pos[x-1].pb({i, j});
    }
}

int dist(const pii& a, const pii& b) {
    return abs(a.fi-b.fi) + abs(a.se-b.se);
}

vector<pair<int, pii>> cur;

int d[maxn][maxn];
pii q[maxn*maxn];

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,1,-1};

void bfs(const vector<pii>& to) {
    sort(all(cur));
    forn(i, n) forn(j, m) d[i][j] = inf;
    int cd = cur[0].fi;
    size_t ptr = 0;
    int lq = 0, rq = 0;

    while (true) {
        while (ptr != cur.size() && cur[ptr].fi == cd) {
            int x, y;
            tie(x, y) = cur[ptr++].se;
            if (d[x][y] > cd) {
                d[x][y] = cd;
                q[rq++] = {x, y};
            }
        }
        if (lq == rq) break;
        int x, y;
        tie(x, y) = q[lq++];
        forn(i, 4) {
            int tx = x+dx[i];
            int ty = y+dy[i];
            if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
            if (d[tx][ty] > d[x][y] + 1) {
                d[tx][ty] = d[x][y] + 1;
                cd = d[tx][ty];
                q[rq++] = {tx, ty};
            }
        }
    }

    cur.clear();
    for (const auto& xy: to) cur.pb({d[xy.fi][xy.se], xy});
}

void solve() {
    for (auto xy: pos[0]) cur.pb({xy.fi+xy.se, xy});
    forn(i, p-1) {
        if (max(cur.size(), pos[i+1].size()) >= 300u) {
            bfs(pos[i+1]);
        } else {
            vector<pair<int, pii>> nxt;
            for (auto xy: pos[i+1]) {
                int d = inf;
                for (const auto& dxy: cur) {
                    d = min(d, dxy.fi + dist(xy, dxy.se));
                }
                nxt.pb({d, xy});
            }
            cur = nxt;
        }
    }
    cout << cur[0].fi << endl;
}

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
#endif

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}