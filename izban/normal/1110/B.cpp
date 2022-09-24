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

    int n, m, k;
    while (scanf("%d%d%d", &n, &m, &k) == 3) {
        vector<int> b(n);
        for (int i = 0; i < n; i++) scanf("%d", &b[i]);

        vector<int> dif;
        for (int i = 1; i < n; i++) dif.push_back(b[i] - b[i - 1] - 1);

        int all = b[n - 1] - b[0] + 1;
        sort(dif.begin(), dif.end());
        reverse(dif.begin(), dif.end());

        for (int i = 0; i < k - 1; i++) {
            all -= dif[i];
        }
        cout << all << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}