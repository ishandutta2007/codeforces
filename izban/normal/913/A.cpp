#include <bits/stdc++.h>
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
using namespace std;
typedef long long ll;


int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif


    int n, m;
    while (cin >> n >> m) {
        int ans;
        if (n <= 30) {
            ans = m % (1LL << n);
        } else {
            ans = m;
        }
        cout << ans << endl;
    }


#ifdef HOME
    eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}