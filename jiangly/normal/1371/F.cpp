#include <bits/stdc++.h>
int n, q;
struct Data {
    int max;
    std::vector<std::pair<int, int>> part;
    Data() : max(0) {}
    friend Data operator+(const Data &lhs, const Data &rhs) {
        Data res;
        res.max = std::max(lhs.max, rhs.max);
        res.part = lhs.part;
        for (auto [t, len] : rhs.part) {
            if (res.part.back().first == t) {
                res.part.back().second += len;
            } else {
                res.part.emplace_back(t, len);
            }
        }
        for (int i = 0; i < int(res.part.size()); ++i) {
            res.max = std::max(res.max, res.part[i].second);
            if (i + 1 < int(res.part.size()) && res.part[i].first == 0)
                res.max = std::max(res.max, res.part[i].second + res.part[i + 1].second);
        }
        for (int i = 1; i + 2 < int(res.part.size()); ++i) {
            if (res.part[i].first == 0) {
                res.part.erase(res.part.begin() + i, res.part.begin() + i + 2);
                --i;
            }
        }
        return res;
    }
};
Data unitl, unitr;
struct SegmentTree {
    int n;
    std::vector<int> tag;
    std::vector<Data> t, neg;
    SegmentTree(const std::string &s) : n(s.length()), tag(4 * n), t(4 * n), neg(4 * n) {
        build(1, 0, n, s);
    }
    void pull(int p) {
        t[p] = t[2 * p] + t[2 * p + 1];
        neg[p] = neg[2 * p] + neg[2 * p + 1];
    }
    void build(int p, int l, int r, const std::string &s) {
        if (r - l == 1) {
            t[p] = unitl;
            neg[p] = unitr;
            if (s[l] == '>')
                std::swap(t[p], neg[p]);
        } else {
            int m = (l + r) / 2;
            build(2 * p, l, m, s);
            build(2 * p + 1, m, r, s);
            pull(p);
        }
    }
    void flip(int p) {
        tag[p] ^= 1;
        std::swap(t[p], neg[p]);
    }
    void push(int p) {
        if (tag[p]) {
            flip(2 * p);
            flip(2 * p + 1);
            tag[p] = 0;
        }
    }
    Data query(int p, int l, int r, int x, int y) {
        if (l >= x && r <= y) {
            flip(p);
            return t[p];
        } else {
            int m = (l + r) / 2;
            push(p);
            Data res;
            if (y <= m) {
                res = query(2 * p, l, m, x, y);
            } else if (x >= m) {
                res = query(2 * p + 1, m, r, x, y);
            } else {
                res = query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y);
            }
            pull(p);
            return res;
        }
    }
    int query(int l, int r) {
        return query(1, 0, n, l, r).max;
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unitl.max = unitr.max = 1;
    unitl.part = {std::make_pair(1, 1)};
    unitr.part = {std::make_pair(0, 1)};
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    SegmentTree t(s);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        --l;
        std::cout << t.query(l, r) << "\n";
    }
    return 0;
}