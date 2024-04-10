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
    cout << -1 << endl;
    exit(0);
}

int main() {
#ifdef LOCAL
//     freopen("e.in", "r", stdin);
#endif

    int n, k;
    cin >> n >> k;

    if (k == 1) no();
    if (k > 3) no();
    if (n <= 3) no();

    if (k == 2) {
        if (n == 4) {
            no();
        } else {
            cout << n-1 << "\n";
            forn(i, n-1) cout << i+1 << " " << i+2 << "\n";
        }
    } else if (k == 3) {
        if (n == 4) {
            cout << n-1 << "\n";
            forn(i, n-1) cout << i+1 << " " << i+2 << "\n";
        } else {
            cout << n-1 << "\n";
            forn(i, n-2) cout << 1 << " " << i+2 << "\n";
            cout << n-1 << " " << n << "\n";
        }
    } else {
        assert(false);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}