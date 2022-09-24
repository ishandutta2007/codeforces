#include <bits/stdc++.h>
#define pw(x) (1LL << (x))
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;

const string FINITE = "Finite";
const string INFINITE = "Infinite";

string solve(ll p, ll q, ll b) {
    p %= q;

    ll g = __gcd(p, q);
    p /= g;
    q /= g;

    // if p * b^k divides by q

    ll cg = __gcd(b, q);
    while (1) {
        cg = __gcd(cg, q);
        if (cg == 1) break;
        q /= cg;
    }

    return q == 1 ? FINITE : INFINITE;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int T;
    while (scanf("%d", &T) == 1) {
        while (T--) {
            ll p, q, b;
            scanf("%lld%lld%lld", &p, &q, &b);
            printf("%s\n", solve(p, q, b).c_str());
        }
    }

#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}