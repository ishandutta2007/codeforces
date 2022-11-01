#include <cstdio>
#include <vector>
#include <cstring>

std::vector<int> v[100007], rv[100007];
int pos[100007];
bool odw[100007];
int spojna[100007];
int rozm[100007];
int zeit;
bool som;
int rozmiar;

void dfs(int a) {
    odw[a] = true;
    for (auto it : v[a])
        if (!odw[it])
            dfs(it);
    pos[++zeit] = a;
}

void dfs2(int a, int spoj) {
    odw[a] = true;
    rozm[spoj]++;
    spojna[a] = spoj;
    for (auto it : rv[a])
        if (!odw[it])
            dfs2(it, spoj);
}

void dfs3(int a) {
    odw[a] = true;
    rozmiar++;
    if (rozm[spojna[a]] != 1)
        som = true;
    for (auto it : v[a])
        if (!odw[it])
            dfs3(it);
    for (auto it : rv[a])
        if (!odw[it])
            dfs3(it);
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int a, b;
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        rv[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
        if (!odw[i])
            dfs(i);
    memset(odw + 1, 0, N * sizeof(bool));
    int ile = 0;
    for (int i = zeit; i > 0; i--)
        if (!odw[pos[i]])
            dfs2(pos[i], ++ile);
    memset(odw + 1, 0, N * sizeof(bool));
    int wyn = 0;
    for (int i = 1; i <= N; i++) {
        if (!odw[i]) {
            som = false;
            rozmiar = 0;
            dfs3(i);
            som = !som;
            wyn += rozmiar - som;
        }
    }
    printf("%d", wyn);
    return 0;
}