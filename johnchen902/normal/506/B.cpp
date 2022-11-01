#include <cstdio>
#include <vector>
using namespace std;
vector<int> adj[100000];
int state[100000];
int dj[100000];
bool cyc[100000];
bool used[100000];

int fnd(int x) {
    return dj[x] == -1 ? x : (dj[x] = fnd(dj[x]));
}

void dfs(int x) {
    if(state[x] == 1) {
        cyc[fnd(x)] = true;
        return;
    }
    if(state[x] == 2) return;

    state[x] = 1;
    for(int i : adj[x]) {
        dfs(i);
        int u = fnd(i), v = fnd(x);
        if(u != v) {
            dj[u] = v;
            cyc[v] |= cyc[u];
        }
    }
    state[x] = 2;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        adj[a].push_back(b);
    }
    for(int i = 0; i < n; i++)
        dj[i] = -1;
    for(int i = 0; i < n; i++)
        if(state[i] == 0)
            dfs(i);
    int c = 0;
    for(int i = 0; i < n; i++)
        if(!used[fnd(i)]) {
            used[fnd(i)] = true;
            if(!cyc[fnd(i)])
                c++;
        }

    printf("%d\n", n - c);
}