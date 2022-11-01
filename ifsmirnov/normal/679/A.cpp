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

bool prime(int n) {
    for (int i = 2; i*i <= n; ++i) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}

bool b[100];

int main() {
#ifdef LOCAL
//     freopen("a.in", "r", stdin);
#endif

    for (int n = 2; n <= 100; ++n) {
        int c = 1;
        for (int i: {2,3,4,5,7,9,10,11,13,17,19,23,29,31,25,37,41,43,47,49}) {
            cout << i << endl;
            string s;
//             if (n%i == 0) s = "yes";
//             else s = "no";
            cin >> s;
            if (s == "yes") ++c;
        }

//         cerr << n << endl;
//         assert( (c<=2) == prime(n) );
        cout << (c <= 2 ? "prime" : "composite") << endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}