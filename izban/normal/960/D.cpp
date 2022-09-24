#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
#define pw(x) (1LL << (x))
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;


int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int q;
    while (scanf("%d", &q) == 1) {
        const int K = 61;
        vector<ll> shift(K);
        vector<ll> len(K);
        for (int i = 0; i < K; i++) {
            len[i] = 1LL << i;
        }

        while (q--) {
            int t;
            scanf("%d", &t);
            ll x;
            scanf("%lld", &x);
            int lvl = 0;
            while (x >= (1LL << (lvl + 1))) lvl++;

            if (t == 1) {
                ll k;
                scanf("%lld", &k);
                k %= len[lvl];
                if (k < 0) k += len[lvl];
                shift[lvl] = (shift[lvl] + k) % len[lvl];
            }
            if (t == 2) {
                ll k;
                scanf("%lld", &k);
                k %= len[lvl];
                if (k < 0) k += len[lvl];
                for (int clvl = lvl; clvl < K; clvl++) {
                    shift[clvl] = (shift[clvl] + k) % len[clvl];
                    k *= 2;
                }
            }
            if (t == 3) {
                vector<ll> ans;
                ll y = x;
                y %= len[lvl];
                y = (y + shift[lvl]) % len[lvl];
                y += len[lvl];
                for (int i = lvl; i >= 0; i--, y >>= 1) {
                    ll cy = y % len[i];
                    cy = (cy - shift[i] + len[i]) % len[i];
                    cy += len[i];
                    ans.push_back(cy);
                }
                for (int i = 0; i < (int)ans.size(); i++) printf("%lld%c", ans[i], " \n"[i + 1 == (int)ans.size()]);
            }
        }
    }


#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}