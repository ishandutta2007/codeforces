#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 100005;

int n, m, s, a[N], ans[N];

struct S {
    int b, c, id;
    friend bool operator < (S a, S b) {
        return a.c > b.c;
    }
} st[N];

struct B {
    int a, id;
} bd[N];

int cmp(S a, S b) {
    return a.b > b.b;
}

int cmp1(B a, B b) {
    return a.a < b.a;
}

void init() {
    int i;
    scanf("%d%d%d", &n, &m, &s);
    for (i = 0; i < m; i ++) {
        scanf("%d", &bd[i].a);
        bd[i].id = i;
    }
    for (i = 0; i < n; i ++) {
        scanf("%d", &st[i].b);
        st[i].id = i;
    }
    for (i = 0; i < n; i ++)
        scanf("%d", &st[i].c);
    sort(bd, bd + m, cmp1);
    sort(st, st + n, cmp);
}

bool judge1(int time) {
    int ss = s, sn = 0;
    priority_queue<S>Q;
    for (int i = m - 1; i >= 0; i -= time) {
        while (st[sn].b >= bd[i].a && sn != n) {Q.push(st[sn++]);}
        if (Q.empty()) return false;
        S t = Q.top(); Q.pop();
        if (ss < t.c) return false;
        ss -= t.c;
        int e = i - time + 1;
        if (e < 0) e = 0;
        for (int j = i; j >= e; j--) {
            ans[bd[j].id] = t.id;
        }
    }
    return true;
}

bool judge(int time) {
    int ss = s, sn = 0;
    priority_queue<S>Q;
    for (int i = m - 1; i >= 0; i -= time) {
        while (st[sn].b >= bd[i].a && sn != n) {Q.push(st[sn++]);}
        if (Q.empty()) return false;
        S t = Q.top(); Q.pop();
        if (ss < t.c) return false;
        ss -= t.c;
    }
    return true;
}

void solve() {
    int l = 0, r = m;
    if (!judge(r)) {
        printf("NO\n"); return;
    }
    while (l < r) {
        int mid = (l + r) / 2;
        if (judge(mid)) r = mid;
        else l = mid + 1;
    }
    judge1(r);
    printf("YES\n");
    for (int i = 0; i < m - 1; i++)
        printf("%d ", ans[i] + 1);
    printf("%d\n", ans[m - 1] + 1);
}

int main() {
    init();
    solve();
    return 0;
}