#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
// #define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
// #define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;
#define sz(x) int((x).size())

void check(string s, int a00, int a01, int a10, int a11) {
    forn(i, s.size()) forn(j, i) {
        if (s[j] == '0') {
            if (s[i] == '1') --a01; else --a00;
        } else {
            if (s[i] == '1') --a11; else --a10;
        }
    }
    assert((a00 | a01 | a10 | a11) == 0);
}

map<i64, i64> cc;

void imp() {
    cout << "Impossible" << endl;
    exit(0);
}

i64 getn(i64 cn2) {
    if (!cc.count(cn2)) imp();
    return cc[cn2];
}


int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
#endif

    for (i64 n = 0;; ++n) {
        i64 c = n * (n-1) / 2;
        if (c > 5e9) break;
        cc[c] = n;
    }

//     forn(mask, 1<<10) {
        i64 a00, a01, a10, a11;
//         a00 = 0;
//         a01 = 0;
//         a10 = 0;
//         a11 = 0;

//         forn(i, 10) forn(j, i) {
//             int x = (mask >> j) & 1;
//             int y = (mask >> i) & 1;
//             if (x == 0) {
//                 if (y == 0) ++a00; else ++a01;
//             } else {
//                 if (y == 0) ++a10; else ++a11;
//             }
//         }
//         cerr << a00 << " " << a01 << " " << a10 << " " << a11 << endl;

        cin >> a00 >> a01 >> a10 >> a11;

        if (0 == (a00|a01|a10|a11)) {
            cout << 0 << endl;
            exit(0);
        }

        i64 n = getn(a00 + a01 + a10 + a11);
        (void)n;
        i64 n0 = getn(a00);
        i64 n1 = getn(a11);

        if (n0 == 1) {
            if (a01 == 0 && a10 == 0) n0 = 0;
        }
        if (n1 == 1) {
            if (a01 == 0 && a10 == 0) n1 = 0;
        }


    //     cerr << n << " " << n0 << " " << n1 << endl;
        if (n != n0 + n1) imp();

        if ((n0 == 0 || n1 == 0) && (a01 != 0 || a10 != 0)) imp();

        string s = string(n0, '0') + string(n1, '1');
        int p0 = 0;
        int p1 = n0;

        i64 c = n0 * n1;
        while (c > a01) {
            if (c - a01 >= n0) {
                if (p1 == n) imp();
                swap(s[p0++], s[p1++]);
                c -= n0;
            } else {
                int need = c - a01;
                if (p1 == n) imp();
                swap(s[p1], s[p1 - need]);
                break;
            }
        }

//         check(s, a00, a01, a10, a11);
        int t0 = 0, t1 = 0;
        for (char c: s) {
            if (c == '0') {
                a00 -= t0;
                a10 -= t1;
                ++t0;
            } else {
                a01 -= t0;
                a11 -= t1;
                ++t1;
            }
        }
        if (a00|a01|a10|a11) imp();
        cout << s << endl;
//     }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}