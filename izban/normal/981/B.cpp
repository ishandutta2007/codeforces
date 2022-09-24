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

    map<int, int> mp;
    for (int it = 0; it < 2; it++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            mp[a] = max(mp[a], b);
        }
    }
    ll ans = 0;
    for (auto it : mp) ans += it.second;
    cout << ans << endl;

#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}