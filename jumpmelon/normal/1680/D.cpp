#include <bits/stdc++.h>

using namespace std;

typedef long long big;

const int MAXN = 3000;
int A[MAXN + 5];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    
    int tcq = 0;
    big tsum = 0;
    for (int i = 0; i < n; i++) {
        tsum += A[i];
        if (A[i] == 0)
            tcq++;
    }

    if (abs(tsum) > (big)tcq * k) {
        puts("-1");
        return 0;
    }

    big ans = 1;

    int lcq = 0;
    big lsum = 0;
    for (int i = 0; i < n; i++) {
        int rcq = 0;
        big rsum = 0;

        for (int j = n - 1; j >= i; j--) {
            int cq = tcq - lcq - rcq;
            big sum = tsum - lsum - rsum;

            ans = max(ans, sum + min((big)cq * k, -tsum + (big)(tcq - cq) * k) + 1);
            ans = max(ans, -sum + min((big)cq * k, tsum + (big)(tcq - cq) * k) + 1);

            rsum += A[j];
            if (A[j] == 0)
                rcq++;
        }
        lsum += A[i];
        if (A[i] == 0)
            lcq++;
    }

    printf("%lld\n", ans);
    return 0;
}