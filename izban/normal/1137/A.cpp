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


const int INF = 1.01e9;



int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
            }
        }

        vector<vector<int>> b(n);
        vector<int> mxR(n);
        for (int i = 0; i < n; i++) {
            vector<int> v = a[i];
            sort(v.begin(), v.end());
            v.resize(unique(v.begin(), v.end()) - v.begin());

            for (int x : a[i]) b[i].push_back(lower_bound(v.begin(), v.end(), x) - v.begin() + 1);
            mxR[i] = *max_element(b[i].begin(), b[i].end());
        }

        vector<vector<int>> ans(n, vector<int>(m));
        for (int j = 0; j < m; j++) {
            vector<int> v;
            for (int i = 0; i < n; i++) v.push_back(a[i][j]);
            sort(v.begin(), v.end());
            v.resize(unique(v.begin(), v.end()) - v.begin());

            vector<int> c;
            for (int i = 0; i < n; i++) c.push_back(lower_bound(v.begin(), v.end(), a[i][j]) - v.begin() + 1);

            int mxC = *max_element(c.begin(), c.end());
            for (int i = 0; i < n; i++) {
                ans[i][j] = max(ans[i][j], mxR[i] + max(0, c[i] - b[i][j]));
                ans[i][j] = max(ans[i][j], mxC + max(0, b[i][j] - c[i]));
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d%c", ans[i][j], " \n"[j + 1 == m]);
            }
        }
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}