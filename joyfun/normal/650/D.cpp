#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;

const int N = 400005;

int n, m, x[N], a[N], b[N], h[N * 2], hn, ans[N];
vector<int> s[N];

void init() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
        h[hn++] = x[i];
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a[i], &b[i]);
        h[hn++] = b[i];
    }
    sort(h, h + hn);
    hn = unique(h, h + hn) - h;
    for (int i = 1; i <= n; i++)
        x[i] = lower_bound(h, h + hn, x[i]) - h + 1;
    for (int i = 1; i <= m; i++) {
        b[i] = lower_bound(h, h + hn, b[i]) - h + 1;
        s[a[i]].push_back(i);
    }
}

#define lowbit(x) (x&(-x))

int bit[N * 2];

void add(int x, int v) {
    while (x <= hn) {
        bit[x] = max(bit[x], v);
        x += lowbit(x);
    }
}

int get(int x) {
    int ans = 0;
    while (x) {
        ans = max(ans, bit[x]);
        x -= lowbit(x);
    }
    return ans;
}

int must[N], pre[N], suf[N], cnt[N];

void gao() {
    memset(bit, 0, sizeof(bit));
    for (int i = 1; i <= m; i++) ans[i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < s[i].size(); j++) {
            int id = s[i][j];
            ans[id] += get(b[id] - 1);
        }
        add(x[i], pre[i] = get(x[i] - 1) + 1);
    }
    memset(bit, 0, sizeof(bit));
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < s[i].size(); j++) {
            int id = s[i][j];
            int bb = hn - b[id] + 1;
            ans[id] += get(bb - 1);
        }
        int xx = hn - x[i] + 1;
        add(xx, suf[i] = get(xx - 1) + 1);
    }
    int Max = 0;
    for (int i = 1; i <= n; i++)
        Max = max(Max, pre[i] + suf[i] - 1);
    for (int i = 1; i <= n; i++)
        if (pre[i] + suf[i] - 1 == Max)
            cnt[pre[i]]++;
    for (int i = 1; i <= n; i++)
        if (pre[i] + suf[i] - 1 == Max && cnt[pre[i]] == 1)
            must[i] = 1;
    for (int i = 1; i <= m; i++) {
        ans[i] = max(ans[i], must[a[i]] ? Max - 1 : Max);
        printf("%d\n", ans[i]);
    }
}

int main() {
    init();
    gao();
    return 0;
}