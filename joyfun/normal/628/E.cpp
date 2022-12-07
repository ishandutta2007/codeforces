#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 3005;

int n, m;
int L[N][N], R[N][N];
char str[N][N];
int tmp[N][2], tn;
int bit[N];
vector<int> g[N];

#define lowbit(x) (x&(-x))

void add(int x, int v) {
    while (x <= tn) {
        bit[x] += v;
        x += lowbit(x);
    }
}

int get(int x) {
    int ans = 0;
    while (x) {
        ans += bit[x];
        x -= lowbit(x);
    }
    return ans;
}

int get(int l, int r) {
    return get(r) - get(l - 1);
}

long long cal() {
    long long ans = 0;
    for (int i = 1; i <= tn; i++) {
        int x = tmp[i][0];
        int y = tmp[i][1];
        g[min(tn, i + L[x][y] - 1)].push_back(i);
        add(i, 1);
        ans += get(max(1, i - R[x][y] + 1), i);
        for (int j = 0; j < g[i].size(); j++)
            add(g[i][j], -1);
    }
    return ans;
}

long long gao(int d) {
    long long ans = 0;
    for (int x = 1; x <= n; x++) {
        int y = d - x;
        if (y <= 0 || y > m) continue;
        if (str[x][y] == '.') {
            ans += cal();
            tn = 0;
        }
        else {
            ++tn;
            g[tn].clear();
            tmp[tn][0] = x;
            tmp[tn][1] = y;
        }
    }
    ans += cal();
    tn = 0;
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", str[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            L[i][j] = L[i][j - 1] + 1;
            if (str[i][j] == '.') L[i][j] = 0;
        }
        for (int j = m; j >= 1; j--) {
            R[i][j] = R[i][j + 1] + 1;
            if (str[i][j] == '.') R[i][j] = 0;
        }
    }
    long long ans = 0;
    for (int i = 2; i <= n + m; i++)
        ans += gao(i);
    printf("%lld\n", ans);
    return 0;
}