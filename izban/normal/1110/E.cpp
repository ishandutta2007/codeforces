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




int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif


    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) scanf("%d", &b[i]);

        vector<int> da, db;
        for  (int i = 1; i < n; i++) {
            da.push_back(a[i] - a[i - 1]);
            db.push_back(b[i] - b[i - 1]);
        }
        sort(da.begin(), da.end());
        sort(db.begin(), db.end());

        cout << (a[0] == b[0] && a[n - 1] == b[n - 1] && da == db ? "Yes" : "No") << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}