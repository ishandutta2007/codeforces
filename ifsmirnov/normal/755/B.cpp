#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
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

set<string> sa, sb;

int main() {
#ifdef LOCAL
//     freopen("b.in", "r", stdin);
#endif

    int n, m, a=0, b=0, ab=0;
    cin >> n >> m;
    string s;
    forn(i, n) {
        cin >> s;
        sa.insert(s);
    }
    forn(i, m) {
        cin >> s;
        sb.insert(s);
    }

    for (string s: sa) {
        if (sb.count(s)) ++ab;
        else ++a;
    }
    for (string s: sb) {
        if (!sa.count(s)) {
            ++b;
        }
    }
//     cerr << a << " " << b << " " << ab << endl;
    bool fi = true;
    while (true) {
        if (fi) {
            if (ab) --ab;
            else if (a) --a;
            else { cout << "NO\n"; return 0; }
        } else {
            if (ab) --ab;
            else if (b) --b;
            else { cout << "YES\n"; return 0; }
        }
        fi ^= 1;
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}