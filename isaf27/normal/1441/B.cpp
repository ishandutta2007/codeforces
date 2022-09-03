//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int two = 2;
const ld eps = 1e-10;
const ll INF = (ll)(2e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 20;
const int T = (1 << 20) + 239;
const int B = 510;
const int X = 30;

int dist[X][M];
int n, m;
vector<pair<int, int>> v[M];

typedef pair<int, int> dist_t;

dist_t f[2][M];

dist_t sum(dist_t a, dist_t b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].emplace_back(f, 0);
        v[f].emplace_back(s, 1);
    }
    for (int i = 0; i < X; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = BIG;
    dist[0][0] = 0;
    deque<pair<int, int>> q;
    q.push_back(make_pair(0, 0));
    while (!q.empty()) {
        int c = q.front().first;
        int p = q.front().second;
        q.pop_front();
        if (c + 1 < X && dist[c + 1][p] > dist[c][p]) {
            dist[c + 1][p] = dist[c][p];
            q.push_front(make_pair(c + 1, p));
        }
        for (pair<int, int> t : v[p]) {
            if (t.second == (c % 2)) {
                if (dist[c][t.first] > dist[c][p] + 1) {
                    dist[c][t.first] = dist[c][p] + 1;
                    q.push_back(make_pair(c, t.first));
                }
            }
        }
    }
    int ans = 2 * BIG;
    for (int i = 0; i < X; i++)
        if (dist[i][n - 1] != BIG)
            ans = min(ans, dist[i][n - 1] + (1 << i) - 1);
    if (ans < 2 * BIG) {
        cout << ans % MOD << "\n";
        return 0;
    }
    set<pair<dist_t, dist_t>> st;
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < n; i++)
            f[j][i] = make_pair(BIG, BIG);
    f[0][0] = make_pair(0, 0);
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < n; i++)
            st.insert(make_pair(f[j][i], make_pair(j, i)));
    while (!st.empty()) {
        pair<int, int> now = st.begin()->second;
        st.erase(st.begin());
        int c = now.first;
        int p = now.second;
        if (f[1 - c][p] > sum(f[c][p], make_pair(1, 0))) {
            st.erase(make_pair(f[1 - c][p], make_pair(1 - c, p)));
            f[1 - c][p] = sum(f[c][p], make_pair(1, 0));
            st.insert(make_pair(f[1 - c][p], make_pair(1 - c, p)));
        }
        for (pair<int, int> t : v[p]) {
            if (t.second == c) {
                if (f[c][t.first] > sum(f[c][p], make_pair(0, 1))) {
                    st.erase(make_pair(f[c][t.first], make_pair(c, t.first)));
                    f[c][t.first] = sum(f[c][p], make_pair(0, 1));
                    st.insert(make_pair(f[c][t.first], make_pair(c, t.first)));
                }
            }
        }
    }
    dist_t anss = min(f[0][n - 1], f[1][n - 1]);
    int res = 1;
    for (int i = 0; i < anss.first; i++) {
        res = (res + res) % MOD;
    }
    res = (res - 1 + anss.second) % MOD;
    cout << res << "\n";
    return 0;
}