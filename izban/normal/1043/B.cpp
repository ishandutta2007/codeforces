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



int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n;
    while (cin >> n) {
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<int> ans;
        for (int k = 1; k <= n; k++) {
            vector<vector<int>> b(k);
            for (int i = 1; i <= n; i++) {
                b[(i - 1) % k].push_back(a[i] - a[i - 1]);
            }
            bool ok = 1;
            for (int i = 0; i < k; i++) {
                ok &= *min_element(b[i].begin(), b[i].end()) == *max_element(b[i].begin(), b[i].end());
            }
            if (ok) ans.push_back(k);
        }
        printf("%d\n", (int)ans.size());
        for (int i = 0; i < (int)ans.size(); i++) printf("%d%c", ans[i], " \n"[i + 1 == (int)ans.size()]);
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}