#include <cstdio>
#include <vector>

std::vector<int> v[50007];
bool odw[50007];
int rozm[50007];
int ile[507];
int podrz[507];

int aktN = 0;
int cent = 0;
int K;

long long wyn = 0;

void dfs(int a, int oj) {
    rozm[a] = 1;
    for (auto it : v[a]) {
        if (it != oj && !odw[it]) {
            dfs(it, a);
            rozm[a] += rozm[it];
        }
    }
}

void szukaj(int a, int oj) {
    bool k = aktN - rozm[a] <= (aktN / 2);
    for (auto it : v[a]) {
        if (it != oj && !odw[it]) {
            szukaj(it, a);
            k &= rozm[it] <= (aktN / 2);
        }
    }
    if (k) {
        cent = a;
    }
}

void policz(int a, int oj, int* ile, int gl = 0) {
    if (gl <= K)
        ile[gl]++;
    for (auto it : v[a]) {
        if (it != oj && !odw[it]) {
            policz(it, a, ile, gl + 1);
        }
    }
}

void rozwal(int a) {
    dfs(a, -1);
    aktN = rozm[a];
    szukaj(a, -1);
    odw[cent] = true;
    for (int i = 0; i <= K; i++)
        ile[i] = 0;
    ile[0] = 1;
    for (auto it : v[cent]) {
        if (odw[it]) continue;
        policz(it, cent, podrz, 1);
        for (int i = 1; i <= K; i++) {
            wyn += (long long) podrz[i] * ile[K - i];
        }
        for (int i = 1; i <= K; i++) {
            ile[i] += podrz[i];
            podrz[i] = 0;
        }
    }
    for (auto it : v[cent]) {
        if (!odw[it])
            rozwal(it);
    }
}

int main() {
    int N;
    scanf("%d%d", &N, &K);
    int a, b;
    for (int i = 1; i < N; i++) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    rozwal(1);
    printf("%I64d\n", wyn);
    return 0;
}