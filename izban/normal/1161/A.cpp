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

    int n, k;
    while (scanf("%d%d", &n, &k) == 2) {
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &a[i]);
            a[i]--;
        }

        vector<vector<int>> vct(n);
        for (int i = 0; i < k; i++) {
            vct[a[i]].push_back(i);
        }

        int ans = 0;
        for (int s = 0; s < n; s++) {
            for (int d = -1; d <= 1; d++) {
                int f = s + d;
                if (f < 0 || f >= n) continue;

                ans += vct[s].empty() || vct[f].empty() || vct[s][0] > vct[f].back();
            }
        }
        cout << ans << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}