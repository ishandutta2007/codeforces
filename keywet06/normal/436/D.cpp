#include <bits/stdc++.h>

const int N = 500500;

int a[N], b[N], ta[N];
int n, m, k, last[N], first[N], f[N], g[N];

std::pair<int, int> v[N];

bool can(int first, int len, int last) { return first + len - 1 >= last; }

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
    std::sort(a, a + n);
    std::sort(b, b + m);
    for (int i = 0; i < n; ++i) {
        int j = i, len = 0;
        while ((j < n) && (a[j] == a[i] + len)) ++len, ++j;
        v[k++] = std::make_pair(a[i], len);
        i = j - 1;
    }
    ta[0] = v[0].second;
    for (int i = 1; i < n; ++i) ta[i] = ta[i - 1] + v[i].second;
    n = k;
    int cur = 0, curLeft = 0;
    for (int i = 0; i < m; ++i) first[i] = n - 1;
    for (int i = 0; i < n; ++i) {
        while ((cur < m) && (b[cur] < v[i].first + v[i].second)) last[cur] = i, ++cur;
        if (i > 0) f[i] = std::max(f[i], f[i - 1]);
        for (int j = 0; j < cur; ++j) {
            while ((last[j] >= 0) &&
                   (!can(b[j], ta[i] - ta[last[j]] + v[last[j]].second, v[i].first + v[i].second - 1)))
                --last[j];
            if (last[j] < 0) continue;
            int cnt = cur - j;
            if (last[j] > 0) cnt += f[last[j] - 1];
            if (cnt > f[i]) f[i] = cnt;
        }
        while ((curLeft < m) && (b[curLeft] < v[i].first)) ++curLeft;
        int cost = 0;
        while ((curLeft + cost < m) && (b[curLeft + cost] < v[i].first + v[i].second)) ++cost;
        for (int j = curLeft; j < m; ++j) {
            if (b[j] < v[i].first) {
                first[j] = -1;
                ++curLeft;
                continue;
            }
            while ((first[j] > i) && (can(v[i].first, ta[first[j] - 1] - ta[i] + v[i].second, b[j]))) --first[j];
            int cnt;
            cnt = j - curLeft + 1 + f[i] - cost;
            if (can(v[i].first, ta[first[j]] - ta[i] + v[i].second, b[j])) g[first[j]] = std::max(g[first[j]], cnt);
        }
        f[i] = std::max(f[i], g[i]);
    }
    printf("%d\n", f[n - 1]);
    return 0;
}