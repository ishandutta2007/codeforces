#include <cstdio>
#include <vector>
using namespace std;
int in[100000]; // in-degree; -1 for robots already won
vector<int> adj[100000];
int z[200000]; // potential robots with 0 in-degree
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int zn = n, zb = 0, ze = n;
    for(int i = 0; i < n; i++)
        z[i] = i;
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;

        if(zn == 0) {
            // just to read all inputs
            continue;
        }
        if(in[u] == -1) {
            // no information is provided
            continue;
        }

        adj[u].push_back(v);
        if(in[v]++ == 0)
            zn--;
        while(zn == 1) {
            while(in[z[zb]] != 0)
                zb++;
            // in[z[zb]] == 0
            zn = 0;
            in[z[zb]] = -1;
            for(int c : adj[z[zb]])
                if(--in[c] == 0) {
                    zn++;
                    z[ze++] = c;
                }
        }
        if(zn == 0) {
            // iff. everything determined
            printf("%d\n", i + 1);
        }
    }
    if(zn != 0)
        puts("-1");
}