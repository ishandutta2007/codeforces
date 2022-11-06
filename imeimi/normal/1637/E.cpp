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

ll get(pii a, pii b) {
    return 1ll * (a.first + b.first) * (a.second + b.second);
}

ll solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> C;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        ++C[a];
    }
    set<pii> B;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        B.emplace(x, y);
        B.emplace(y, x);
    }
    map<int, vector<int>> A;
    for (auto [i, j] : C) {
        B.emplace(i, i);
        A[j].push_back(i);
    }
    for (auto &[_, V] : A) reverse(V.begin(), V.end());
    ll ans = 0;
    for (auto [i, X] : A) for (auto [j, Y] : A) {
        if (i > j) continue;
        vector<pii> S;
        set<pii> V;
        S.emplace_back(0, 0);
        while (!S.empty()) {
            auto [a, b] = S.back();
            S.pop_back();
            if (V.count(pii(a, b))) continue;
            if (a >= int(X.size()) || b >= int(Y.size())) continue;
            V.emplace(a, b);
            if (B.count(pii(X[a], Y[b]))) {
                S.emplace_back(a + 1, b);
                S.emplace_back(a, b + 1);
            }
            else {
                ans = max(ans, get(pii(i, X[a]), pii(j, Y[b])));
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) printf("%lld\n", solve());
    return 0;
}