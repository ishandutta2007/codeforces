#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int N = 100005;

int n;

struct Table {
    int l, d;
    void read() {
        scanf("%d%d", &l, &d);
    }
} t1[N];

bool cmp(Table a, Table b) {
    return a.l < b.l;
}

int sum[N], num[N];
int tot[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &t1[i].l);
    for (int i = 1; i <= n; i++) scanf("%d", &t1[i].d);
    for (int i = 1; i <= n; i++) {
        sum[t1[i].l] += t1[i].d;
        num[t1[i].l]++;
    }
    for (int i = N - 2; i >= 0; i--) {
        sum[i] += sum[i + 1];
        num[i] += num[i + 1];
    }
    sort(t1 + 1, t1 + n + 1, cmp);
    int Min = 2000000000;
    for (int i = 1; i <= n; i++) {
        if (t1[i].l != t1[i - 1].l) {
            int ans = sum[t1[i].l + 1];
            int need = n - num[t1[i].l] - (num[t1[i].l] - num[t1[i].l + 1] - 1);
            if (need < 0) need = 0;
            for (int j = 1; j <= 200; j++) {
                if (need < tot[j]) {
                    ans += need * j; 
                    need = 0;
                    break;
                } else {
                    ans += tot[j] * j;
                    need -= tot[j];
                }
            }
            if (!need) Min = min(Min, ans);
        }
        tot[t1[i].d]++;
    }
    printf("%d\n", Min);
    return 0;
}