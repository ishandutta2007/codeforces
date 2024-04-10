#include <cstdio>
#include <algorithm>

int dlugo[5007];
int ile[5007];
int N, M;

int odl(int pocz, int kon) {
    if (pocz > kon)
        return kon - pocz + N;
    return kon - pocz;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (ile[a] == 0)
            dlugo[a] = 1337133713;
        dlugo[a] = std::min(dlugo[a], odl(a, b));
        ile[a]++;
    }
    for (int start = 1; start <= N; start++) {
        int wyn = 0;
        for (int i = 1; i <= N; i++) {
            if (ile[i] == 0)
                continue;
            wyn = std::max(wyn, odl(start, i) + (ile[i] - 1) * N + dlugo[i]);
        }
        printf("%d ", wyn);
    }
    return 0;
}