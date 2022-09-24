#include <bits/stdc++.h>
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
using namespace std;
typedef long long ll;


int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif


    int n;
    while (cin >> n) {
        vector<int> p(n, -1);
        for (int i = 1; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }

        vector<int> cntCh(n);
        vector<int> cntChLe(n);
        for (int i = n - 1; i >= 1; i--) {
            cntCh[p[i]]++;
            if (cntCh[i] == 0) {
                cntChLe[p[i]]++;
            } else {

            }
        }
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            ok &= cntCh[i] == 0 || cntChLe[i] >= 3;
        }
        cout << (ok ? "Yes" : "No") << endl;
    }


#ifdef HOME
    eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}