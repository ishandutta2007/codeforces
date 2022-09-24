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

int sign(int x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n;
    while (cin >> n) {
        int ax, ay, bx, by, cx, cy;
        cin >> ax >> ay >> bx >> by >> cx >> cy;

        bool ok = 1;
        if (sign(bx - ax) != sign(cx - ax)) ok = 0;
        if (sign(by - ay) != sign(cy - ay)) ok = 0;

        cout << (ok ? "YES" : "NO") << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}