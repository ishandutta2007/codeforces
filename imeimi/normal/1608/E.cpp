#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lf, lf> pff;

int n;
vector<pii> P[3];

void compress(vector<int> &V) {
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
}

int C[3][100005];

int solve() {
    memset(C, 0, sizeof(C));
    int i0 = 0, i1 = 0, i2 = 0;
    int y = 0, up = 0, dn = 0;
    int ret = 0;
    for (int x = 0; x <= n; ++x) {
        while (i0 < n / 3 && P[0][i0].first <= x) ++i0;
        while (i1 < n / 3 && P[1][i1].first <= x) {
            int py = P[1][i1++].second;
            ++C[1][py];
            if (py > y) ++up;
        }
        while (i2 < n / 3 && P[2][i2].first <= x) {
            int py = P[2][i2++].second;
            ++C[2][py];
            if (py <= y) ++dn;
        }
        ret = max(ret, min({ up, dn, n / 3 - i0 }));
        while (up < dn) {
            up += C[1][y];
            dn -= C[2][y];
            --y;
            ret = max(ret,  min({ up, dn, n / 3 - i0 }));
        }
        while (up > dn) {
            up -= C[1][y + 1];
            dn += C[2][y + 1];
            ++y;
            ret = max(ret,  min({ up, dn, n / 3 - i0 }));
        }
    }
    return ret;
}

int solve2() {
    memset(C, 0, sizeof(C));
    int i0 = 0, i1 = 0, i2 = 0;
    int y = 0, up = 0, dn = 0;
    int ret = 0;
    for (int x = 0; x <= n; ++x) {
        while (i0 < n / 3 && P[0][i0].first <= x) ++i0;
        while (i1 < n / 3 && P[1][i1].first <= x) {
            int py = P[1][i1++].first;
            ++C[1][py];
            if (py > y) ++up;
        }
        while (i2 < n / 3 && P[2][i2].first <= x) {
            int py = P[2][i2++].first;
            ++C[2][py];
            if (py <= y) ++dn;
        }
        ret = max(ret, min({ up, dn, n / 3 - i0 }));
        while (up < dn) {
            up += C[1][y];
            dn -= C[2][y];
            --y;
            ret = max(ret,  min({ up, dn, n / 3 - i0 }));
        }
        while (up > dn) {
            up -= C[1][y + 1];
            dn += C[2][y + 1];
            ++y;
            ret = max(ret,  min({ up, dn, n / 3 - i0 }));
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    vector<int> X, Y;
    for (int i = 1; i <= n; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        P[c - 1].emplace_back(x, y);
        X.push_back(x);
        Y.push_back(y);
    }
    compress(X);
    compress(Y);
    for (int i = 0; i < 3; ++i) {
        for (auto &[x, y] : P[i]) {
            x = upper_bound(X.begin(), X.end(), x) - X.begin();
            y = upper_bound(Y.begin(), Y.end(), y) - Y.begin();
        }
    }
    int ans = 0;
    for (int xy = 0; xy < 2; ++xy) {
        for (int i = 0; i < 3; ++i) sort(P[i].begin(), P[i].end());
        for (int f = 0; f < 2; ++f) {
            ans = max(ans, solve());
            swap(P[0], P[1]);
            ans = max(ans, solve());
            swap(P[0], P[2]);
            ans = max(ans, solve());
            swap(P[1], P[2]);
            ans = max(ans, solve());
            swap(P[0], P[1]);
            ans = max(ans, solve());
            swap(P[0], P[2]);
            ans = max(ans, solve());
            swap(P[1], P[2]);
            for (int i = 0; i < 3; ++i) {
                for (auto &[x, y] : P[i]) x = n + 1 - x;
                reverse(P[i].begin(), P[i].end());
            }
        }
            ans = max(ans, solve2());
            swap(P[0], P[1]);
            ans = max(ans, solve2());
            swap(P[0], P[2]);
            ans = max(ans, solve2());
            swap(P[1], P[2]);
            ans = max(ans, solve2());
            swap(P[0], P[1]);
            ans = max(ans, solve2());
            swap(P[0], P[2]);
            ans = max(ans, solve2());
            swap(P[1], P[2]);
        for (int i = 0; i < 3; ++i) {
            for (auto &[x, y] : P[i]) swap(x, y);
        }
    }
    printf("%d\n", ans * 3);
    return 0;
}