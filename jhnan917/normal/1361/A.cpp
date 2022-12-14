#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> E[500005];
int T[500005], ord[500005], cnt[500005];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    set<int> rem;
    for (int i = 1; i <= n; i++) {
        scanf("%d", T + i);
        ord[i] = i;
        rem.insert(i);
    }
    sort(ord + 1, ord + n + 1, [&](int a, int b) {
        return T[a] < T[b];
    });
    for (int it = 1; it <= n; it++) {
        int i = ord[it], x = 1;
        for (int j : E[i]) {
            if (T[j] > T[i]) continue;
            if (T[j] == T[i]) {
                printf("-1\n");
                return 0;
            }
            if (!cnt[T[j]]) cnt[T[j]] = 1, x++;
        }
        if (x != T[i]) {
            printf("-1\n");
            return 0;
        }
        for (int j = 1; j < T[i]; j++) cnt[j] = 0;
    }
    for (int i = 1; i <= n; i++) printf("%d ", ord[i]);
    return 0;
}