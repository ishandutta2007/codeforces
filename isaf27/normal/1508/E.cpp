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
const int M = (int)(3e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 20) + 239;
const int B = 510;
const int X = 1010;

int n, a[M], par[M];
vector<int> v[M];
int b[M];
int h[M];

void init_b() {
    for (int i = 0; i < n; i++) {
        b[a[i]] = i;
    }
}

void dfs(int p, int last) {
    par[p] = last;
    if (last == -1) {
        h[p] = 0;
    } else {
        h[p] = h[last] + 1;
    }
    vector<int> go;
    for (int i : v[p]) {
        if (i != last) {
            go.emplace_back(i);
        }
    }
    v[p] = go;
    for (int i : v[p]) {
        dfs(i, p);
    }
}

bool live[M];

int timer;

bool dfs_check(int p) {
    if (a[p] != timer) {
        return false;
    }
    timer++;
    vector<pair<int, int>> to;
    for (int i : v[p]) {
        if (live[i]) {
            to.emplace_back(a[i], i);
        }
    }
    sort(to.begin(), to.end());
    for (const auto& t : to) {
        if (!dfs_check(t.second)) {
            return false;
        }
    }
    return true;
}

int mn[M];

int dfs_mn(int p) {
    int sum = mn[p];
    for (int i : v[p]) {
        sum += dfs_mn(i);
    }
    a[p] -= sum;
    return sum;
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n - 1; i++) {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].emplace_back(f);
        v[f].emplace_back(s);
    }
    dfs(0, -1);
    for (int i = 0; i < n; i++) {
        live[i] = true;
    }
    if (a[0] == 0) {
        timer = 0;
        if (!dfs_check(0)) {
            cout << "NO\n";
            return 0;
        }
        // check that the current configuration is dfs order
        cout << "YES\n0\n";
        for (int i = 0; i < n; i++) {
            cout << a[i] + 1 << " ";
        }
        cout << "\n";
        return 0;
    }
    int p = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[0] - 1) {
            p = i;
            break;
        }
    }
    ll ans = 0;
    while (p != 0) {
        if (a[p] > a[par[p]]) {
            cout << "NO\n";
            return 0;
        }
        for (int i : v[par[p]]) {
            if (i != p && a[i] < a[par[p]] && a[i] > a[p]) {
                cout << "NO\n";
                return 0;
            }
        }
        ans++;
        swap(a[p], a[par[p]]);
        p = par[p];
    }
    init_b();
    for (int i = 0; i < a[0]; i++) {
        int p = b[i];
        for (int i : v[p]) {
            if (live[i]) {
                cout << "NO\n";
                return 0;
            }
        }
        live[p] = false;
        ans += h[p];
    }
    timer = a[0];
    if (!dfs_check(0)) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 0; i < a[0]; i++) {
        int p = b[i];
        mn[par[p]]++;
        a[p] += h[p];
    }
    dfs_mn(0);
    for (int i = 0; i < n; i++) {
        if (a[i] < 0 || a[i] >= n) {
            cout << "NO\n";
            return 0;
        }
    }
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i] != 1) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] + 1 << " ";
    }
    cout << "\n";
    return 0;
}