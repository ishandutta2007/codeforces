#include <cstdio>
#include <vector>
#include <algorithm>

int tab[1000007];
std::vector<int> v[1000007];
std::vector<int> podzielne[1000007];
bool akt[1000007];
bool trza[1000007];
int wyn = 0;

int dfs(int a) {
    akt[a] = false;
    int maxi1 = -1, maxi2 = -1;
    int dl = 1;
    for (auto it : v[a]) {
        if (akt[it]) {
            int ddd = dfs(it);
            dl = std::max(dl, ddd + 1);
            if (ddd > maxi1) {
                maxi2 = maxi1;
                maxi1 = ddd;
            } else {
                maxi2 = std::max(maxi2, ddd);
            }
        }
    }
    wyn = std::max(dl, wyn);
    if (maxi2 != -1)
        wyn = std::max(maxi1 + maxi2 + 1, wyn);
    return dl;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &tab[i]);
        podzielne[tab[i]].push_back(i);
    }
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 2; i <= 200000; i++) {
        if (trza[i])
            continue;
        for (int w = i; w <= 200000; w += i) {
            trza[w] = true;
            for (auto it : podzielne[w])
                akt[it] = true;
        }
        for (int w = i; w <= 200000; w += i) {
            for (auto it : podzielne[w]) {
                if (akt[it]) {
                    dfs(it);
                }
            }
        }
    }
    printf("%d", wyn);
    return 0;
}