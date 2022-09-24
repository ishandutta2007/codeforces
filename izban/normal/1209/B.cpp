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
    while (cin >> n) {
        string s;
        cin >> s;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i] >> b[i];


        int ans = 0;
        for (int t = 0; t < 1e3; t++) {
            for (int i = 0; i < n; i++) {
                if (t >= b[i] && (t - b[i]) % a[i] == 0) {
                    s[i] ^= '0' ^ '1';
                }
            }
            int cnt = 0;
            for (char c : s) cnt += c == '1';
            ans = max(ans, cnt);
        }
        cout << ans << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}