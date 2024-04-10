/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

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
const ld eps = 1e-10;
const ll INF = (ll)(4e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353; //1e9 + 7;
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
const int L = 21;
const int T = (1 << 20) + 239;
const int B = 510;
const int X = 1010;

int par[M], rg[M], par2[M];

int find(int s) {
    if (s == par[s]) {
        return s;
    }
    return (par[s] = find(par[s]));
}

bool merge(int s, int f) {
    s = find(s);
    f = find(f);
    if (s == f) {
        return false;
    }
    if (rg[s] > rg[f]) {
        swap(s, f);
    }
    par[s] = f;
    if (rg[s] == rg[f]) {
        rg[f]++;
    }
    return true;
}

int find2(int s) {
    if (s == par2[s]) {
        return s;
    }
    return (par2[s] = find2(par2[s]));
}

bool merge2(int s, int f) {
    s = find2(s);
    f = find2(f);
    if (s == f) {
        return false;
    }
    par2[s] = f;
    return true;
}

int n, m, s[M], f[M], w[M], xr;
vector<int> v[M];

bool used[M];
set<int> non_used;

void bfs(int st) {
    queue<int> q;
    q.push(st);
    non_used.erase(st);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        merge(st, p);
        used[p] = true;

        set<int> ban;
        for (int i : v[p]) {
            ban.insert(s[i] ^ f[i] ^ p);
        }
        set<int> new_non_used;
        for (int t : non_used) {
            if (ban.find(t) == ban.end()) {
                q.push(t);
            } else {
                new_non_used.insert(t);
            }
        }
        non_used = new_non_used;
    }
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    xr = 0;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++) {
        cin >> s[i] >> f[i] >> w[i];
        s[i]--, f[i]--;
        v[s[i]].emplace_back(i);
        v[f[i]].emplace_back(i);
        xr ^= w[i];
        edges.emplace_back(w[i], s[i], f[i]);
    }
    for (int i = 0; i < n; i++) {
        par[i] = i;
        par2[i] = i;
        rg[i] = 0;
        non_used.insert(i);
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            bfs(i);
            k++;
        }
    }
    sort(edges.begin(), edges.end());
    int pl = xr;
    ll ans = 0;
    for (const auto& t : edges) {
        if (merge(get<1>(t), get<2>(t))) {
            merge2(get<1>(t), get<2>(t));
            ans += get<0>(t);
        } else {
            if (find2(get<1>(t)) != find2(get<2>(t))) {
                pl = min(pl, get<0>(t));
            }
        }
    }
    if (m + n - k == (((ll)n * (ll)(n - 1)) / 2LL)) {
        ans += pl;
    }
    cout << ans << "\n";
    return 0;
}