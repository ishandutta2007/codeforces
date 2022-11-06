#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        char in[501];
        cin >> in;
        char pr = in[0];
        int cnt = 1;
        bool ans[26] = {};
        for (int i = 1; in[i - 1]; ++i) {
            if (pr != in[i]) {
                if (cnt & 1) ans[pr - 'a'] = 1;
                pr = in[i];
                cnt = 1;
            }
            else ++cnt;
        }
        for (int i = 0; i < 26; ++i) if (ans[i])
            printf("%c", (char)('a' + i));
        printf("\n");
    }
    return 0;
}