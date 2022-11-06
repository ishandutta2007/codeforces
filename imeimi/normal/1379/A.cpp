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
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<lf, lf> pff;

int n;
char P[52], S[52], C[] = "abacaba";
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> P + 1;
        bool ans = 0;
        for (int i = 1; i + 6 <= n; ++i) {
            strcpy(S + 1, P + 1);
            bool pos = 1;
            for (int j = 0; j <= 6; ++j) {
                if (S[i + j] == '?') S[i + j] = C[j];
                else if (S[i + j] != C[j]) pos = 0;
            }
            if (!pos) continue;
            for (int j = 1; j <= n; ++j) {
                if (S[j] == '?') S[j] = 'z';
            }
            for (int j = 1; j + 6 <= n; ++j) {
                if (i == j) continue;
                bool same = 1;
                for (int k = 0; k <= 6; ++k) {
                    if (S[j + k] != C[k]) same = 0;
                }
                if (same) pos = 0;
            }
            if (!pos) continue;
            ans = 1;
            printf("Yes\n%s\n", S + 1);
            break;
        }
        if (!ans) printf("No\n");
    }
    return 0;
}