#include <bits/stdc++.h>

using namespace std;

int on[1005];
int re[1005];
int main() {
    int n;
    scanf("%d", &n);
    int R = 0, x = n;
    for (int i = 1; i < n; i++) {
        int c = (n + i) / (i + 1);
        int r = n - c - i;
        if (R < r) R = r, x = i;
    }
    for (int i = 1; i < n; i++) {
        if (i % (x + 1) == 0) continue;
        re[i] = 1;
    }
    for (int it = 3 * n; it--; ) {
        vector<int> o;
        for (int i = 1; i <= n; i++) {
            if (re[i] == 0 || on[i]) continue;
            on[i] = 1;
            o.push_back(i);
        }
        if (o.empty()) continue;
        printf("%u", o.size());
        for (int i : o) printf(" %d", i);
        printf("\n");
        fflush(stdout);
        int s;
        scanf("%d", &s);
        for (int i = 0; i < o.size(); i++, s = s % n + 1) on[s] = 0;
    }
    printf("0\n");
    fflush(stdout);
}