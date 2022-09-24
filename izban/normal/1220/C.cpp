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

    static char buf[(int)1.01e6];
    while (scanf(" %s", buf) == 1) {
        string s = buf;
        int n = s.length();

        char mn = 'z' + 1;
        for (int i =0; i < n; i++) {
            if (mn < s[i]) printf("Ann\n");
            else printf("Mike\n");
            mn = min(mn, s[i]);
        }
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}