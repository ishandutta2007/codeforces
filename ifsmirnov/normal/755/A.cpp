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

bool prime(int n) {
    for (int i = 2; i*i <= n; ++i) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
#ifdef LOCAL
//     freopen("a.in", "r", stdin);
#endif

    int n;
    cin >> n;
    int m = 1;
    while (prime(n*m+1)) {
        ++m;
    }
    cout << m << endl;


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}