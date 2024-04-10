#include <cstdio>
#include <vector>

const int z = 1024 * 512;
std::pair<int, int> drzewo[z * 2 + 1];
int tab[500007];
int lastPos[500007];
int prevPos[500007];
int prev[500007];
int next[500007];
std::vector<int> zapytania[500007];
int pocz[500007];
int odp[500007];

void wrzuc(int a, int b, std::pair<int, int> war) {
    a += z - 1, b += z + 1;
    while (a != b - 1) {
        if (a % 2 == 0)
            drzewo[a + 1] = std::max(drzewo[a + 1], war);
        if (b % 2 == 1)
            drzewo[b - 1] = std::max(drzewo[b - 1], war);
        a /= 2, b /= 2;
    }
}

std::pair<int, int> czytaj(int a) {
    a += z;
    std::pair<int, int> ret = {0, 0};
    while (a != 0) {
        ret = std::max(ret, drzewo[a]);
        a /= 2;
    }
    return ret;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &tab[i]);
        lastPos[tab[i]] = 1337133713;
        prev[i] = prevPos[tab[i]];
        prevPos[tab[i]] = i;
    }
    for (int i = N; i >= 1; i--) {
        next[i] = lastPos[tab[i]];
        lastPos[tab[i]] = i;
    }
    int Q;
    scanf("%d", &Q);
    int a, b;
    for (int i = 1; i <= Q; i++) {
        scanf("%d%d", &a, &b);
        pocz[i] = a;
        zapytania[b].push_back(i);
    }
    for (int i = 1; i <= N; i++) {
        wrzuc(prev[i] + 1, i, {next[i], tab[i]});
        for (auto it : zapytania[i]) {
            auto w = czytaj(pocz[it]);
            if (w.first > i)
                odp[it] = w.second;
        }
    }
    for (int i = 1; i <= Q; i++)
        printf("%d\n", odp[i]);
    return 0;
}