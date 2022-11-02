#include <bits/stdc++.h>

const int N = 1005;

int As[N], Bs[N], Ia[N], Ib[N];

void Ea(int i, int j) {
    std::swap(As[i], As[j]);
    std::swap(Ia[As[i]], Ia[As[j]]);
}

void Eb(int i, int j) {
    std::swap(Bs[i], Bs[j]);
    std::swap(Ib[Bs[i]], Ib[Bs[j]]);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &As[i]);
        Ia[As[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &Bs[i]);
        Ib[Bs[i]] = i;
    }
    std::vector<std::array<int, 4> > Pors;
    for (int i = 1; i <= n; ++i) {
        if (Ia[i] != i || Ib[i] != i) {
            Pors.push_back({Ia[i], i, i, Ib[i]});
            Ea(i, Ia[i]);
            Eb(i, Ib[i]);
        }
    }
    printf("%d\n", (int)Pors.size());
    for (auto it : Pors) {
        printf("%d %d %d %d\n", it[0], it[1], it[2], it[3]);
    }
    return 0;
}