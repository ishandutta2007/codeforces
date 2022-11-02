#include <bits/stdc++.h>

#define pub push_back
#define fi first
#define se second
#define mkp std::make_pair

using namespace std;

using int64 = long long;
using pii = pair<int64, int64>;

const int64 N = 1001005;

struct seg {
    int64 som, en;
};

seg merge(seg a, seg b) {
    seg c;
    c.som = a.som + b.som;
    c.en = max(a.en + b.som, b.en);
    return c;
}

int64 t, n, q;
int64 start = 1;
seg st[N * 4];

seg quer(int64 a, int64 b, int64 le, int64 ri, int64 x) {
    if (le >= a && ri <= b) return st[x];
    if (le > b || ri < a) return {-1, -1};
    int64 mid = (le + ri) / 2;
    seg s1 = quer(a, b, le, mid, x << 1);
    seg s2 = quer(a, b, mid + 1, ri, x << 1 | 1);
    if (s1.en == -1) return s2;
    if (s2.en == -1) return s1;
    return merge(s1, s2);
}

void upd(int64 t, int64 d) {
    int64 x = start + t;
    st[x].som = d;
    st[x].en = t + d;
    x >>= 1;
    while (x) {
        st[x] = merge(st[x << 1], st[x << 1 | 1]);
        x >>= 1;
    }
}

seg init(int64 x) {
    if (x >= start) return st[x];
    return st[x] = merge(init(x << 1), init(x << 1 | 1));
}

vector<pii> que;

int main() {
    cin >> q;
    while (start < N) start <<= 1;
    for (int64 i = 0; i < start; ++i) st[i + start].en = i;
    init(1);
    for (int64 i = 0; i < q; ++i) {
        char c;
        int64 x, y;
        cin >> c;
        if (c == '+') {
            cin >> x >> y;
            upd(x, y);
            que.pub(mkp(x, y));
        } else if (c == '-') {
            cin >> x;
            x--;
            upd(que[x].fi, 0);
            que.pub(mkp(x, y));
        } else if (c == '?') {
            cin >> x;
            int64 lol = quer(0, x, 0, start - 1, 1).en;
            cout << lol - x << '\n';
            que.pub(mkp(x, y));
        }
    }
}