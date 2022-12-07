#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 1005;

int n, vis[N], k;
struct Visit {
    int num, value, id;
} v[N];

struct Table {
    int num, id;
} t[N];

bool cmp(Visit a, Visit b) {
    if (a.value != b.value)
    return a.value > b.value;
    return a.num > b.num;
}

bool cmp2(Table a, Table b) {
    return a.num < b.num;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    scanf("%d%d", &v[i].num, &v[i].value);
    v[i].id = i;
    }
    sort(v, v + n, cmp);
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
    scanf("%d", &t[i].num);
    t[i].id = i;
    }
    sort(t, t + k, cmp2);
    int ans1 = 0, ans2 = 0, ans[N];
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
        if (vis[j]) continue;
        if (t[j].num >= v[i].num) {
        vis[j] = 1;
        ans[i] = t[j].id;
        ans1++;
        ans2 += v[i].value;
        break;
        }
    }
    }
    printf("%d %d\n", ans1, ans2);
    for (int i = 0; i < n; i++) {
    if (ans[i] == -1) continue;
    printf("%d %d\n", v[i].id + 1, ans[i] + 1);
    }
    return 0;
}