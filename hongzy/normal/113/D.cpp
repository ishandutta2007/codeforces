#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int N = 25;

int n, m, s, t, deg[N];
double mov[N], p[N];
vector<int> G[N];

double calc(int u, int v) {
    return u == v ? p[u] : mov[u];
}

int pos(int u, int v) {
    return (u - 1) * n + v;
}

double a[N * N][N * N];

void gauss(int n) {
    for(int i = 1, j = 1; i <= n; j = ++ i) {
        for(int k = i + 1; k <= n; k ++) if(fabs(a[j][i]) < fabs(a[k][i])) j = k;
        if(i != j) for(int k = i; k <= n + 1; k ++) swap(a[j][k], a[i][k]);
        if(fabs(a[i][i]) < 1e-17) puts("error!");
        for(j = i + 1; j <= n; j ++) {
            double z = a[j][i] / a[i][i];
            for(int k = i; k <= n + 1; k ++) a[j][k] -= z * a[i][k];
        }
    }
    for(int i = n; i >= 1; i --) {
        for(int j = i + 1; j <= n; j ++) a[i][n + 1] -= a[j][n + 1] * a[i][j];
        a[i][n + 1] /= a[i][i];
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int u, v, i = 1; i <= m; i ++) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u] ++; deg[v] ++;
    }
    for(int i = 1; i <= n; i ++) {
        scanf("%lf", p + i);
        G[i].push_back(i);
        mov[i] = (1 - p[i]) / deg[i];
    }
    int k = n * n;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            int p = pos(i, j);
            a[p][p] = -1;
            if(i == s && j == t) a[p][k + 1] = -1;
            for(int x = 0; x < G[i].size(); x ++) {
                int u = G[i][x];
                for(int y = 0; y < G[j].size(); y ++) {
                    int v = G[j][y];
                    if(u == v) continue ;
                    a[p][pos(u, v)] += calc(u, i) * calc(v, j);
                }
            }
        }
    }
    gauss(k);
    for(int i = 1; i <= n; i ++)
        printf("%.10f ", fabs(a[pos(i, i)][k + 1]));
    return 0;
}
/*
f(s, t) = 1
f(i, j) = \sum_{ edge(u, i), edge(v, j), u != v} f(u, v) * calc(u, i) * calc(v, j)
calc(u, v) : u == v ? p[u] : mov[u]
*/