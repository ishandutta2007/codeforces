#include <cstdio>
#include <vector>

std::vector<int> v[1000007];
int gl[1000007];
int oj[1000007][20];
int pre[1000007], pos[1000007], zeit;
bool biere[1000007];

void dfs(int a, int moj) {
    pre[a] = ++zeit;
    oj[a][0] = moj;
    for (int i = 1; i < 20; i++)
        oj[a][i] = oj[oj[a][i - 1]][i - 1];
    gl[a] = gl[moj] + 1;
    for (auto it : v[a])
        if (it != moj)
            dfs(it, a);
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

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    K = N - K;
    int a, b, c;
    for (int i = 1; i < N; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 1);
    biere[N] = true;
    K--;
    for (int i = N - 1; i >= 1; i--) {
        if (biere[i])
            continue;
        a = N, b = i;
        c = lca(a, b);
        if (!biere[c]) {
            int skok = 19;
            while (skok >= 0) {
                if (isOj(oj[a][skok], c)) {
                    skok--;
                    continue;
                }
                if (biere[oj[a][skok]])
                    a = oj[a][skok];
                else
                    skok--;
            }
            int odl = gl[b] - gl[c] + gl[a] - gl[c];
            if (odl > K)
                continue;
            K -= odl;
            do {
                a = oj[a][0];
                biere[a] = true;
            } while (a != c);
            while (b != c) {
                biere[b] = true;
                b = oj[b][0];
            }
        } else {
            int dokad = b;
            int skok = 19;
            while (skok >= 0 && dokad != 1) {
                if (isOj(oj[dokad][skok], c)) {
                    skok--;
                    continue;
                }
                if (biere[oj[dokad][skok]])
                    skok--;
                else
                    dokad = oj[dokad][skok];
            }
            int odl = gl[b] - gl[dokad] + 1;
            if (odl > K)
                continue;
            K -= odl;
            while (!biere[b]) {
                biere[b] = true;
                b = oj[b][0];
            }
        }
    }
    for (int i = 1; i <= N; i++)
        if (!biere[i])
            printf("%d ", i);
    return 0;
}