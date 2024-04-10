#include <cstdio>
#include <algorithm>

const int z = 256 * 1024;
std::pair<int, int> drzewo[z * 2 + 7];
int pos[z], zasieg[z];
std::pair<int, int> nast[z];
int oj[z][15];
int koszt[z];
bool odw[z];

void insert(int a, int war, int koszt) {
    a += z;
    drzewo[a] = {war, -koszt};
    a /= 2;
    while (a != 0) {
        drzewo[a] = std::max(drzewo[a * 2], drzewo[a * 2 + 1]);
        a /= 2;
    }
}

std::pair<int, int> get(int a, int b) {
    a += z - 1, b += z + 1;
    std::pair<int, int> ret = {0, 0};
    while (a != b - 1) {
        if (a % 2 == 0)
            ret = std::max(ret, drzewo[a + 1]);
        if (b % 2 == 1)
            ret = std::max(ret, drzewo[b - 1]);
        a /= 2, b /= 2;
    }
    return ret;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d%d", &pos[i], &zasieg[i]);
    pos[N + 1] = 1337133713;
    for (int i = 0; i < 15; i++)
        oj[N + 1][i] = N + 1;
    for (int i = N; i > 0; i--) {
        int next = int(std::upper_bound(pos + i, pos + N + 1, pos[i] + zasieg[i]) - 1 - pos);
        nast[i] = get(i, next);
        if (nast[i].first == 0)
            nast[i] = {i + 1, -(pos[i + 1] - pos[i] - zasieg[i])};
        nast[i].second = std::max(nast[i].second, -(pos[nast[i].first] - pos[i] - zasieg[i]));
        oj[i][0] = nast[i].first;
        for (int w = 1; w < 15; w++)
            oj[i][w] = oj[oj[i][w - 1]][w - 1];
        koszt[i] = koszt[nast[i].first] - nast[i].second;
        insert(i, nast[i].first, -nast[i].second);
    }
    int Q;
    scanf("%d", &Q);
    int a, b;
    while (Q--) {
        scanf("%d%d", &a, &b);
        int ter = a;
        int skok = 13;
        while (skok != -1) {
            if (oj[ter][skok] > b)
                skok--;
            else
                ter = oj[ter][skok];
        }
        printf("%d\n", koszt[a] - koszt[ter]);
    }
    return 0;
}