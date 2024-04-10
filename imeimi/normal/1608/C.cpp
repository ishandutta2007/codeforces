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
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lf, lf> pff;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<tuple<int, int, int>> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            get<0>(A[i]) = get<1>(B[i]) = a;
            get<2>(A[i]) = get<2>(B[i]) = i;
        }
        for (int i = 0; i < n; ++i) {
            int b;
            cin >> b;
            get<1>(A[i]) = get<0>(B[i]) = b;
        }
        vector<bool> ans(n, true);
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int maxA = 0, maxB = 0;
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            maxA = max(get<0>(A[i]), maxA);
            maxB = max(get<1>(A[i]), maxB);
            while (1) {
                if (a < n && get<0>(A[a]) <= maxA) {
                    maxB = max(get<1>(A[a++]), maxB);
                    continue;
                }
                if (b < n && get<0>(B[b]) <= maxB) {
                    maxA = max(get<1>(B[b++]), maxA);
                    continue;
                }
                break;
            }
            if (a == n && b == n) break;
            ans[get<2>(A[i])] = false;
        }
        for (int i = 0; i < n; ++i) printf("%c", char('0' + ans[i]));
        printf("\n");
    }
    return 0;
}