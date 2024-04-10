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

    string s;
    while (cin >> s) {
        int n = s.length();

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && s[i] == 'b' && s[i + 1] == 'a') {
                ans[i] = 1;
            }
            if ((i + 1 == n || s[i + 1] == 'b') && s[i] == 'a') {
                ans[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i + 1 == n];
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}