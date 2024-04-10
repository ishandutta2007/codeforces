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




int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n, h;
    while (scanf("%d%d", &n, &h) == 2) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
//        sort(a.begin(), a.end());

        int ans = 0;
        vector<int> b;

        while (ans < n) {
            b.push_back(a[ans]);
            sort(b.begin(), b.end());

            ll sum = 0;
            for (int i = ans; i >= 0; i -= 2) sum += b[i];

            if (sum > h) break;
            ans++;
        }
        cout << ans << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}