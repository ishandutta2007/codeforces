#include <bits/stdc++.h>

typedef long long int64;

int x;

struct node {
    std::vector<int> last, first;
    int64 cnt;
    node() : cnt(0) {}
};

std::vector<int> a;
std::vector<node> t;

void unite(node& ans, node& left, node& right) {
    ans.cnt = left.cnt + right.cnt;
    int val = 0;
    ans.last = right.last;
    for (int pos : ans.last) val |= a[pos];
    for (int j = 0; j < (left.last).size(); ++j) {
        int pos = left.last[j];
        if ((val | a[pos]) != val || j == (left.last).size() - 1) ans.last.push_back(pos), val |= a[pos];
    }
    ans.first = left.first;
    val = 0;
    for (int pos : ans.first) val |= a[pos];
    for (int j = 0; j < (right.first).size(); ++j) {
        int pos = right.first[j];
        if ((val | a[pos]) != val || j == (right.first).size() - 1) ans.first.push_back(pos), val |= a[pos];
    }
    int init = 0;
    for (int i = 0; i < (left.last).size(); ++i) {
        init |= a[left.last[i]];
        val = init;
        int j = 0;
        val |= a[right.first[0]];
        while (val < x) {
            ++j;
            if (j < (right.first).size()) {
                val |= a[right.first[j]];
            } else {
                break;
            }
        }
        if (j == (right.first).size()) continue;
        int64 lf;
        if (i == (left.last).size() - 1) {
            lf = 1;
        } else {
            lf = left.last[i] - left.last[i + 1];
        }
        ans.cnt += lf * (right.first.back() - right.first[j] + 1);
    }
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v].last = {tl};
        t[v].first = {tl};
        if (a[tl] >= x) {
            t[v].cnt = 1;
        } else {
            t[v].cnt = 0;
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    unite(t[v], t[v * 2], t[v * 2 + 1]);
}

void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        t[v].last = {tl};
        t[v].first = {tl};
        if (a[tl] >= x) {
            t[v].cnt = 1;
        } else {
            t[v].cnt = 0;
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        update(v * 2, tl, tm, pos);
    } else {
        update(v * 2 + 1, tm + 1, tr, pos);
    }
    unite(t[v], t[v * 2], t[v * 2 + 1]);
}

void split(int v, int tl, int tr, int l, int r, std::vector<node>& ans) {
    if (tl == l && tr == r) {
        ans.push_back(t[v]);
        return;
    }
    int tm = (tl + tr) >> 1;
    if (l <= tm) split(v * 2, tl, tm, l, std::min(r, tm), ans);
    if (r > tm) split(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r, ans);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, q;
    std::cin >> n >> q >> x;
    a.resize(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    t.resize(4 * n);
    build(1, 0, n - 1);
    while (q--) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int pos, val;
            std::cin >> pos >> val;
            --pos;
            a[pos] = val;
            update(1, 0, n - 1, pos);
        } else {
            int l, r;
            std::cin >> l >> r;
            --l, --r;
            std::vector<node> vct;
            split(1, 0, n - 1, l, r, vct);
            node ans = vct[0];
            for (int i = 1; i < (vct).size(); ++i) {
                node tmp;
                unite(tmp, ans, vct[i]);
                ans = tmp;
            }
            std::cout << ans.cnt << "\n";
        }
    }
    return 0;
}