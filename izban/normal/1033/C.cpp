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

const string YES = "YES";
const string NO = "NO";


int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> p(n);
        vector<int> pos(n + 1);
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            pos[p[i]] = i;
        }

        vector<int> win(n, -1);
        for (int x = n; x >= 1; x--) {
            int i = pos[x];
            win[i] = 0;
            for (int y = x; y <= n; y += x) {
                if (i - y >= 0) {
                    win[i] |= win[i - y] == 0;
                }
                if (i + y < n) {
                    win[i] |= win[i + y] == 0;
                }
            }
        }
        string res(n, 'z');
        for (int i = 0; i < n; i++) res[i] = 'B' - win[i];

        cout << res << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}