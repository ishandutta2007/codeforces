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

    int x, d;
    while (cin >> x >> d) {

        vector<ll> a;
        ll t = 1;
        ll C = 3e9;

        while (x > 0) {
            int k = 1;
            while ((1LL << k) - 1 <= x) {
                k++;
            }
            k--;

            x -= (1LL << k) - 1;
            for (int i = 0; i < k; i++) a.push_back(t);

            t += C;
        }

        cout << a.size() << endl;
        for (int i = 0; i < (int)a.size(); i++) cout << a[i] << " \n"[i + 1 == (int)a.size()];
    }


#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}