#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
constexpr int maxn = 100000, sqrtn = 317;
int a[100000];
struct Q {
    int l, r, id;
} qu[100000];
int ans[100000];

int fr[100000];
int ff[100001] {100001}, ne[100001], pr[100001];
void add(int x) {
    int f = fr[x]++;
    ff[f]--;
    ff[f + 1]++;
    if(ff[f] == 0) {
        ne[pr[f]] = ne[f];
        pr[ne[f]] = pr[f];
    }
    if(ff[f + 1] == 1) {
        ne[f + 1] = ne[f];
        pr[f + 1] = pr[ne[f]];
        pr[ne[f + 1]] = ne[pr[f + 1]] = f + 1;
    }
}
void remove(int x) {
    int f = fr[x]--;
    ff[f]--;
    ff[f - 1]++;
    if(ff[f] == 0) {
        ne[pr[f]] = ne[f];
        pr[ne[f]] = pr[f];
    }
    if(ff[f - 1] == 1) {
        pr[f - 1] = pr[f];
        ne[f - 1] = ne[pr[f]];
        pr[ne[f - 1]] = ne[pr[f - 1]] = f - 1;
    }
}
void reset() {
    std::fill_n(fr, 100000, 0);
    ff[0] = 100001;
    std::fill_n(ff + 1, 100000, 0);
    ne[0] = pr[0] = 0;
}
pair<int, int> que2[1000];
int solve() {
    int ret = 0;
    using P = pair<int, int>;
    int q1x = ne[0], q2b = 0, q2e = 0;
#define NEMPTY() (q1x || q2b != q2e)
#define POP(X) (q1x && (q2b == q2e || q1x < que2[q2b].first) ? \
        (void) ((X) = P(q1x, ff[q1x]), q1x = ne[q1x]) : \
        (void) ((X) = que2[q2b++]))
#define PUSH(X) (que2[q2e++] = (X))
    while(NEMPTY()) {
        P p;
        POP(p);
        while(true) {
            if(p.second >= 2) {
                ret += (p.first * 2) * (p.second / 2);
                PUSH(P(p.first * 2, p.second / 2));
                p.second %= 2;
            }
            if(p.second && NEMPTY()) {
                P p2;
                POP(p2);
                ret += p.first + p2.first;
                PUSH(P(p.first + p2.first, 1));
                p2.second--;
                p = p2;
            } else {
                break;
            }
        }
    }
#undef PUSH
#undef POP
#undef NEMPTY
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", a + i);
        a[i]--;
    }
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%d %d", &qu[i].l, &qu[i].r);
        qu[i].l--;
        qu[i].id = i;
    }
    sort(qu, qu + q, [](const Q &lhs, const Q &rhs) {
                if(lhs.l / sqrtn != rhs.l / sqrtn)
                    return lhs.l / sqrtn < rhs.l / sqrtn;
                return lhs.r < rhs.r;
            });
    int l = qu[0].l, r = qu[0].l;
    for(int i = 0; i < q; i++) {
        int l1 = qu[i].l, r1 = qu[i].r;
        if(r1 < r) {
            reset();
            l = r = l1;
        }
        while(l > l1)
            add(a[--l]);
        while(r < r1)
            add(a[r++]);
        while(l < l1)
            remove(a[l++]);
        ans[qu[i].id] = solve();
    }
    for(int i = 0; i < q; i++)
        printf("%d\n", ans[i]);
}