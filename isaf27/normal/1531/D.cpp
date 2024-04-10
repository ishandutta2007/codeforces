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
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 510;
const int X = 2010;

map<string, int> col_to_id;
vector<string> colors = {"red", "orange", "yellow", "green", "blue", "indigo", "violet"};

struct Info {
    std::array<int, 14> go;

    Info() = default;

    explicit Info(const string& s) {
        if (s == "lock") {
            for (int i = 0; i < 7; i++) {
                go[2 * i] = 2 * i + 1;
                go[2 * i + 1] = 2 * i + 1;
            }
        } else if (s == "unlock") {
            for (int i = 0; i < 7; i++) {
                go[2 * i] = 2 * i;
                go[2 * i + 1] = 2 * i;
            }
        } else {
            int id = col_to_id[s];
            for (int i = 0; i < 14; i++) {
                if (i % 2 == 1) {
                    go[i] = i;
                } else {
                    go[i] = 2 * id;
                }
            }
        }
    }

    Info operator+(const Info& other) const {
        Info res;
        for (int i = 0; i < 14; i++) {
            res.go[i] = other.go[go[i]];
        }
        return res;
    }
};

Info state[T];
string init[M];
int n;

void build(int i, int l, int r) {
    if (r - l == 1) {
        state[i] = Info(init[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid, r);
    state[i] = state[2 * i + 1] + state[2 * i + 2];
}

void upd(int i, int l, int r, int id, const string& color) {
    if (r - l == 1) {
        state[i] = Info(color);
        return;
    }
    int mid = (l + r) / 2;
    if (id < mid) {
        upd(2 * i + 1, l, mid, id, color);
    } else {
        upd(2 * i + 2, mid, r, id, color);
    }
    state[i] = state[2 * i + 1] + state[2 * i + 2];
}

string query() {
    return colors[state[0].go[8] / 2];
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    for (int i = 0; i < (int)colors.size(); i++) {
        col_to_id[colors[i]] = i;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> init[i];
    }
    build(0, 0, n);
    cout << query() << "\n";
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int id;
        string color;
        cin >> id >> color;
        id--;
        upd(0, 0, n, id, color);
        cout << query() << "\n";
    }
    return 0;
}