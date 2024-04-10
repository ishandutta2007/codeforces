#include <bits/stdc++.h>

constexpr int N = 5e5, M = 1 << 20;

int n;
int a[N];
std::vector<int> p[N];

struct Event {
    int y1, y2, v;
};

std::vector<Event> events[N + 2];

void addRectangle(int l1, int l2, int r1, int r2) {
    events[l1].push_back(Event{r1, r2, 1});
    events[l2].push_back(Event{r1, r2, -1});
}

struct Data {
    int mx, cnt;
    Data(int mx = 0, int cnt = 0) : mx(mx), cnt(cnt) {}
};

Data operator+(const Data &lhs, const Data &rhs) {
    if (lhs.mx > rhs.mx) {
        return lhs;
    } else if (lhs.mx < rhs.mx) {
        return rhs;
    } else {
        return Data(lhs.mx, lhs.cnt + rhs.cnt);
    }
}

Data t[M];
int tag[M];

void add(int p, int v) {
    t[p].mx += v;
    tag[p] += v;
}

void push(int p) {
    add(2 * p, tag[p]);
    add(2 * p + 1, tag[p]);
    tag[p] = 0;
}

void rangeAdd(int p, int l, int r, int x, int y, int v) {
    if (l >= y || r <= x) return;
    if (l >= x && r <= y) return add(p, v);
    int m = (l + r) / 2;
    push(p);
    rangeAdd(2 * p, l, m, x, y, v);
    rangeAdd(2 * p + 1, m, r, x, y, v);
    t[p] = t[2 * p] + t[2 * p + 1];
}

void build(int p, int l, int r) {
    t[p].cnt = r - l;
    if (r - l == 1) return;
    int m = (l + r) / 2;
    build(2 * p, l, m);
    build(2 * p + 1, m, r);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        --a[i];
        p[a[i]].push_back(i);
    }

    for (int x = 0; x < n; ++x) {
        int c = p[x].size();

        for (int i = 0; i <= c; ++i) {
            addRectangle(
                i == 0 ? 0 : p[x][i - 1] + 1, i == c ? n + 1 : p[x][i] + 1,
                i == 0 ? 0 : p[x][i - 1] + 1, i == c ? n + 1 : p[x][i] + 1);
        }

        for (int i = 0; i + 3 <= c; ++i) {
            addRectangle(i == 0 ? 0 : p[x][i - 1] + 1, p[x][i] + 1,
                         p[x][i + 2] + 1, i + 3 == c ? n + 1 : p[x][i + 3] + 1);
        }
    }

    int64_t ans = 0;

    build(1, 0, n + 1);

    for (int l = 0; l < n; ++l) {
        for (auto [y1, y2, v] : events[l]) rangeAdd(1, 0, n + 1, y1, y2, v);
        rangeAdd(1, 0, n + 1, l, l + 1, -1);

        if (t[1].mx == n) ans += t[1].cnt;
    }

    std::cout << ans << "\n";

    return 0;
}