#include <bits/stdc++.h>

using int64 = long long;

const int N = 500005;

char ori[N], build[N], mc[N];

int n, k;
int nxt[N];

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", ori + 1);
    bool flag = true;
    for (int i = 1, j = 0; i <= k; i++) {
        if (i == 1) {
            build[i] = ori[i];
            putchar(build[i]);
            mc[0] = ori[i];
            continue;
        }
        while ((j + 1) * 2 > i) j = nxt[j];
        char jc = mc[j];
        if (i <= n && flag) jc = std::min(jc, ori[i]);
        build[i] = jc;
        if (i <= n && build[i] != ori[i] && flag) flag = false;
        while (j && build[i] != build[j + 1]) j = nxt[j];
        if (build[j + 1] == build[i]) j++;
        nxt[i] = j, mc[i - 1] = std::min(mc[nxt[i - 1]], build[i]);
        putchar(build[i]);
    }
    return 0;
}