#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#include <functional>
#include <utility>
#include <vector>

#define ALL(v) (v).begin(), (v).end()

const int K = 4;
const int N = 300000;

struct Summary
{
    Summary()
    {
        memset(count, 0, sizeof(count));
        memset(value, 0, sizeof(value));
    }

    int count[5], value[5];
};

Summary merge(Summary a, const Summary& b)
{
    for (int j = 0; j < K; ++ j) {
        if (b.count[j]) {
            int i = 0, i_min = 0;
            while (i < K && a.value[i] != b.value[j]) {
                if (a.count[i] < a.count[i_min]) {
                    i_min = i;
                }
                i ++;
            }
            if (i < K) {
                a.count[i] += b.count[j];
            } else if (a.count[i_min] >= b.count[j]) {
                for (int i = 0; i < K; ++ i) {
                    a.count[i] -= b.count[j];
                }
            } else {
                int t = a.count[i_min];
                for (int i = 0; i < K; ++ i) {
                    a.count[i] -= t;
                }
                a.count[i_min] = b.count[j] - t;
                a.value[i_min] = b.value[j];
            }
        }
    }
    return a;
}

int get_id(int l, int r)
{
    return l + r | l != r;
}

int a[N];
Summary summary[N << 1];

void build(int l, int r)
{
    int u = get_id(l, r);
    if (l < r) {
        int m = l + r >> 1;
        build(l, m);
        build(m + 1, r);
        summary[u] = merge(summary[get_id(l, m)], summary[get_id(m + 1, r)]);
    } else {
        summary[u].count[0] = 1;
        summary[u].value[0] = a[l];
    }
}

Summary query(int l, int r, int a, int b)
{
    if (b < l || r < a) {
        return Summary();
    }
    int u = get_id(l, r);
    if (a <= l && r <= b) {
        return summary[u];
    } else {
        int m = l + r >> 1;
        if (b <= m) {
            return query(l, m, a, b);
        }
        if (m < a) {
            return query(m + 1, r, a, b);
        }
        return merge(query(l, m, a, b), query(m + 1, r, a, b));
    }
}

std::vector<int> indices[N + 1];

int main()
{
#ifdef LOCAL_JUDGE
    freopen("D.in", "r", stdin);
#endif
    int n, m, p;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
        indices[a[i]].push_back(i);
    }
    build(0, n - 1);
    while (m --) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        l --;
        r --;
        Summary result = query(0, n - 1, l, r);
        int rr = INT_MAX;
        for (int i = 0; i < K; ++ i) {
            int x = result.value[i];
            if (1 <= x && x <= n) {
                int cnt = std::upper_bound(ALL(indices[x]), r) - std::lower_bound(ALL(indices[x]), l);
                if ((long long)cnt * k > (r - l + 1)) {
                    rr = std::min(rr, x);
                }
            }
        }
        printf("%d\n", rr == INT_MAX ? -1 : rr);
    }
}