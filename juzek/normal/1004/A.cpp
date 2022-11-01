#include <cstdio>
#include <algorithm>
#include <set>

int tab[107];
std::set<int> k;

int odl(int N, int x) {
    int mini = 1337133713;
    for (int i = 0; i < N; i++) {
        mini = std::min(mini, std::abs(tab[i] - x));
    }
    return mini;
}

int main() {
    int N, D;
    scanf("%d%d", &N, &D);
    for (int i = 0; i < N; i++) {
        scanf("%d", &tab[i]);
    }
    int odp = 0;
    for (int i = 0; i < N; i++) {
        if (odl(N, tab[i] - D) == D && k.count(tab[i] - D) == 0)
            k.insert(tab[i] - D);
        if (odl(N, tab[i] + D) == D && k.count(tab[i] + D) == 0)
            k.insert(tab[i] + D);
    }
    printf("%d\n", (int) k.size());
    return 0;
}