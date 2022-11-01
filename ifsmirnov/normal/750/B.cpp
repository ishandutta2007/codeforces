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

void no() {
    cout << "NO\n";
    exit(0);
}

int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
#endif

    int n, x;
    cin >> n;
    x = 0;
    forn(i, n) {
        int y;
        string s;
        cin >> y >> s;
        if ( (x == 0 && s != "South") || (x == 20000 && s != "North") ) {
            no();
        }
        if (s == "South") {
            if (x > 20000) {
                if (y > x-20000) no();
                x -= y;
            } else {
                if (y > 20000-x) no();
                x += y;
            }
        }
        if (s == "North") {
            if (x > 20000) {
                if (y > 40000-x) no();
                x = (x+y)%40000;
            } else {
                if (y > x) no();
                x -= y;
            }
        }
    }
    cout << (x == 0 ? "YES\n" : "NO\n");

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}