#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

const int N = 200005;

int n, m, a[N];
int tt[N], rr[N], t[N], r[N];
multiset<int> s;
multiset<int>::iterator it;

int ans[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &tt[i], &rr[i]);
    }
    int tot = 0;
    r[tot++] = 0;
    for (int i = 0; i < m ; i++) {
        while (tot && rr[i] >= r[tot - 1]) tot--;
        r[tot] = rr[i];
        t[tot] = tt[i];
        tot++;
    }
    for (int i = r[0] + 1; i <= n; i++) ans[i] = a[i];
    for (int i = 1; i <= r[0]; i++)
        s.insert(a[i]);
    r[tot] = 0;
    for (int i = 0; i < tot; i++) {
        //printf("%d %d %d\n", r[i + 1] + 1, r[i], t[i]);
        for (int j = r[i]; j >= r[i + 1] + 1; j--) {
            if (t[i] == 2) {
                it = s.begin();
                ans[j] = *it;
                s.erase(it);
            } else {
                it = s.end(); it--;
                ans[j] = *it;
                s.erase(it);
            }
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}