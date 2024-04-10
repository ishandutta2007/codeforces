#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

struct kr {
    int a, b, waga;

    bool operator<(kr const& kr) const {
        return waga < kr.waga;
    };
};

int oj[2007];
int tab[2007][2007];
std::vector<kr> kraw;
std::vector<std::pair<int, int>> v[2007];

int find(int a) {
    if (oj[a] == a)
        return a;
    return oj[a] = find(oj[a]);
}

void unioner(int a, int b) {
    oj[find(a)] = find(b);
}

void policz(int a, int oj, int odl, int start) {
    if (tab[start][a] != odl) {
        printf("NO");
        exit(0);
    }
    for (auto it : v[a])
        if (it.first != oj)
            policz(it.first, a, odl + it.second, start);
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        oj[i] = i;
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= N; w++) {
            scanf("%d", &tab[i][w]);
            if (tab[i][w] == 0 && i != w) {
                printf("NO");
                return 0;
            }
            if (i != w)
                kraw.push_back({i, w, tab[i][w]});
        }
    }
    std::sort(kraw.begin(), kraw.end());
    for (auto it : kraw) {
        if (find(it.a) != find(it.b)) {
            unioner(it.a, it.b);
            v[it.a].emplace_back(it.b, it.waga);
            v[it.b].emplace_back(it.a, it.waga);
        }
    }
    for (int i = 1; i <= N; i++)
        policz(i, -1, 0, i);
    printf("YES");
    return 0;
}