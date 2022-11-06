#include <bits/stdc++.h>

using namespace std;

#define sqr(x) ((x)*(x))
#define I(i, a) for (auto i: (a))
#define F(i, st, en) for (auto i = (st); i < (en); ++i)
#define DF(i, st, en) for (auto i = (st); i > (en); --i)
#define E(i, st, en) for (auto i = (st); i <= (en); ++i)
#define fin(st) freopen(st, "r", stdin)
#define fout(st) freopen(st, "w", stdout)
#define pb push_back
#define mp make_pair
#define cont continue
#define ret return
#define ins insert
#define sz(a) ((int)(a).size())
#define X first
#define Y second
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(0);cin.tie(0)

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;
typedef vector <int> vi;

const int maxn = 55;
const int mod = (int)1e9 + 7;
const dbl eps = 1e-8;
const int inf = 1e9;
const ll linf = 1e18;

struct action {
    int x1, y1, x2, y2;
};

struct pt {
    int x, y, i;
};

int n;
char used[maxn][maxn];
pii parent[maxn][maxn];

bool bfs(int sx, int sy, int fx, int fy, const vector<pt> &cur, vector<action> &path) {
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= n + 1; ++j) {
            used[i][j] = (i == 0 || j == 0 || i == n + 1 || j == n + 1);
            parent[i][j] = {0, 0};
        }
    }
    for (auto &p: cur) {
        used[p.x][p.y] = true;
    }
    queue<pii> q;
    q.emplace(sx, sy);
    used[sx][sy] = true;
    parent[sx][sy] = {sx, sy};
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (abs(i) + abs(j) != 1) continue;
                int nx = x + i, ny = y + j;
                if (!used[nx][ny]) {
                    used[nx][ny] = true;
                    parent[nx][ny] = {x, y};
                    q.emplace(nx, ny);
                }
            }
        }
    }
    if (parent[fx][fy].first == 0) return false;
    while (fx != sx || fy != sy) {
        int px, py;
        tie(px, py) = parent[fx][fy];
        path.push_back({px, py, fx, fy});
        fx = px; fy = py;
    }
    reverse(path.begin(), path.end());
    return true;
}

int getlen(int sx, int sy, int fx, int fy, const vector<pt> &cur) {
    vector<action> path;
    if (!bfs(sx, sy, fx, fy, cur, path)) return inf;
    return sz(path);
}

void extend(vector<action> &a, const vector<action> &b) {
    for (auto i: b) a.push_back(i);
}

void shift_to_second(vector<pt> &cur, const vector<pt> &need, vector<action> &actions) {
    for (int i = 1; i <= sz(cur); ++i) {
        int mind = inf;
        for (auto &p: cur) {
            if (p.x == 1 && p.y < i) continue;
            mind = min(mind, getlen(p.x, p.y, 1, i, cur));
        }
        for (auto &p: cur) {
            if (p.x == 1 && p.y < i) continue;
            if (mind == getlen(p.x, p.y, 1, i, cur)) {
                vector<action> path;
                bfs(p.x, p.y, 1, i, cur, path);
                extend(actions, path);
                p.x = 1;
                p.y = i;
                break;
            }
        }
    }
    for (auto &p: cur) {
        actions.push_back({p.x, p.y, p.x + 1, p.y});
        ++p.x;
    }
}

void shift_to_first(vector<pt> &cur, const vector<pt> &need, vector<action> &actions) {
    vector<int> order(sz(cur));
    for (int i = 0; i < sz(cur); ++i) {
        order[i] = i;
    }
    sort(order.begin(), order.end(), [&need] (int ai, int bi) {
         const pt &a = need[ai];
         const pt &b = need[bi];
         return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });
    for (int i = 0; i < sz(cur); ++i) {
        int id = order[i];
        vector<action> path;
        assert(bfs(cur[id].x, cur[id].y, 1, i + 1, cur, path));
        cur[id].x = 1;
        cur[id].y = i + 1;
        extend(actions, path);
    }
}

void sort_second(vector<int> &order, const vector<pt> &cur, const vector<pt> &need) {
    int l = inf, r = 0;
    for (int i = 0; i < sz(order); ++i) {
        if (need[order[i]].x == 2) {
            l = min(l, i);
            r = max(r, i);
        }
    }
    if (l > r) return;
    int pl = l, pr = r;
    vector<int> res;
    while (pl <= pr) {
        if (cur[order[pl]].y >= need[order[pl]].y) {
            res.push_back(order[pl++]);
        } else {
            res.push_back(order[pr--]);
        }
    }
    for (int i = 0; i < sz(res); ++i) {
        order[l + i] = res[i];
    }
}

vector<int> find_order(const vector<pt> &cur, const vector<pt> &need) {
    vector<int> order(sz(cur));
    for (int i = 0; i < sz(cur); ++i) {
        order[i] = i;
    }
    sort(order.begin(), order.end(), [&need] (int ai, int bi) {
         const pt &a = need[ai];
         const pt &b = need[bi];
         if (a.x != b.x) return a.x > b.x;
         if (a.x > 2) return false;
         if (a.x == 2) return a.y < b.y;
         if (a.x == 1) return a.y > b.y;
         assert(0);
    });
    sort_second(order, cur, need);
    return order;
}

int main() {
    //fin("t.in");
    sync;

    int m;
    cin >> n >> m;
    vector<pt> cur(m), need(m);
    for (int i = 0; i < m; ++i) {
        cin >> cur[i].x >> cur[i].y;
        cur[i].i = i;
    }
    for (int i = 0; i < m; ++i) {
        cin >> need[i].x >> need[i].y;
        need[i].i = i;
    }
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    vector<action> ans;
    shift_to_second(cur, need, ans);
    shift_to_first(cur, need, ans);
    vector<int> order = find_order(cur, need);
    for (auto i: order) {
        vector<action> path;
        assert(bfs(cur[i].x, cur[i].y, need[i].x, need[i].y, cur, path));
        extend(ans, path);
        cur[i] = need[i];
    }
    cout << sz(ans) << '\n';
    for (auto i: ans) {
        cout << i.x1 << ' ' << i.y1 << ' ';
        cout << i.x2 << ' ' << i.y2 << '\n';
    }

    return 0;
}