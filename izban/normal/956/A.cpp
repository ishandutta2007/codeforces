#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1.01e9;

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n, m;
    while (cin >> n >> m) {
        vector<string> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        bool ok = 1;
        for (int i = 0; i < n; i++) {
            vector<int> vct;
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '#') {
                    vct.push_back(j);
                }
            }
            vector<int> rr;
            for (int r = i; r < n; r++) {
                bool any = 0;
                for (int j : vct) if (a[r][j] == '#') any = 1;
                if (any) rr.push_back(r);
            }
            for (int r : rr) {
                ok &= a[r] == a[i];
            }
            for (int r : rr) {
                a[r] = string(m, '.');
            }
        }
        string ans = ok ? "Yes" : "No";
        cout << ans << endl;
    }

    return 0;
}