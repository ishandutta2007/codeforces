#include <cstdio>
#include <vector>
using namespace std;
struct Data {
    long long ans;
    int zero, one;
    Data() : ans(0), zero(0), one(0) {}
};
int w[100000];
vector<int> adj[100000];
bool bw[100000];
Data dfs(int v, int p) {
    Data data;
    if(bw[v])
        data.one = data.ans = 1;
    else
        data.zero = 1;

    for(int c : adj[v])
        if(c != p) {
            Data cd = dfs(c, v);
            data.ans += cd.ans;
            data.ans += (long long) data.zero * cd.one;
            data.ans += (long long) data.one * cd.zero;
            if(bw[v])
                swap(cd.zero, cd.one);
            data.zero += cd.zero;
            data.one += cd.one;
        }
    return data;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", w + i);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    long long ans = 0;
    for(int i = 1; i < (1 << 20); i <<= 1) {
        for(int j = 0; j < n; j++)
            bw[j] = w[j] & i;
        ans += dfs(0, -1).ans * i;
        // printf("ans->%lld\n", ans);
    }
    printf("%lld\n", ans);
}