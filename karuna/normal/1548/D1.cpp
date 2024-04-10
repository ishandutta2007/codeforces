#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 6010;
int n, X[M], Y[M];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> X[i] >> Y[i];
    }

    lint ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) {
        lint a = 0, b = 0;
        for (int j = 1; j <= n; j++) if (i != j) {
            lint d = __gcd(abs(X[i] - X[j]), abs(Y[i] - Y[j]));
            if (d % 4 == 0) a += 1;
            else b += 1;
        }
        ans1 += a * (a - 1) / 2;
        ans2 += a * b;
    }
    cout << ans1 / 3 + ans2 / 2;
}