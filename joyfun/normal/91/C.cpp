#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000000009;
const int N = 100005;

int n, m, u, v;
int parent[N];
int pow2[N];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    scanf("%d%d", &n, &m);
    pow2[0] = 1;
    for (int i = 1; i <= m; i++) pow2[i] =1LL * pow2[i - 1] * 2 % MOD;
    for (int i = 1; i <= n; i++) parent[i] = i;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) parent[pu] = pv;
        else cnt++;
        printf("%d\n", (pow2[cnt] - 1 + MOD) % MOD);
    }

    return 0;
}