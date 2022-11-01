#include <cstdio>
#include <vector>

std::vector<int> v[1000007];
bool kolor[1000007];
bool naKolejce[1000007];
std::vector<int> ziomki;

bool sprawdz(int a) {
    int ile = 0;
    for (auto it : v[a])
        if (kolor[it] == kolor[a])
            ile++;
    return ile <= 1;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
        if (v[i].size() > 1) {
            ziomki.push_back(i);
            naKolejce[i] = true;
        }
    while (!ziomki.empty()) {
        int a = ziomki.back();
        ziomki.pop_back();
        naKolejce[a] = false;
        if (sprawdz(a))
            continue;
        kolor[a] = !kolor[a];
        for (auto it : v[a]) {
            if (!naKolejce[it] && !sprawdz(it)) {
                naKolejce[it] = true;
                ziomki.push_back(it);
            }
        }
    }
    for (int i = 1; i <= N; i++)
        printf("%d", kolor[i]);
    return 0;
}