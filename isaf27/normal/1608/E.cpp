#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const int BIG = (int)(1e9) + 239;
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
const int B = 2000;
const int X = 35;

int n, x[M], y[M], c[M], sx, sy;
vector<int> vx, vy;

vector<int> in[M];
int pref[M], suf[M];

int tree[2][M];

void clear() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < sy; j++) {
            tree[i][j] = 0;
        }
    }
}

int getsum(int t, int i) {
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
        ans += tree[t][i];
    }
    return ans;
}

void upd(int t, int i) {
    for (; i < sy; i |= i + 1) {
        tree[t][i]++;
    }
}

int solve(const vector<int>& p, bool nw) {
    if (nw) {
        for (int i = 0; i < sx; i++) {
            in[i].clear();
        }
        for (int i = 0; i < n; i++) {
            in[x[i]].emplace_back(i);
        }
    }

    //suf
    suf[sx] = 0;
    for (int i = sx - 1; i >= 0; i--) {
        suf[i] = suf[i + 1];
        for (int t : in[i]) {
            suf[i] += (c[t] == p[2]);
        }
    }

    //pref
    clear();
    for (int i = 0; i < sx; i++) {
        for (int t : in[i]) {
            if (c[t] == p[0]) {
                upd(0, y[t]);
            } else if (c[t] == p[1]) {
                upd(1, sy - 1 - y[t]);
            }
        }
        int l = 0;
        int r = sy;
        while (r - l > 1) {
            int h = (l + r) / 2;
            if (getsum(0, h - 1) <= getsum(1, sy - 1 - h)) {
                l = h;
            } else {
                r = h;
            }
        }
        pref[i] = 0;
        if (l > 0) {
            pref[i] = max(pref[i], min(getsum(0, l - 1), getsum(1, sy - 1 - l)));
        }
        if (r < sy) {
            pref[i] = max(pref[i], min(getsum(0, r - 1), getsum(1, sy - 1 - r)));
        }
    }

    int ans = 0;
    for (int i = 1; i < sx; i++) {
        ans = max(ans, min(pref[i - 1], suf[i]));
    }
    return ans;
}

int cnt[M][3];

bool check2(const vector<int>& p, int x) {
    int l = 0;
    int s = 0;
    for (int i = 0; i < sx; i++) {
        s += cnt[i][p[0]];
        if (s >= x) {
            l = i + 1;
            break;
        }
    }
    s = 0;
    int r = sx - 1;
    for (int i = sx - 1; i >= 0; i--) {
        s += cnt[i][p[2]];
        if (s >= x) {
            r = i - 1;
            break;
        }
    }
    s = 0;
    for (int i = l; i <= r; i++) {
        s += cnt[i][p[1]];
    }
    return (s >= x);
}

int solve2(const vector<int>& p) {
    for (int i = 0; i < sx; i++) {
        cnt[i][0] = 0;
        cnt[i][1] = 0;
        cnt[i][2] = 0;
    }
    for (int i = 0; i < n; i++) {
        cnt[x[i]][c[i]]++;
    }
    int l = 0;
    int r = (n / 3) + 1;
    while (r - l > 1) {
        int h = (l + r) / 2;
        if (check2(p, h)) {
            l = h;
        } else {
            r = h;
        }
    }
    return l;
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> c[i];
        c[i]--;
        vx.emplace_back(x[i]);
        vy.emplace_back(y[i]);
    }
    sort(vx.begin(), vx.end());
    vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
    sort(vy.begin(), vy.end());
    vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
    sx = vx.size();
    sy = vy.size();
    for (int i = 0; i < n; i++) {
        x[i] = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin();
        y[i] = lower_bound(vy.begin(), vy.end(), y[i]) - vy.begin();
    }
    int ans = 0;
    for (int it1 = 0; it1 < 2; it1++) {
        for (int it2 = 0; it2 < 2; it2++) {
            vector<int> p{0, 1, 2};
            bool nw = true;
            do {
                ans = max(ans, solve(p, nw));
                nw = false;
            } while (next_permutation(p.begin(), p.end()));

            for (int i = 0; i < n; i++) {
                x[i] = sx - x[i] - 1;
            }
        }

        vector<int> p{0, 1, 2};
        do {
            ans = max(ans, solve2(p));
        } while (next_permutation(p.begin(), p.end()));

        for (int i = 0; i < n; i++) {
            swap(x[i], y[i]);
        }
        swap(sx, sy);
    }
    cout << ans * 3 << "\n";
    return 0;
}