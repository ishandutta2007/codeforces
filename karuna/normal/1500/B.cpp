#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
typedef pair<lint, lint> plint;
const int MAX = 10e5 + 10;

lint n, m, k, A[MAX], B[MAX], Ap[MAX], C[MAX], D[MAX];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m >> k; memset(Ap, -1, sizeof Ap);
    for (int i = 0; i < n; i++) cin >> (n > m ? A[i] : B[i]);
    for (int i = 0; i < m; i++) cin >> (n > m ? B[i] : A[i]);
    lint g = __gcd(n, m), l = n * m / g;
    if (n < m) swap(n, m);
    for (int i = 0; i < n; i++) Ap[A[i]] = i;

    for (int i = 0; i < m; i++) {
        if (Ap[B[i]] == -1) continue;
        C[(Ap[B[i]] - i + n) % n]++;
    }
    lint s = 0;
    for (int i = 0; i < l / m; i++) {
        D[i] = C[i * m % n]; s += D[i];
    }
    s = l - s;

    lint ans = l * ((k - 1) / s); k -= (k - 1) / s * s;
    for (int i = 0; i < l / m; i++) {
        if (m - D[i] >= k) {
            for (int j = 0; j < m; j++) {
                if (B[j] != A[(j + i * m % n) % n]) {
                    ++ans;
                    if (--k == 0) {
                        cout << ans; return 0;
                    }
                }
                else ++ans;
            }
        }
        else k -= (m - D[i]), ans += m;
    }
}