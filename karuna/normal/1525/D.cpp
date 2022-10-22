#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
const int M = 5050;

int n, A[M], I[M], Dp[M], Ep[M], S[M];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1, s = 0; i <= n; i++) {
        if (A[i] == 1) I[++s] = i;
    }
    for (int i = 1; I[i]; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[j]) Ep[j] = 2e9;
            else Ep[j] = abs(j - I[i]) + S[j - 1];
        }
        S[0] = 2e9;
        for (int j = 1; j <= n; j++) {
            Dp[j] = Ep[j];
            S[j] = min(S[j - 1], Dp[j]);
        }
    }
    cout << S[n];
}