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
const int MOD = 1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(5e3 + 10);
const int L = 21;
const int T = (1 << 20) + 239;
const int B = 510;
const int X = 110;

vector<int> v[M];
int n, s[M], f[M];
bool ban[M];

int fb[X], k;

int getid(int s) {
    for (int i = 1; i < k; i++) {
        if (fb[i] == s) {
            return i;
        }
    }
    return -1;
}

int sz[M];

void dfs(int p, int pr, int n1, int n2, int& store) {
    sz[p] = 1;
    for (int i : v[p]) {
        if (!ban[i]) {
            int to = s[i] ^ f[i] ^ p;
            if (to != pr) {
                dfs(to, p, n1, n2, store);
                if (sz[to] == n1) {
                    store = i;
                }
                if (sz[to] == n2) {
                    store = i;
                }
                sz[p] += sz[to];
            }
        }
    }
}

bool check(int p) {
    int id = -1;
    dfs(p, -1, -1, -1, id);
    if (sz[p] <= 3) {
        return true;
    }
    int t = getid(sz[p]);
    if (t == -1) {
        return false;
    }
    id = -1;
    dfs(p, -1, fb[t - 1], fb[t - 2], id);
    if (id == -1) {
        return false;
    }
    ban[id] = true;
    return check(s[id]) && check(f[id]);
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fb[0] = 1;
    fb[1] = 1;
    for (int i = 2; ; i++) {
        fb[i] = fb[i - 1] + fb[i - 2];
        if (fb[i] >= M) {
            k = i;
            break;
        }
    }
    /*cerr << k << "\n";
    for (int i = 0; i < k; i++) {
        cerr << f[i] << " ";
    }
    cerr << "\n";
    for (int i = 1; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            for (int h = j + 1; h < k; h++) {
                if (f[i] + f[j] == f[h] && h - i != 2) {
                    cerr << i << " " << j << " " << h << "!\n";
                }
            }
        }
    }*/
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> s[i] >> f[i];
        s[i]--, f[i]--;
        v[s[i]].emplace_back(i);
        v[f[i]].emplace_back(i);
    }
    cout << (check(0) ? "YES\n" : "NO\n");
    return 0;
}