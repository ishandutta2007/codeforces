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
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        int sum = 0;
        int sumA = 0;

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (i == 0 || a[i] * 2 <= a[0]) {
                sumA += a[i];
                ans.push_back(i);
            }
            sum += a[i];
        }

        if (sumA * 2 > sum) {
            cout << ans.size() << endl;
            for (int x : ans) cout << x + 1 << " ";
            cout << endl;
        } else {
            cout << 0 << endl;
        }
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}