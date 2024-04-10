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

const int INF = 1e9;

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n, k;
    while (scanf("%d%d", &n, &k) == 2) {
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            static char buf[111111];
            scanf("%s", buf);
            a[i] = buf;
        }

        vector<vector<int>> b(n, vector<int>(n, INF));
        b[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                b[i][j] += a[i][j] != 'a';
                if (i + 1 < n) {
                    b[i + 1][j] = min(b[i + 1][j], b[i][j]);
                }
                if (j + 1 < n) {
                    b[i][j + 1] = min(b[i][j + 1], b[i][j]);
                }
            }
        }

        vector<pair<int, int>> ans;
        ans.push_back({0, -1});
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (b[i][j] <= k) {
                    if (i + j < ans.back().first + ans.back().second) continue;
                    if (i + j > ans.back().first + ans.back().second) {
                        ans.clear();
                    }
                    ans.push_back({i, j});
                }
            }
        }
        string res = "";
        for (int x = 0; x <= ans.back().first + ans.back().second; x++) res += 'a';

        while (ans.back() != make_pair(n - 1, n - 1)) {
            vector<pair<int, int>> nans;
            for (auto o : ans) {
                int x = o.first, y = o.second;
                if (x + 1 < n && y >= 0) {
                    nans.push_back({x + 1, y});
                }
                if (y + 1 < n && x >= 0) {
                    nans.push_back({x, y + 1});
                }
            }
            sort(nans.begin(), nans.end());
            nans.resize(unique(nans.begin(), nans.end()) - nans.begin());
            char best = 'z';
            for (auto o : nans) best = min(best, a[o.first][o.second]);
            res += best;
            ans.clear();
            for (auto o : nans) if (a[o.first][o.second] == best) ans.push_back(o);
        }
        cout << res << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}