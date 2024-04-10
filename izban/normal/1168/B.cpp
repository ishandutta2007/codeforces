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


const int INF = 1.01e9;

ll solve(string s) {
    int n = s.length();
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = s[i] - '0';

    ll ans = 0;

    for (int l = 0; l < n; l++) {
        bool ok = 0;
        int r = l;
        while (1) {
            r++;
            if (r == n) break;
            for (int d = 1; r - 2 * d >= l; d++) {
                if (a[r] == a[r - d] && a[r] == a[r - d - d]) {
                    ok = 1;
                    break;
                }
            }
            if (ok) break;
        }
        assert(r - l <= 12);
        ans += n - r;
    }

    return ans;
}

void test() {
    for (int n = 1; n <= 15; n++) {
        bool ok = 1;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> a;
            for (int i = 0; i < n; i++) a.push_back((mask >> i) & 1);

            bool f = 0;
            for (int i = 0; i < n; i++) {
                for (int d = 1; i + 2 * d < n; d++) {
                    f |= a[i] == a[i + d] && a[i + d] == a[i + d + d];
                }
            }
            ok &= f;
        }
        if (ok) {
            db(n);
            exit(0);
        }
    }
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
//    test();


    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while (cin >> s) {
        cout << solve(s) << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}