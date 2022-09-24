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

    ll A, B;
    while (cin >> A >> B) {

        vector<int> b;
        auto f = [&](ll M) {
            b.assign(M + 1, 1);

            ll curA = A;
            for (ll i = M; i >= 1; i--) {
                if (curA >= i) {
                    curA -= i;
                    b[i] = 0;
                }
            }
            ll sumB = 0;
            for (ll i = 1; i <= M; i++) if (b[i] == 1) sumB += i;
            return sumB <= B;
        };

        ll L = 0, R = 2e5;
        while (R - L > 1) {
            ll M = (L + R) >> 1;
            if (f(M)) L = M;
            else R = M;
        }
        f(L);

        vector<vector<int>> ans(2);
        for (int i = 1; i < (int)b.size(); i++) {
            ans[b[i]].push_back(i);
        }

        for (int i = 0; i < 2; i++) {
            printf("%d\n", (int)ans[i].size());
            for (int j = 0; j < (int)ans[i].size(); j++) {
                printf("%d%c", ans[i][j], " \n"[j + 1 == (int)ans[i].size()]);
            }
        }
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}