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

const int MOD = 998244353;

bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) if (x % i == 0) return 0;
    return 1;
}

string solve(string s) {
    string pref, suf;

    int n =s.length();
    int l = 0, r = n - 1;
    while (r - l + 1 >= 4) {
        auto check = [&](int x, int y) {
            if (s[x] == s[y]) {
                pref += s[x];
                suf += s[y];
                l = x + 1;
                r = y - 1;
                return 1;
            }
            return 0;
        };
        if (check(l, r)) continue;
        if (check(l, r - 1)) continue;
        if (check(l + 1, r)) continue;
        if (check(l + 1, r - 1)) continue;
        assert(0);
    }
    if (l <= r) {
        pref += s[l];
        l++;
    }

    reverse(suf.begin(), suf.end());
    pref += suf;

    auto rs = pref;
    reverse(rs.begin(), rs.end());
    assert(pref == rs);
    assert(pref.length() >= n / 2);
    return pref;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    string s;
    while (cin >> s) {
        cout << solve(s) << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}