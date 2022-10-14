#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1000005;
const llint INF = 1000000000000000000LL;
const int LOG = 20;

llint n, C, ofs = 1;
llint w[MAXN], a[MAXN], lef[MAXN][2], rig[MAXN], d[MAXN];
llint t[MAXN * 4][2];
pi dp[MAXN][2];
vector <int> add[MAXN], rem[MAXN];
set <int> st;
map <llint, int> mp[2];

void tour_init () {
    for (int i = ofs - 1; i > 0; i--) {
        t[i][0] = min(t[2 * i][0], t[2 * i + 1][0]);
        t[i][1] = min(t[2 * i][1], t[2 * i + 1][1]);
    }
}

int get_lef_0 (int x, llint lo, llint hi) {
    if (x >= ofs) return x - ofs;
    llint novi_lo = min(lo, t[2 * x + 1][0]), novi_hi = min(hi, t[2 * x + 1][1]);
    if (-novi_lo <= novi_hi) return get_lef_0(2 * x, novi_lo, novi_hi);
    return get_lef_0(2 * x + 1, lo, hi);
}

int get_lef_1 (int x, llint val) {
    if (x >= ofs) return x - ofs;
    if (-t[2 * x + 1][0] <= val && val <= t[2 * x + 1][1]) return get_lef_1(2 * x, val);
    return get_lef_1(2 * x + 1, val);
}

int get_rig_1 (int x, llint val) {
    if (x >= ofs) return x - ofs;
    if (-t[2 * x][0] <= val && val <= t[2 * x][1]) return get_rig_1(2 * x + 1, val);
    return get_rig_1(2 * x, val);
}

void precompute () {
    while (ofs < n + 1) ofs *= 2;
    for (int i = 0; i < 2 * ofs; i++) t[i][0] = t[i][1] = INF;
    for (int i = 0; i <= n + 1; i++) {
        if (i > 0) a[i] = w[i - 1] - a[i - 1];
        t[i + ofs][i % 2] = a[i];
    }
    tour_init();
    for (int i = 1; i <= n + 1; i++) {
        llint lo = t[i + ofs][0], hi = t[i + ofs][1];
        int pos = i + ofs;
        while (pos > 1) {
            if (pos % 2 == 1) {
                llint novi_lo = min(lo, t[pos - 1][0]), novi_hi = min(hi, t[pos - 1][1]);
                if (-novi_lo <= novi_hi) {
                    lo = novi_lo; hi = novi_hi;
                } else {
                    lef[i][0] = get_lef_0(pos - 1, lo, hi) + 1;
                    break;
                }
            }
            pos /= 2;
        }
        if (pos == 1) lef[i][0] = 0;

        llint val = (i % 2 == 0 ? -a[i] : a[i]);
        pos = i + ofs;
        while (pos > 1) {
            if (pos % 2 == 1 && !(-t[pos - 1][0] <= val && val <= t[pos - 1][1])) {
                lef[i][1] = get_lef_1(pos - 1, val) + 1;
                break;
            }
            pos /= 2;
        }
        if (pos == 1) lef[i][1] = 0;
    }
    for (int i = 0; i <= n; i++) {
        llint val = (i % 2 == 0 ? -a[i] : a[i]);
        int pos = i + ofs;
        while (pos > 1) {
            if (pos % 2 == 0 && !(-t[pos + 1][0] <= val && val <= t[pos + 1][1])) {
                rig[i] = min((int)n + 1, get_rig_1(pos + 1, val) - 1);
                break;
            }
            pos /= 2;
        }
        if (pos == 1) rig[i] = n + 1;
    }
}

void calc () {
    int ind = 0;
    mp[0][0] = 0;
    for (int pos = 1; pos <= n; pos++) {
        dp[pos][0] = dp[pos][1] = {-1, -1};
        for (auto x : add[pos]) st.insert(x);
        for (auto x : rem[pos]) st.erase(x);
        if (lef[pos + 1][0] <= ind) {
            dp[pos][0] = {ind, 1};
        } else if (!st.empty()) {
            int val = *st.rbegin();
            if (lef[pos + 1][0] <= val) dp[pos][0] = {val, 0};
        }

        if (lef[pos + 1][1] <= ind) {
            dp[pos][1] = {ind, 1};
        } else {
            llint val = (pos % 2 == 0 ? -a[pos + 1] : a[pos + 1]);
            if (mp[0].find(val) != mp[0].end() && lef[pos + 1][1] <= mp[0][val]) dp[pos][1] = {mp[0][val], 0};
            if (mp[1].find(-val) != mp[1].end() && lef[pos + 1][1] <= mp[1][-val]) dp[pos][1] = {mp[1][-val], 0};
        }

        if (dp[pos][0].first != -1) {
            add[pos + 1].push_back(pos);
            rem[rig[pos]].push_back(pos);
            mp[pos % 2][a[pos]] = pos;
        }
        if (dp[pos][1].first != -1) {
            ind = pos;
        }
    }
}

void solve_lef (int a, int b, int sign) {
    d[a] = w[a - 1];
    for (int i = a + 1; i <= b; i++) {
        d[i] = w[i - 1] - d[i - 1];
    }
    for (int i = a; i <= b; i++) d[i] *= sign;
}

void solve_rig (int a, int b, int sign) {
    d[b] = w[b];
    for (int i = b - 1; i >= a; i--) {
        d[i] = w[i] - d[i + 1];
    }
    for (int i = a; i <= b; i++) d[i] *= sign;
}

void reconstruct () {
    int pos = n, flg = 0, sign = 1;
    while (pos > 0) {
        int nxt = dp[pos][flg].first;
        int novi_flg = dp[pos][flg].second;
        if (flg) solve_rig(nxt + 1, pos, sign); else solve_lef(nxt + 1, pos, sign);
        pos = nxt; flg = novi_flg;
        sign *= -1;
    }
    llint mn = 0;
    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
        mn = min(mn, d[i]);
    }
    cout << "YES\n";
    for (int i = 0; i <= n; i++) {
        cout << d[i] - mn << " ";
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> C;
    n--;
    w[0] = w[n] = C;
    for (int i = 1; i <= n-1; i++) {
        cin >> w[i];
    }
    precompute();
    calc();
    if (dp[n][0].first == -1) {
        cout << "NO";
    } else {
        reconstruct();
    }
    return 0;
}