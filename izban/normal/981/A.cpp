#include <bits/stdc++.h>
#define pw(x) (1LL << (x))
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;


int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    string s;
    while (cin >> s) {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            string cur = "";
            for (int j = i; j < n; j++) {
                cur += s[j];
                string rcur = cur;
                reverse(rcur.begin(), rcur.end());
                if (cur != rcur) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        cout << ans << endl;
    }

#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}