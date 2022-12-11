#include <functional>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 2e5 + 10;
int n, m;
int u[N], v[N], dir[N];
struct node {
    int v, id;
};
vector<node> G[N];
bool fail = 0;
void dfs(int u, int t = -1, int la = -1) {
    if(fail) return ;
    for(node &e : G[u]) if(e.id != la) {
        if(t == -1) {
            dir[e.id] = :: u[e.id] != u;
            dfs(e.v, 0, e.id);
        } else {
            int uu = t ? u : e.v;
            int dd = :: u[e.id] != uu;
            if(~ dir[e.id]) {
                if(dir[e.id] != dd) {
                    fail = 1; return ;
                }
                continue ;
            }
            dir[e.id] = dd;
            dfs(e.v, t ^ 1, e.id);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++) {
        scanf("%d%d", u + i, v + i);
        G[u[i]].push_back({v[i], i});
        G[v[i]].push_back({u[i], i});
        dir[i] = -1;
    }
    dfs(1);
    if(fail) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for(int i = 1; i <= m; i ++)
        printf("%d", dir[i]);
    return 0;
}
/*
aaa -> 1
aab
*/