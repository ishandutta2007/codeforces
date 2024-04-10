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
char A[100002], B[100002];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> A + 1 >> B + 1;
        vector<int> a, b;
        for (int i = 1, j = 1; i <= n; ++i) {
            while (j < n && A[j] == A[j + 1]) ++j;
            if (j == n) break;
            A[j] ^= 1;
            a.push_back(j);
        }
        for (int i = 1, j = 1; i <= n; ++i) {
            while (j < n && B[j] == B[j + 1]) ++j;
            if (j == n) break;
            B[j] ^= 1;
            b.push_back(j);
        }
        if (A[n] != B[n]) a.push_back(n);
        while (!b.empty()) a.push_back(b.back()), b.pop_back();
        printf("%d", int(a.size()));
        for (int i : a) printf(" %d", i);
        printf("\n");
    }
    return 0;
}