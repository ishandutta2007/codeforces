#include <bits/stdc++.h>
using namespace std;

int tab[1000007];

bool ogarnij(int N, int K) {
    int mini = 13371337;
    int curr = 0;
    int ok = false;
    for (int i = 1; i <= N; i++) {
        if (tab[i] == K && (ok || curr - mini >= 0))
            return true;
        int przed = curr;
        if (tab[i] >= K)
            curr++;
        else
            curr--;
        if (curr - mini > 0)
            ok = true;
        mini = min(mini, przed);
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, K;
        scanf("%d%d", &N, &K);
        for (int i = 1; i <= N; i++)
            scanf("%d", &tab[i]);
        if (N == 1) {
            printf(tab[1] == K ? "yes\n" : "no\n");
            continue;
        }
        bool ok = ogarnij(N, K);
        reverse(tab + 1, tab + N + 1);
        ok |= ogarnij(N, K);
        printf(ok ? "yes\n" : "no\n");
    }
    return 0;
}