#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 1e3 + 10;
lint n, A[M];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (i % 2 == 0) A[i] = -A[i];
    }
    lint ans = 0, s = 0;
    for (int i = 1; i <= n; i += 2) {
        lint t = s + A[i], mn = s + A[i] - 1;
        for (int j = i + 1; j <= n; j++) {
            if (j % 2 == 1) {
                t += A[j]; continue;
            }
            t += A[j];
            lint k = max(s, t);
            if (k <= mn) {
                ans += mn - k + 1;
            }
            mn = min(mn, t);
        }
        s += A[i] + A[i + 1];
    }
    cout << ans << '\n';
}