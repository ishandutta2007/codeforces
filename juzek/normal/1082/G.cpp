#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

int tab[2007][2007];
int poprz[2007];
bool odw[2007];

const int zrodlo = 0, ujscie = 2003;
std::queue<std::pair<int, int>> Q;
std::vector<int> kr[2007];

int bfs() {
    memset(odw, 0, sizeof(odw));
    while (!Q.empty())
        Q.pop();
    odw[0] = true;
    Q.push({zrodlo, 1337133713});
    while (!Q.empty()) {
        int v, odl;
        v = Q.front().first;
        odl = Q.front().second;
        Q.pop();
        if (v == ujscie)
            return odl;
        for (auto i : kr[v]) {
            if (tab[v][i] > 0 && !odw[i]) {
                odw[i] = true;
                poprz[i] = v;
                Q.push({i, std::min(odl, tab[v][i])});
            }
        }
    }
    return -1;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        int a;
        scanf("%d", &a);
        tab[i][ujscie] = a;
        kr[i].push_back(ujscie);
    }
    long long sum = 0;
    for (int i = 1; i <= M; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        sum += c;
        tab[zrodlo][N + i] = c;
        tab[N + i][a] = 1337133713;
        tab[N + i][b] = 1337133713;
        kr[N + i].push_back(a);
        kr[N + i].push_back(b);
        kr[a].push_back(N + i);
        kr[b].push_back(N + i);
        kr[zrodlo].push_back(N + i);
    }
    int a;
    long long przeplyw = 0;
    while ((a = bfs()) != -1) {
        int ter = ujscie;
        przeplyw += a;
        while (ter != zrodlo) {
            int prev = poprz[ter];
            tab[prev][ter] -= a;
            tab[ter][prev] += a;
            ter = prev;
        }
    }
    printf("%lld", sum - przeplyw);
    return 0;
}