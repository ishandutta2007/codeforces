#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef vector<int> vi;
typedef long long i64;

i64 n, k;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> k;
    k = min(k, n/2);
    i64 s = 0;
    forn(i, n/2) {
        if (i < k) {
            s += n - 1;
        } else {
            s += k * 2;
        }
    }
    if (n%2) s += k;
    cout << s << endl;

    return 0;
}