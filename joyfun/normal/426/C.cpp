#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define max(a, b) ((a)>(b)?(a):(b))
int n, k, a[205], i, j, vis[205];

struct cmp {
    bool operator() (int &a, int &b) {
        return a > b;
    }
};

int cal(int l, int r) {
    priority_queue<int, vector<int>, cmp> Q;
    int sum = 0, i;
    for (i = l; i <= r; i++) {
        sum += a[i];
        Q.push(a[i]);
    }
    int kk = k;
    memset(vis, 0, sizeof(vis));
    while (kk--) {
        int maxx = -INF, max_v;
        for (i = 0; i < n; i++) {
            if ((i >= l && i <= r) || vis[i]) continue;
            if (maxx < a[i]) {
                maxx = a[i];
                max_v = i;
            }
        }
        if (Q.top() < maxx) {
            sum = sum - Q.top() + maxx;
            Q.pop();
            Q.push(maxx);
            vis[max_v] = 1;
        }
    }
    return sum;
}

int main() {
    int ans = -INF;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++) {
            int t = cal(i, j);
            ans = max(ans, t);
        }
    printf("%d\n", ans);
    return 0;
}