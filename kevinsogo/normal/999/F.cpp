#include <bits/stdc++.h>
using namespace std;

vector<int> best, joys;
int f(int k, int cards, int people) {
    for (int c = 0; c <= cards; c++) best[c] = 0;
    while (people--) {
        for (int c = cards; c >= 0; c--) {
            for (int j = min(c, k); j; j--) {
                best[c] = max(best[c], best[c - j] + joys[j]);
            }
        }
    }
    return best[cards];
}

void collect(map<int,int>& m, int n) {
    for (int v; n--;) {
        scanf("%d", &v);
        m[v]++;
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    map<int,int> cards, faves;
    collect(cards, n * k);
    collect(faves, n);
    joys.resize(k + 1);
    for (int i = 1; i <= k; i++) scanf("%d", &joys[i]);
    best.resize(n * k + 1);
    int ans = 0;
    for (auto [v, c] : faves) ans += f(k, cards[v], c);
    printf("%d\n", ans);
}