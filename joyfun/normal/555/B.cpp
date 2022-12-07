#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef unsigned long long ll;

const int N = 200005;
int n, m;
ll pl, pr, l, r;
ll a[N];

struct Seg {
    int id;
    ll l, r;
    Seg() {}
    Seg(ll l, ll r) {
        this->l = l;
        this->r = r;
    }
    bool operator < (const Seg& c) const {
        return r > c.r;
    }
} seg[N];

struct Bg {
    ll a;
    int id;
} bg[N];

bool cmp1(Seg a, Seg b) {
    return a.l < b.l;
}

bool cmp2(Bg a, Bg b) {
    return a.a < b.a;
}

int out[N];

int main() {
    scanf("%d%d", &n, &m);
    scanf("%llu%llu", &pl, &pr);
    n--;
    for (int i = 0; i < n; i++) {
        scanf("%llu%llu", &l, &r);
        seg[i] = Seg(l - pr, r - pl);
        seg[i].id = i;
        pl = l;
        pr = r;
    }
    for (int i = 0; i < m; i++) {
        scanf("%llu", &bg[i].a);
        bg[i].id = i + 1;
    }
    sort(bg, bg + m, cmp2);
    sort(seg, seg + n, cmp1);
    priority_queue<Seg> Q;
    int u = 0;
    int flag = 1;
/*  for (int i = 0; i < n; i++)
        printf("%llu %llu\n", seg[i].l, seg[i].r);
    for (int i = 0; i < m; i++)
        printf("%llu ", bg[i].a); printf("\n");*/
    int on = 0;
    for (int i = 0; i < m; i++) {
        while (u < n && seg[u].l <= bg[i].a) {
            Q.push(seg[u]);
            u++;
        }
        if (Q.empty() || Q.top().r < bg[i].a)
            continue;
        out[Q.top().id] = bg[i].id;
        on++;
        Q.pop();
    }
    if (on != n) {
        printf("No\n");
    } else {
        printf("Yes\n");
        for (int i = 0; i < n; i++) printf("%d ", out[i]);
    }
    return 0;
}