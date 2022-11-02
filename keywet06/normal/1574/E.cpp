#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long int64;

template <typename T>
void mad(T &x, T y) {
    if (y > x) x = y;
}
template <typename T>
void min(T &x, T y) {
    if (y < x) x = y;
}

template <typename T>
void inline read(T &x) {
    int f = 1;
    x = 0;
    char s = getchar();
    while (s < '0' || s > '9') {
        if (s == '-') f = -1;
        s = getchar();
    }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e6 + 5, P = 998244353;

int n, m, q, pw[N];

map<int, int> M[N];

struct tree {
    int st[N][2], ban, cnt;
    int inline get() {
        if (ban) return 0;
        return pw[cnt];
    }
    void inline ins(int x, int y, int o) {
        int t = (y + o) & 1;
        st[x][t]++;
        if (st[x][t] == 1 && st[x][!t]) ban++;
        if (st[x][t] == 1 && !st[x][!t]) cnt--;
    }
    void inline del(int x, int y, int o) {
        int t = (y + o) & 1;
        st[x][t]--;
        if (!st[x][t] && st[x][!t]) ban--;
        if (!st[x][t] && !st[x][!t]) cnt++;
    }
};

int cnt[2];

tree t0, t1;

void inline Del(int x, int y) {
    int w = M[x][y];
    t0.del(x, y, w);
    t1.del(y, x, w);
    int gx = (x + y + w) & 1;
    cnt[gx]--;
    M[x].erase(y);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    pw[0] = 1;
    for (int i = 1; i <= 1000000; i++) pw[i] = pw[i - 1] * 2 % P;
    std::cin >> n >> m >> q;
    t0.cnt = n, t1.cnt = m;
    while (q--) {
        int x, y, t;
        std::cin >> x >> y >> t;
        if (t == -1) {
            if (M[x].count(y)) Del(x, y);
        } else {
            if (M[x].count(y)) Del(x, y);
            int gx = (x + y + t) & 1;
            cnt[gx]++;
            t0.ins(x, y, t);
            t1.ins(y, x, t);
            M[x][y] = t;
        }
        int ans = (t0.get() + t1.get()) % P;
        if (!cnt[0]) ans = (ans - 1 + P) % P;
        if (!cnt[1]) ans = (ans - 1 + P) % P;
        printf("%d\n", ans);
    }
    return 0;
}