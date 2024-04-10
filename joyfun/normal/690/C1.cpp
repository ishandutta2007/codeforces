#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1005;
int n, m, parent[N];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) parent[i] = i;
    int u, v;
    int f = 1, cnt = n;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            parent[pu] = pv;
            cnt--;
        }
        else f = 0;
    }
    printf("%s\n", (cnt == 1 && f) ? "yes" : "no");
    return 0;
}