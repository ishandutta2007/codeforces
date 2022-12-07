#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;

struct SB {
    int x, y, val;
    SB() {}
    SB(int x, int y, int val) : x(x), y(y), val(val) {}

    bool operator < (const SB& c) const {
        return val > c.val;
    }
} sb[N * N];
int sn;

int n, m;
long long k;

int cnt[N][N], vis[N][N], a[N][N];
int parent[N * N], sum[N * N];

int st[N * N], top;
int find(int x) {
    top = 0;
    while (x != parent[x]) {
        st[top++] = x;
        x = parent[x];
    }
    for (int i = 0; i < top; i++)
        parent[st[i]] = x;
    return x;
}

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

void cao(int x, int y) {
    int pu = find(x);
    int pv = find(y);
    if (pu != pv) {
        sum[pv] += sum[pu];
        parent[pu] = pv;
    }
}

int add(int x, int y) {
  //  printf("%d %d!!\n", x, y);
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx <= 0 || xx > n || yy <= 0 || yy > m) continue;
        if (vis[xx][yy] == 0) continue;
        cao((x - 1) * m + y, (xx - 1) * m + yy);
    }
}

int ans[N][N], md[N][N];
long long need;

void dfs(int x, int y, int w) {
    if (need == 0) return;
    ans[x][y] = w;
    md[x][y] = 1;
   // printf("%d %d %lld\n", x, y, need);
    need--;
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx <= 0 || xx > n || yy <= 0 || yy > m || md[xx][yy] || a[xx][yy] < w) continue;
        dfs(xx, yy, w);
    }
}

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}
int main() {
    scanf("%d%d%lld", &n, &m, &k);
    int x;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &x);
            a[i][j] = x;
            sb[sn++] = SB(i, j, x);
        }
    }
    for (int i = 1; i <= n * m; i++) {
        parent[i] = i;
        sum[i] = 1;
    }
    sort(sb, sb + sn);
    for (int i = 0; i < sn; i++) {
        int last = sn;
        for (int j = i; j < sn; j++) {
            if (sb[j].val != sb[i].val) {
                last = j;
                break;
            }
        }
        for (int j = i; j < last; j++) {
            add(sb[j].x, sb[j].y);
        }
        for (int j = i; j < last; j++)
            cnt[sb[j].x][sb[j].y] = sum[find((sb[j].x - 1) * m + sb[j].y)];
        i = last - 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //printf("%lld %d\n", k / a[i][j], cnt[i][j]);
            if (k % a[i][j] == 0 && k / a[i][j] <= 1LL * cnt[i][j]) {
                printf("YES\n");
                need = k / a[i][j];
                dfs(i, j, a[i][j]);
                print();
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}