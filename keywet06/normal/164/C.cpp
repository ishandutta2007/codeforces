#include <bits/stdc++.h>

using namespace std;

const int N = 3010;
const int M = 2 * 25010;
const int inf = 1000000000;

map<int, int> mp;

struct abc {
    int s, t, c;
} c[1010];

int num[2010];

struct Node {
    int f, t, c, w;
} e[M];

int nxt[M], point[N], dis[N], q[N], pre[N], ne;
bool u[N];

int mmin(int x, int y) { return x < y ? x : y; }

void init() {
    memset(point, -1, sizeof(point));
    ne = 0;
}

void add_edge(int f, int t, int d1, int d2, int w) {
    e[ne].f = f, e[ne].t = t, e[ne].c = d1, e[ne].w = w;
    nxt[ne] = point[f], point[f] = ne++;
    e[ne].f = t, e[ne].t = f, e[ne].c = d2, e[ne].w = -w;
    nxt[ne] = point[t], point[t] = ne++;
}

bool spfa(int s, int t, int n) {
    int i, tmp, l, r;
    memset(pre, -1, sizeof(pre));
    for (i = 0; i < n; ++i) dis[i] = inf;
    dis[s] = 0;
    q[0] = s;
    l = 0, r = 1;
    u[s] = true;
    while (l != r) {
        tmp = q[l];
        l = (l + 1) % (n + 1);
        u[tmp] = false;
        for (i = point[tmp]; i != -1; i = nxt[i]) {
            if (e[i].c && dis[e[i].t] > dis[tmp] + e[i].w) {
                dis[e[i].t] = dis[tmp] + e[i].w;
                pre[e[i].t] = i;
                if (!u[e[i].t]) {
                    u[e[i].t] = true;
                    q[r] = e[i].t;
                    r = (r + 1) % (n + 1);
                }
            }
        }
    }
    if (pre[t] == -1) return false;
    return true;
}

void MCMF(int s, int t, int n, int &flow, int &cost) {
    int tmp, min;
    flow = cost = 0;
    while (spfa(s, t, n)) {
        min = inf, tmp = t;
        while (tmp != s) {
            min = mmin(min, e[pre[tmp]].c);
            tmp = e[pre[tmp]].f;
        }
        tmp = t;
        while (tmp != s) {
            e[pre[tmp]].c -= min;
            e[pre[tmp] ^ 1].c += min;
            tmp = e[pre[tmp]].f;
        }
        flow += min;
        cost += min * dis[t];
    }
}

int main() {
    int n, m, i, t;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; ++i) {
        scanf("%d %d %d", &c[i].s, &c[i].t, &c[i].c);
        c[i].t += c[i].s;
        num[i + i] = c[i].s;
        num[i + i + 1] = c[i].t;
    }
    sort(num, num + n + n);
    t = 2;
    mp.clear();
    mp[num[0]] = 1;
    for (i = 1; i < n + n; ++i) {
        if (num[i] != num[i - 1]) mp[num[i]] = t++;
    }
    init();
    for (i = 1; i <= t; ++i) add_edge(i, i + 1, inf, 0, 0);
    add_edge(0, 1, m, 0, 0);
    for (i = 0; i < n; ++i) add_edge(mp[c[i].s], mp[c[i].t], 1, 0, -c[i].c);
    MCMF(0, t, t + 1, i, i);
    for (i = 0; i < n; ++i) {
        if (i) printf(" ");
        if (e[t * 2 + i * 2 + 2].c == 1) {
            printf("0");
        } else {
            printf("1");
        }
    }
    printf("\n");
    return 0;
}