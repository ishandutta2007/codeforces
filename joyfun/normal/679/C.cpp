#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 505;
const int dir[2][2] = {-1, 0, 0, -1};

int n, k;
char str[N][N];
int parent[N * N], cnt[N * N], id[N][N], idx, cc[N * N];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int vis[N * N], tmp[N * N], tn;

long long gao(int x) {
    int p = find(x);
    if (vis[p]) return 0;
    tmp[tn++] = p;
    vis[p] = 1;
    return cnt[p];
}

int cal(int x, int y) {
    int ans = k * k;
    tn = 0;
    for (int i = x; i < x + k; i++) {
        if (y - 1 >= 1 && str[i][y - 1] == 'X') ans += gao(id[i][y - 1]);
        if (y + k <= n && str[i][y + k] == 'X') ans += gao(id[i][y + k]);
    }
    for (int i = y; i < y + k; i++) {
        if (x - 1 >= 1 && str[x - 1][i] == 'X') ans += gao(id[x - 1][i]);
        if (x + k <= n && str[x + k][i] == 'X') ans += gao(id[x + k][i]);
    }
    for (int i = 0; i < tn; i++) vis[tmp[i]] = 0;
    return ans;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i] + 1);
        for (int j = 1; j <= n; j++) {
            if (str[i][j] == '.') str[i][j] = 'X';
            else str[i][j] = '.';
            id[i][j] = ++idx;
            parent[idx] = idx;
            cnt[idx] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (str[i][j] == '.') continue;
            for (int k = 0; k < 2; k++) {
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if (x <= 0 || x > n || y <= 0 || y > n || str[x][y] == '.') continue;
                int pu = find(id[i][j]);
                int pv = find(id[x][y]);
                if (pu != pv) {
                    parent[pu] = pv;
                    cnt[pv] += cnt[pu];
                }
            }
        }
    }
    memcpy(cc, cnt, sizeof(cnt));
    int ans = 0;
    for (int i = 1; i <= n - k + 1; i++) {
        memcpy(cnt, cc, sizeof(cc));
        for (int x = i; x < i + k; x++) {
            for (int y = 1; y < k; y++)
                cnt[find(id[x][y])]--;
        }
        for (int y = 1; y <= n - k + 1; y++) {
            for (int x = i; x < i + k; x++)
                cnt[find(id[x][y + k - 1])]--;
            ans = max(ans, cal(i, y));
            for (int x = i; x < i + k; x++)
                cnt[find(id[x][y])]++;
        }
    }
    printf("%d\n", ans);
    return 0;
}