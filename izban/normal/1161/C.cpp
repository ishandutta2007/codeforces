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

        sort(a.begin(), a.end());

        const int T = 55;
        vector<int> cnt(T);
        for  (int x : a) cnt[x]++;


        bool first_win;
//        if (cnt[1] > n / 2) {
//            first_win = 0;
//        } else if (cnt[1] > 0) {
//            first_win = 1;
//        } else {
//            if (cnt[2] > n / 2) {
//                first_win = 0;
//            } else if (cnt[2] > 0) {
//                first_win = 1;
//            }
//        }
        for (int x = 1; x < T; x++) {
            if (cnt[x] > n / 2) {
                first_win = 0;
                break;
            } else if (cnt[x] > 0) {
                first_win = 1;
                break;
            }
        }
        string s = first_win ? "Alice" : "Bob";
        cout << s << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}