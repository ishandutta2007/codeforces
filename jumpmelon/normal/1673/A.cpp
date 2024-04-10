#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
char S[MAXN + 1];

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        int n;
        scanf("%s", S);
        n = strlen(S);
        int minv = INT_MAX;
        long long tot = 0;
        for (int i = 0; i < n; i++) {
            // minv = min(minv, S[i] - 'a' + 1);
            tot += S[i] - 'a' + 1;
        }
        minv = min(S[0] - 'a' + 1, S[n - 1] - 'a' + 1);
        if (n & 1) {
            if (tot >= 2 * minv)
                printf("Alice %lld\n", tot - 2 * minv);
            else
                printf("Bob %lld\n", 2 * minv - tot);
        }
        else
            printf("Alice %lld\n", tot);
    }
    return 0;
}