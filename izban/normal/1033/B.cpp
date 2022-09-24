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

const string YES = "YES";
const string NO = "NO";

string solve(ll a, ll b) {
    assert(a > b);
    if (a - b > 1) return NO;
    assert(a - b == 1);
    ll x = a + b;
    for (ll y = 2; y * y <= x; y++) {
        if (x % y == 0) {
            return NO;
        }
    }
    return YES;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int T;
    cin >> T;
    while (T--) {
        ll a, b;
        cin >> a >> b;

        cout << solve(a, b) << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}