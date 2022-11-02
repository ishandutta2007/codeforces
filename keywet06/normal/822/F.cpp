#include <bits/stdc++.h>

typedef long long int64;
typedef double ldou;
typedef std::pair<int, int> Pair;

std::vector<int> conn[105];
std::vector<int> son[105];
std::map<Pair, int> Mx;

ldou ans[105];

int in[105][2];

bool dchk[105];

void Dfs(int n, ldou prv) {
    dchk[n] = true;
    prv += 1;
    for (auto it : conn[n]) {
        if (dchk[it]) continue;
        prv += 2.0 / (int)conn[n].size();
        int x = Mx[Pair(n, it)];
        ldou a = prv;
        if (in[x][0] != n) a += 1;
        ans[x] = a;
        Dfs(it, prv);
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 1; i < n; ++i) {
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        conn[t1].push_back(t2);
        conn[t2].push_back(t1);
        Mx[Pair(t1, t2)] = i;
        Mx[Pair(t2, t1)] = i;
        in[i][0] = t1, in[i][1] = t2;
    }
    Dfs(1, 2.0 / 3);
    printf("%d\n", n - 1);
    for (i = 1; i < n; ++i) {
        int v = (int)(ans[i] / 2);
        ans[i] -= 2 * v;
        printf("1 %d ", i);
        if (ans[i] < 1) {
            printf("%d %d %.10lf\n", in[i][0], in[i][1], ans[i]);
        } else {
            printf("%d %d %.10lf\n", in[i][1], in[i][0], ans[i] - 1);
        }
    }
    return 0;
}