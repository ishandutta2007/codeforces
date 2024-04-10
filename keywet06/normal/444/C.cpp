#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int N = 100005 << 1;

int n, m;
int64 sum[N], tag[N];

set<pair<pair<int, int>, int> > s;

inline int getID(int l, int r) { return l + r | l != r; }

void update(int l, int r) {
    if (l == r) return;
    int x = getID(l, r), m = l + r >> 1, lc = getID(l, m), rc = getID(m + 1, r);
    sum[x] = sum[lc] + sum[rc] + tag[x] * (r - l + 1);
}

void add(int l, int r, int a, int b, int64 val) {
    if (r < a || b < l) return;
    int x = getID(l, r);
    if (a <= l && r <= b) {
        tag[x] += val;
        sum[x] += val * (r - l + 1);
    } else {
        int m = l + r >> 1;
        add(l, m, a, b, val);
        add(m + 1, r, a, b, val);
        update(l, r);
    }
}

void pushdown(int l, int r) {
    int x = getID(l, r), m = l + r >> 1, lc = getID(l, m), rc = getID(m + 1, r);
    if (tag[x]) {
        tag[lc] += tag[x];
        sum[lc] += tag[x] * (m - l + 1);
        tag[rc] += tag[x];
        sum[rc] += tag[x] * (r - (m + 1) + 1);
        tag[x] = 0;
    }
}

int64 getsum(int l, int r, int a, int b) {
    if (r < a || b < l) {
        return 0;
    }
    int x = getID(l, r);
    if (a <= l && r <= b) {
        return sum[x];
    } else {
        pushdown(l, r);
        int m = l + r >> 1;
        return getsum(l, m, a, b) + getsum(m + 1, r, a, b);
    }
}

inline bool intersect(const int &l0, const int &r0, const int &l1,
                      const int &r1) {
    return max(l0, l1) <= min(r0, r1);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        s.insert(make_pair(make_pair(i, i), i + 1));
    }
    while (m--) {
        int op, l, r, x;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d%d", &l, &r, &x);
            --l, --r;
            set<pair<pair<int, int>, int> >::iterator it =
                s.lower_bound(make_pair(make_pair(l, -1), -1));
            vector<pair<pair<int, int>, int> > interval;
            while (it != s.end() &&
                   intersect((*it).first.second, (*it).first.first, l, r)) {
                interval.push_back(*it);
                ++it;
            }
            for (int i = 0; i < (int)interval.size(); ++i) {
                int rr = interval[i].first.first, ll = interval[i].first.second,
                    y = interval[i].second;
                s.erase(s.find(interval[i]));
                if (ll < l) {
                    s.insert(make_pair(make_pair(l - 1, ll), y));
                    ll = l;
                }
                if (r < rr) {
                    s.insert(make_pair(make_pair(rr, r + 1), y));
                    rr = r;
                }
                add(0, n - 1, ll, rr, abs(x - y));
            }
            s.insert(make_pair(make_pair(r, l), x));
        } else {
            scanf("%d%d", &l, &r);
            --l, --r;
            printf("%I64d\n", getsum(0, n - 1, l, r));
        }
    }
    return 0;
}