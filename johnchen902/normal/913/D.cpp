#include <cstdio>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std;
struct P {
    int a, t, id;
} p[200000];
bool operator < (P lhs, P rhs) { // for pq
    return lhs.t < rhs.t; // pop largest first
}
int main() {
    int n, t;
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p[i].a, &p[i].t);
        p[i].id = i + 1;
    }
    sort(p, p + n, [](P lhs, P rhs) { return lhs.a > rhs.a; });
    int ans = 0;
    {
        priority_queue<P> pq;
        long long sumt = 0;
        for (int k = n, i = 0; k >= 1; k--) {
            for (; i < n && p[i].a >= k; i++) {
                sumt += p[i].t;
                pq.push(p[i]);
            }
            while (sumt > t) {
                sumt -= pq.top().t;
                pq.pop();
            }
            ans = max(ans, min(k, (int) pq.size()));
        }
    }
    if (ans == 0) {
        puts("0\n0\n");
        return 0;
    }
    {
        priority_queue<P> pq;
        long long sumt = 0;
        for (int k = n, i = 0; k >= 1; k--) {
            for (; i < n && p[i].a >= k; i++) {
                sumt += p[i].t;
                pq.push(p[i]);
            }
            while (sumt > t) {
                sumt -= pq.top().t;
                pq.pop();
            }
            if (min(k, (int) pq.size()) == ans) {
                printf("%d\n%d\n", ans, ans);
                for (int j = 0; j < ans; j++) {
                    printf("%d%c", pq.top().id, j == ans - 1 ? '\n' : ' ');
                    pq.pop();
                }
                return 0;
            }
        }
    }
    assert(false);
}