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
    //assert(freopen("in", "r", stdin));
#endif

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        int ans = 0;
        for (int b = 0; b < 9; b++) {
            vector<vector<int>> a(2);
            for (int i = 1; i <= n; i++) {
                a[(i >> b) & 1].push_back(i);
            }

            if (!a[0].empty() && !a[1].empty()) {
                cout << a[0].size() << " " << a[1].size();
                for (int x : a[0]) cout << " " << x;
                for (int x : a[1]) cout << " " << x;
                cout << endl;

                int x;
                cin >> x;
                ans = max(ans, x);
            }
        }
        cout << -1 << " " << ans << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}