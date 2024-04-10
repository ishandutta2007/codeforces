#include <cstdio>
#include <vector>

std::vector<int> v[200007];
bool odw[200007];
int pre[200007], pos[200007], low[200007];
int oj[200007][20];
int spojna[200007];
int skladowa[200007];
int wdol[200007];
int wgore[200007];
int gl[200007];
std::vector<int> kr[200007];
int zeit;

void dfs(int a, int moj, int sk) {
    skladowa[a] = sk;
    odw[a] = true;
    low[a] = pre[a] = ++zeit;
    bool byl = false;
    for (auto it : v[a]) {
        if (!odw[it]) {
            dfs(it, a, sk);
            low[a] = std::min(low[a], low[it]);
//            if (low[it] > pre[a]) {
//                printf("most %d %d\n", a, it);
//            }
        } else if (it != moj || byl) {
            low[a] = std::min(low[a], pre[it]);
        } else if (it == moj) {
            byl = true;
        }
    }
}

void dfsZbij(int a, int num) {
    odw[a] = true;
    spojna[a] = num;
    for (auto it : v[a])
        if (!odw[it] && (pre[it] > pre[a] ? low[it] <= pre[a] : low[a] <= pre[it]))
            dfsZbij(it, num);
}

void dfsLca(int a, int moj) {
    pre[a] = ++zeit;
    gl[a] = gl[moj] + 1;
    oj[a][0] = moj;
    for (int i = 1; i < 20; i++)
        oj[a][i] = oj[oj[a][i - 1]][i - 1];
    for (auto it : kr[a])
        if (it != moj)
            dfsLca(it, a);
    pos[a] = zeit;
}

bool isOj(int a, int b) {
    return pre[a] <= pre[b] && pos[b] <= pos[a];
}

int lca(int a, int b) {
    if (isOj(a, b))
        return a;
    int skok = 19;
    while (skok >= 0) {
        if (isOj(oj[a][skok], b))
            skok--;
        else
            a = oj[a][skok];
    }
    return oj[a][0];
}

bool wynik = true;

void dfsSprawdz(int a, int moj) {
    odw[a] = true;
    for (auto it : kr[a]) {
        if (it != moj) {
            dfsSprawdz(it, a);
            wgore[a] = std::max(wgore[a], wgore[it] - 1);
            wdol[a] = std::max(wdol[a], wdol[it] - 1);
        }
    }
    if (wgore[a] > 0 && wdol[a] > 0)
        wynik = false;
}

int main() {
    int N, M, Q;
    scanf("%d%d%d", &N, &M, &Q);
    int a, b;
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int skl = 0;
    for (int i = 1; i <= N; i++) {
        if (!odw[i])
            dfs(i, -1, ++skl);
    }
    for (int i = 1; i <= N; i++) odw[i] = false;
    int ile = 0;
    for (int i = 1; i <= N; i++)
        if (!odw[i])
            dfsZbij(i, ++ile);
    for (int i = 1; i <= N; i++)
        for (auto it : v[i])
            if (spojna[it] != spojna[i])
                kr[spojna[i]].push_back(spojna[it]);
    zeit = 0;
    for (int i = 1; i <= ile; i++)
        if (pos[i] == 0)
            dfsLca(i, i);
    while (Q--) {
        scanf("%d%d", &a, &b);
        if (skladowa[a] != skladowa[b]) {
            wynik = false;
            break;
        }
        a = spojna[a], b = spojna[b];
        int c = lca(a, b);
        wgore[a] = std::max(wgore[a], gl[a] - gl[c]);
        wdol[b] = std::max(wdol[b], gl[b] - gl[c]);
    }
    for (int i = 1; i <= ile; i++)
        if (oj[i][0] == i)
            dfsSprawdz(i, -1);
    printf(wynik ? "Yes" : "No");
    return 0;
}