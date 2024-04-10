#include <bits/stdc++.h>
#define pw(x) (1LL << (x))
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;

const string FINITE = "Finite";
const string INFINITE = "Infinite";


int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    const int m = 9;
    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a[i], &b[i]);
            a[i]--; b[i]--;
        }

        vector<vector<int>> vct;
        vector<int> cur;
        function<void(int)> rec = [&](int x) {
            if (x == m) {
                vct.push_back(cur);
                return;
            }
            rec(x + 1);
            if ((int)cur.size() < 4) {
                cur.push_back(x);
                rec(x);
                cur.pop_back();
            }
        };
        rec(0);
        sort(vct.begin(), vct.end());

        vector<vector<int>> go(vct.size(), vector<int>(m, -1));
        for (int i = 0; i < (int)vct.size(); i++) {
            for (int fl = 0; fl < m; fl++) {
                cur = vct[i];
                while (1) {
                    auto it = find(cur.begin(), cur.end(), fl);
                    if (it == cur.end()) break;
                    cur.erase(it);
                }
                go[i][fl] = lower_bound(vct.begin(), vct.end(), cur) - vct.begin();
            }
        }

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m, vector<int>(vct.size(), INF)));
        int si = 0, sj = 0;
        cur.clear();
        while (si < n && cur.size() < 4 && a[si] == sj) {
            cur.push_back(b[si++]);
            sort(cur.begin(), cur.end());
        }
        int sk = lower_bound(vct.begin(), vct.end(), cur) - vct.begin();

        dp[si][sj][sk] = 0;
        queue<pair<pair<int, int>, int>> q;
        q.push({{si, sj}, sk});
        int ans = INF;
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int k = q.front().second;
            q.pop();

            if (i == n && vct[k].empty()) {
                ans = min(ans, dp[i][j][k]);
            }
            for (int df = -1; df <= 1; df += 2) {
                int ni = i;
                int nj = j + df;
                if (!(0 <= nj && nj < m)) continue;
                int nk = go[k][nj];
                auto ncur = vct[nk];
                while (ni < n && ncur.size() < 4 && a[ni] == nj) {
                    ncur.push_back(b[ni++]);
                    sort(ncur.begin(), ncur.end());
                }
                nk = lower_bound(vct.begin(), vct.end(), ncur) - vct.begin();

                if (dp[ni][nj][nk] > dp[i][j][k] + 1) {
                    dp[ni][nj][nk] = dp[i][j][k] + 1;
                    q.push({{ni, nj}, nk});
                }
            }
        }
        cout << ans + 2 * n << endl;
    }

#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}