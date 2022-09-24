#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 17;


int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n, k;
    while (scanf("%d%d", &n, &k) == 2) {
        vector<int> a(n);
        vector<int> cnt(1 << k);
        for (int i = 0; i < n; i++) {
            int cmask = 0;
            for (int j = 0; j < k; j++) {
                int x;
                scanf("%d", &x);
                cmask = 2 * cmask + x;
            }
            cnt[cmask]++;
        }

        bool f = 0;
        if (cnt[0] > 0) f = 1;
        for (int m1 = 0; m1 < (1 << k); m1++) {
            for (int m2 = 0; m2 < (1 << k); m2++) {
                if (cnt[m1] > 0 && cnt[m2] > 0 && (m1 & m2) == 0) {
                    f = 1;
                }
            }
        }
        string res = f ? "YES" : "NO";
        cout << res << endl;
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}