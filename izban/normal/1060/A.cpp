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

    int n;
    string s;
    while (cin >> n >> s) {
        vector<int> cnt(10);
        for (char c : s) cnt[c - '0']++;

        int ans = 0;
        for (int x = 1;; x++) {
            auto curcnt = cnt;
            bool ok = 1;
            ok &= curcnt[8] >= x;
            curcnt[8] -= x;
            int sum = 0;
            for (int x : curcnt) sum += x;
            ok &= sum >= x * 10;
            if (ok) ans = x;
            else break;
        }
        cout << ans << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}