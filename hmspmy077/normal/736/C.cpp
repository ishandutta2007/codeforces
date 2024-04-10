#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

#define ALL(v) (v).begin(), (v).end()
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)

const int N = 2000;

int n, m, r;
bool special[N];
short dist[N][N];
std::vector <int> edge[N];

void prepare(short* dist, int p, int u)
{
    dist[u] = ~p ? dist[p] + 1 : 0;
    foreach (v, edge[u]) {
        if (*v != p) {
            prepare(dist, u, *v);
        }
    }
}

const int MOD = (int)1e9 + 7;

int ways[N][N], aux[N][N], count[N];

void solve(int p, int u)
{
    foreach (iterator, edge[u]) {
        const int &v = *iterator;
        if (v != p) {
            solve(u, v);
        }
    }
    std::vector <std::pair <int, int> > orderp, orderu;
    for (int c = 0; c < n; ++ c) {
        if (~p) {
            orderp.push_back(std::make_pair(dist[p][c], c));
        }
        orderu.push_back(std::make_pair(dist[u][c], c));
        if (!special[u] || dist[u][c] <= r) {
            int& way = ways[u][c];
            way = 1;
            foreach (iterator, edge[u]) {
                const int &v = *iterator;
                if (v != p) {
                    bool belongs = dist[0][c] == dist[0][v] + dist[v][c];
                    way = (long long)way * (belongs ? ways[v][c] : aux[v][c]) % MOD;
                }
            }
        }
    }
    if (~p) {
        std::sort(ALL(orderp));
        std::sort(ALL(orderu));
        memset(count, 0, sizeof(count));
        foreach (iterator, orderu) {
            const int &v = iterator->second;
            int idx = std::lower_bound(ALL(orderp), std::make_pair((int)dist[p][v], v)) - orderp.begin();
            const int &way = ways[u][v];
            int &sum = aux[u][v];
            sum = way;
            for (int k = idx; k < n; k += ~k & k + 1) {
                sum += count[k];
                if (sum >= MOD) {
                    sum -= MOD;
                }
            }
            for (int k = idx; k >= 0; k -= ~k & k + 1) {
                count[k] += way;
                if (count[k] >= MOD) {
                    count[k] -= MOD;
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &r);
    memset(special, 0, sizeof(special));
    for (int i = 0; i < n; ++ i) {
        special[i] = true;
    }
    for (int i = 0; i < n - 1; ++ i) {
        int a, b;
        scanf("%d%d", &a, &b);
        a --;
        b --;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (int i = 0; i < n; ++ i) {
        prepare(dist[i], -1, i);
    }
    memset(ways, 0, sizeof(ways));
    solve(-1, 0);
    int result = 0;
    for (int i = 0; i < n; ++ i) {
        result += ways[0][i];
        if (result >= MOD) {
            result -= MOD;
        }
    }
    printf("%d\n", result);
}