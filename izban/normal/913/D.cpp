#include <bits/stdc++.h>
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
using namespace std;
typedef long long ll;


int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif


    int n, t;
    while (scanf("%d%d", &n, &t) == 2) {
        vector<pair<pair<int, int>, int> > a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a[i].first.second, &a[i].first.first);
            a[i].second = i;
        }
        sort(a.begin(), a.end());

        auto f = [&](int x) {
            int csum = 0;
            vector<int> res;
            for (int i = 0; i < n; i++) {
                if (a[i].first.second >= x && (int)res.size() < x) {
                    res.push_back(a[i].second + 1);
                    csum += a[i].first.first;
                }
            }
            if (csum > t || (int)res.size() < x) res.clear();
            return res;
        };

        int L = 0, R = n + 1;
        while (R - L > 1) {
            int M = (L + R) >> 1;

            vector<int> b = f(M);
            if (b.empty()) R = M;
            else L = M;
        }
        auto b = f(L);
        printf("%d\n%d\n", (int)b.size(), (int)b.size());
        for (int i = 0; i < (int)b.size(); i++) printf("%d%c", b[i], " \n"[i + 1 == (int)b.size()]);

    }


#ifdef HOME
    eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}