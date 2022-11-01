#include <bits/stdc++.h>

using namespace std;

int n;
int tab[10000007];

bool solve(int start, int limit, int ile, bool moge) {
    if (ile == 0) return true;
    if (start > n) return false;
    if (moge)
        return solve(start + 1, limit, ile - 1, false);
    else
        return solve(start + 1, limit, ile - (tab[start] <= limit), (tab[start] <= limit));
}

int main() {
    int k;
    scanf("%d%d", &n, &k);
    int pocz = 0, kon = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        kon = max(kon, tab[i] + 1);
    }
    while (pocz != kon - 1) {
        int sr = (pocz + kon) / 2;
        if (solve(1, sr, k, false) || solve(1, sr, k, true))
            kon = sr;
        else
            pocz = sr;
    }
    printf("%d\n", kon);
    return 0;
}