#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>

#define ALL(v) (v).begin(), (v).end()

struct Query
{
    Query(int a, int t, int x, int id) : a(a), t(t), x(x), id(id) {}

    int a, t, x, id;
};

bool operator < (const Query& a, const Query& b)
{
    if (a.x != b.x)
    {
        return a.x < b.x;
    }
    return a.id < b.id;
}

int main()
{
    int n;
    scanf("%d", &n);
    std::vector<Query> queries;
    for (int i = 0; i < n; ++ i) {
        int a, t, x;
        scanf("%d%d%d", &a, &t, &x);
        queries.emplace_back(a, t, x, i);
    }
    std::vector<int> result(n, -1);
    std::sort(queries.begin(), queries.end());
    for (int l = 0; l < n; ) {
        int r = l;
        while (r < n && queries[l].x == queries[r].x) {
            r ++;
        }
        std::vector<int> times;
        for (int i = l; i < r; ++ i) {
            times.push_back(queries[i].t);
        }
        std::sort(ALL(times));
        int m = times.size();
        std::vector<int> count(m);
        for (int i = l; i < r; ++ i) {
            int idx = std::lower_bound(ALL(times), queries[i].t) - times.begin();
            int delta = 0;
            if (queries[i].a == 1) {
                delta = 1;
            } else if (queries[i].a == 2) {
                delta = -1;
            }
            if (delta) {
                for (; idx < m; idx += ~idx & idx + 1) {
                    count[idx] += delta;
                }
            } else {
                int& ref = result[queries[i].id];
                ref = 0;
                for (; idx >= 0; idx -= ~idx & idx + 1) {
                    ref += count[idx];
                }
            }
        }
        l = r;
    }
    for (int i = 0; i < n; ++ i) {
        if (~result[i]) {
            printf("%d\n", result[i]);
        }
    }
}