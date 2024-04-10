#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;

vector<vi> edges;

int n;

vector<int> result;
vector<int> init;
vector<int> goal;

void run(int v, int prev, bool x1, bool x2) {
    if ((goal[v] == init[v]) == x1) {
        x1 = !x1;
        result.push_back(v);
    }
    for (auto iter = edges[v].begin(); iter != edges[v].end(); ++iter) {
        if (*iter == prev)
            continue;
        run(*iter, v, x2, x1);
    }
}

int main(void) {
    scanf("%d", &n);
    edges.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u; --v;
        edges[v].push_back(u);
        edges[u].push_back(v);
    }
    init.resize(n);
    goal.resize(n);
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        init[i] = t;
    }
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        goal[i] = t;
    }
    run(0, -1, false, false);
    printf("%d\n", result.size());
    for (int i =0; i < result.size(); ++i) {
        printf("%d\n", result[i] + 1);
    }
    return 0;
}