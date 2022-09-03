#pragma GCC optimize("Ofast")
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
const ll INF = (ll)(1e18 + 239);
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
const int T = (1 << 18) + 239;
const int B = 50;
const int X = 1e4 + 239;

int n, k, a;
int c[X];

int cnt[X];
pair<int, int> ans[X];

void add(int i, int l, int r) {
    ans[i] = make_pair(l, r);
    //cout << l + 1 << " " << r + 1 << "\n";
    for (int i = l; i <= r; i++) {
        cnt[i]++;
    }
}

int getmax(int l, int r) {
    int mx = 0;
    for (int i = l; i <= r; i++) {
        mx = max(mx, cnt[i]);
    }
    return mx;
}

vector<pair<int, int>> in[X];
bool used[X];

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n * k; i++) {
        cin >> c[i];
        c[i]--;
    }
    a = (n + k - 2) / (k - 1);
    for (int i = 0; i < n; i++) {
        vector<int> v;
        for (int t = 0; t < n * k; t++) {
            if (c[t] == i) {
                v.emplace_back(t);
            }
        }
        for (int j = 0; j < k - 1; j++) {
            in[v[j + 1]].emplace_back(-v[j], i);
        }
    }
    for (int i = 0; i < n; i++) {
        ans[i] = make_pair(-1, -1);
    }
    for (int t = 0; t < n * k; t++) {
        for (const auto& u : in[t]) {
            int c = u.second;
            int l = -u.first;
            if (!used[c] && getmax(l, t) <= a - 1) {
                used[c] = true;
                add(c, l, t);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == make_pair(-1, -1)) {
            exit(239);
        }
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }
    return 0;
}