#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;

int solve(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<pair<int, int>> vct;
    for (int j = 0; j < m; j++) {
        int mx = -1;
        for (int i = 0; i < n; i++) mx = max(mx, a[i][j]);
        vct.push_back({mx, j});
    }
    sort(vct.begin(), vct.end());
    reverse(vct.begin(), vct.end());

    if ((int)vct.size() > n) vct.resize(n);

    vector<vector<int>> na(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)vct.size(); j++) {
            na[i].push_back(a[i][vct[j].second]);
        }
    }
    a = na;
    m = vct.size();

    vector<int> dp(1 << n, 0);
    for (int j = 0; j < m; j++) {
        vector<int> ndp = dp;
        for (int s = 0; s < n; s++) {
            auto cdp = dp;
            for (int i = 0; i < n; i++) {
                for (int mask = 0; mask < (1 << n); mask++) {
                    if (!(mask & (1 << i))) {
                        cdp[mask | (1 << i)] = max(cdp[mask | (1 << i)], cdp[mask] + a[(s + i) % n][j]);
                    }
                }
            }
            for (int mask = 0; mask < (1 << n); mask++) ndp[mask] = max(ndp[mask], cdp[mask]);
        }
        dp = ndp;
    }
    return dp[(1 << n) - 1];
}

void test() {
    for (int t = 0; t < 40; t++) {
        int n = 12;
        int m = 2e3;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = rand() % (int)1e5;
            }
        }
        solve(a);

    }
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    exit(0);
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
//    test();

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
            }
        }


        cout << solve(a) << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}