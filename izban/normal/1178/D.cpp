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

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

//    for (int n = 3; n <= 1000; n++) {
//        bool any = 0;
//        for (int i = n; i <= n + n / 2; i++) {
//            any |= isPrime(i);
//        }
//        assert(any);
//    }

    int n;
    while (cin >> n) {
        vector<pair<int, int>> ed;
        for (int i = 0; i < n; i++) {
            ed.push_back({i, (i + 1) % n});
        }

        int cur = 0;
        int add = n / 2;
        while (!isPrime(ed.size())) {
            assert(cur < add);
            ed.push_back({cur, cur + add});
            cur++;
        }

        cout << ed.size() << endl;
        for (auto o : ed) {
            cout << o.first + 1 << " "<< o.second + 1 << endl;
        }
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}