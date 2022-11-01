#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); ++i)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long i64;

const int maxn = 500500;

int n;
i64 X;
i64 a[maxn];

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);
    forn(i, n) {
        i64 x, y;
#ifdef HOME
        scanf("%I64d%I64d", &x, &y);
#else
        scanf("%lld%lld", &x, &y);
#endif
        X ^= x;
        a[i] = x ^ y;
    }

    int num = 0, den = 0;

//     cout << X << endl;
//     forn(i, n) cout << a[i] << " "; cout << endl;

    for (int bn = 61; bn >= 0; --bn) {
        i64 B = 1ll << bn;
        i64 fi = -1;
        int idx = -1;
        forn(i, n) if (a[i] & B) {
            if (fi == -1) {
                fi = a[i];
                idx = i;
            } else {
                a[i] ^= fi;
            }
        }

        if (X & B) {
            if (idx == -1) {
                cout << "1/1" << endl;
                return 0;
            }
            X ^= fi;
            ++num;
        }
        if (idx != -1) {
            a[idx] = 0;
            ++den;
        }
    }

//     cout << "vals: ";
//     cout << num << " " << den << endl;

    assert(X == 0);

    if (den == 0) {
        cout << "0/1" << endl;
        return 0;
    }

    cout << (1ll<<den)-1 << "/" << (1ll<<den) << endl;

#ifdef HOME
    cerr << "Time: " << clock() << " ms" << endl;
#endif
}