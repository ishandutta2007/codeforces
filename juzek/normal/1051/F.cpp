#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

std::vector<std::pair<int, int>> v[100007];
long long odl[50][100007];
int N;
int oj[100007];
int gl[100007];
int rozm[100007];
int skok[100007];
bool odw[100007];
long long modl[100007];

void dfs(int a, int moj, long long ter) {
    modl[a] = ter;
    oj[a] = moj;
    odw[a] = true;
    gl[a] = gl[moj] + 1;
    rozm[a] = 1;
    for (auto it : v[a]) {
        if (!odw[it.first]) {
            dfs(it.first, a, ter + it.second);
            rozm[a] += rozm[it.first];
        }
    }
}

void dfs2(int a, int sk) {
    skok[a] = sk;
    for (auto it : v[a]) {
        if (skok[it.first] == 0) {
            if (rozm[it.first] * 2 >= rozm[a])
                dfs2(it.first, sk);
            else
                dfs2(it.first, it.first);
        }
    }
}

int lca(int a, int b) {
    while (skok[a] != skok[b]) gl[skok[a]] > gl[skok[b]] ? a = oj[skok[a]] : b = oj[skok[b]];
    return gl[a] < gl[b] ? a : b;
}

long long odle(int a, int b) {
    int c = lca(a, b);
    return modl[a] + modl[b] - 2 * modl[c];
}

std::vector<int> pocz;

template class std::vector<int>;

void dijkstra(int a, long long *odl) {
//    printf("Dijkstra z %d\n", a);
    pocz.push_back(a);
    for (int i = 1; i <= N; i++)
        odl[i] = LLONG_MAX;
    odl[a] = 0;
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> Q;
    Q.push({0, a});
    while (!Q.empty()) {
        auto ter = Q.top();
        Q.pop();
        a = ter.second;
        long long o = ter.first;
        if (odl[a] != o)
            continue;
//        printf("Odleglosc do %d: %lld\n", a, o);
        for (auto it : v[a]) {
            if (odl[it.first] > o + it.second) {
                odl[it.first] = o + it.second;
                Q.push({odl[it.first], it.first});
            }
        }
    }
}

int main() {
    int M;
    scanf("%d%d", &N, &M);
    int a, b, c;
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        v[a].emplace_back(b, c);
        v[b].emplace_back(a, c);
    }
    dfs(1, 1, 0);
    dfs2(1, 1);
    for (int i = 1; i <= N; i++) {
        for (auto it : v[i]) {
            if (std::abs(gl[i] - gl[it.first]) != 1) {
                dijkstra(i, odl[pocz.size()]);
            }
        }
    }
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%d", &a, &b);
        long long wyn = odle(a, b);
        for (int i = 0; i < pocz.size(); i++)
            wyn = std::min(wyn, odle(a, pocz[i]) + odl[i][b]);
        printf("%lld\n", wyn);
    }
    return 0;
}