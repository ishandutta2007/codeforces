#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

const int z = 1024 * 128;
std::vector<std::pair<int, int>> input;
std::vector<int> liczby;
std::map<int, int> zbite;
char sl[10];
long long reszty[z * 2 + 7][5];
int drzewo[z * 2 + 7];

void polacz(int v) {
    int lewo = drzewo[v * 2];
    drzewo[v] = drzewo[v * 2] + drzewo[v * 2 + 1];
    for (int i = 0; i < 5; i++)
        reszty[v][i] = reszty[v * 2][i] + reszty[v * 2 + 1][(((i - lewo) % 5) + 5) % 5];
}

void ins(int v, int war) {
    v += z;
    drzewo[v] = 1;
    for (int i = 0; i < 5; i++)
        reszty[v][i] = 0;
    reszty[v][0] = war;
    v /= 2;
    while (v != 0) {
        polacz(v);
        v /= 2;
    }
}

void usu(int v, int war) {
    v += z;
    drzewo[v] = 0;
    for (int i = 0; i < 5; i++)
        reszty[v][i] = 0;
    reszty[v][0] = 0;
    v /= 2;
    while (v != 0) {
        polacz(v);
        v /= 2;
    }
}

void wypisz() {
    printf("Drzewo\n");
    for (int i = 1; i < z * 2; i++) {
        printf("%d ", drzewo[i]);
        if ((i & (i + 1)) == 0)
            printf("\n");
    }
    for (int res = 0; res < 5; res++) {
        printf("Reszta %d\n", res);
        for (int i = 1; i < z * 2; i++) {
            printf("%lld ", reszty[i][res]);
            if ((i & (i + 1)) == 0)
                printf("\n");
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        scanf(" %s", sl);
        if (sl[0] == 's') {
            input.emplace_back(0, 0);
        } else if (sl[0] == 'a') {
            int a;
            scanf("%d", &a);
            input.emplace_back(1, a);
            liczby.push_back(a);
        } else {
            int a;
            scanf("%d", &a);
            input.emplace_back(2, a);
        }
    }
    std::sort(liczby.begin(), liczby.end());
    int ter = 0;
    for (int i = 0; i < liczby.size(); i++) {
        if (liczby[i] != liczby[i - 1]) {
            ter++;
            zbite[liczby[i]] = ter;
        }
    }
    for (auto it : input) {
        if (it.first == 0) {
            printf("%lld\n", reszty[1][2]);
        } else if (it.first == 1) {
            ins(zbite[it.second], it.second);
        } else {
            usu(zbite[it.second], it.second);
        }
//        wypisz();
    }
    return 0;
}