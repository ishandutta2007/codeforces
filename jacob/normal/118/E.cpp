#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef long long ll;
ll MOD = 100000000;

typedef pair<int, int> pii;
vector<pii> result;
typedef vector<int> vi;
vector<vi> edges;
vi d;

int dfs(int p, int de) {
    d[p] = de;
    int md = de;
    for (vi::const_iterator it = edges[p].begin(); it != edges[p].end(); it++) {
        if (d[*it] == -1) {
            result.push_back(pii(p, *it));
            md = min(md, dfs(*it, de + 1));
        } else if (d[*it] > de)
            result.push_back(pii(*it, p));
        else if (d[*it] != de - 1)
            md = min(md, d[*it]);
    }
    if (md == de && de != 0) {
        printf("0");
        exit(0);
    }
    return md;
}

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);
    edges.resize(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    d.assign(n+1, -1);
    dfs(1, 0);
    for (int i = 0; i < m; i++) {
        printf("%d %d\n", result[i].first, result[i].second);
    }
    return 0;
}