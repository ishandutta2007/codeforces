#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1 << 20, M = 1 << 20;
int B[MAXN + 5], V[M + 5];

unordered_map<long long, int> F;

int calc(int n, int k) {
    long long key = (long long)n * 998244353 + k;
    if (F.count(key)) {
        return F[key];
    } else {
        int ans = 0;
        for (int i = k; i <= n; i++)
            ans ^= (n & i) == i ? 1 : 0;
        return F[key] = ans;
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &B[i]);
    for (int i = 0; i < n; i++) {
        int c = B[i];
        for (int j = i + 1; c < M; j++) {
            int l = max(0, i - 1) + max(0, n - j - 1);
            int t = (i == 0 ? 0 : 1) + (j == n ? 0 : 1);
            if (calc(l, max(0, k - t)))
                V[c] ^= 1;
            if (j >= n)
                break;
            if (j > i) {
                if (B[j] >= 20 || c >= (M >> B[j]))
                    break;
                c = c << B[j];
            }
        }
    }
    int i = M - 1;
    while (i > 0 && !V[i])
        i--;
    while (i >= 0) {
        printf("%d", V[i]);
        i--;
    }
    putchar('\n');
    return 0;
}