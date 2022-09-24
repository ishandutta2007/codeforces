#include <bits/stdc++.h>
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
using namespace std;
typedef long long ll;


int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif


    int n, l;
    while (cin >> n >> l) {
        vector<int> c(n);
        for (int i = 0; i < n; i++) cin >> c[i];
        for (int i = 0; i < n - 1; i++) c[i + 1] = min(c[i + 1], 2 * c[i]);

        ll ans = 4e18;
        ll cost = 0;
        for (int i = n - 1; i >= 0; i--) {
            int cnt = l / (1 << i);
            cost += 1LL * cnt * c[i];
            l %= 1 << i;

            ll o = cost;
            if (l) o += c[i];
            ans = min(ans, o);
        }
        cout << ans << endl;
    }


#ifdef HOME
    eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}