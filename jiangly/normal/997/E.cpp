#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1e9;

struct MinCnt {
    int val;
    i64 cnt;
    MinCnt(int x = inf) : val(x), cnt(1) {}
    MinCnt(int x, i64 c) : val(x), cnt(c) {}
};

MinCnt operator+(const MinCnt &a, const MinCnt &b) {
    if (a.val < b.val) {
        return a;
    } else if (a.val > b.val) {
        return b;
    } else {
        return MinCnt(a.val, a.cnt + b.cnt);
    }
}

MinCnt operator*(const MinCnt &a, const MinCnt &b) {
    return MinCnt(a.val + b.val, a.cnt * b.cnt);
}

struct Tag {
    MinCnt vcur = 0;
    MinCnt vhis;
};

void apply(Tag &a, const Tag &b) {
    a.vhis = a.vhis + b.vhis * a.vcur;
    a.vcur = a.vcur * b.vcur;
}

struct Info {
    MinCnt cur;
    MinCnt his;
};

void apply(Info &a, const Tag &b) {
    a.his = a.his + b.vhis * a.cur;
    a.cur = a.cur * b.vcur;
}

Info operator+(const Info &a, const Info &b) {
    return {a.cur + b.cur, a.his + b.his};
}

template<class Info, class Tag,
    class Merge = std::plus<Info>>
struct LazySegmentTree {
    const int n;
    const Merge merge;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree(int n) : n(n), merge(Merge()), info(4 << std::__lg(n)), tag(4 << std::__lg(n)) {}
    LazySegmentTree(std::vector<Info> init) : LazySegmentTree(init.size()) {
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = merge(info[2 * p], info[2 * p + 1]);
    }
    void apply(int p, const Tag &v) {
        ::apply(info[p], v);
        ::apply(tag[p], v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return merge(rangeQuery(2 * p, l, m, x, y), rangeQuery(2 * p + 1, m, r, x, y));
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    
    LazySegmentTree<Info, Tag> seg(n);
    
    int q;
    std::cin >> q;
    std::vector<std::tuple<int, int, int>> queries;
    queries.reserve(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        l--;
        queries.emplace_back(r, l, i);
    }
    
    std::vector<i64> ans(q);
    
    std::sort(queries.begin(), queries.end());
    
    std::vector<int> smx{-1}, smn{-1};
    for (int i = 0, j = 0; i < n; i++) {
        seg.modify(i, {0});
        seg.rangeApply(0, i, {-1});
        while (smx.size() > 1 && a[i] > a[smx.back()]) {
            int v = smx.back();
            smx.pop_back();
            seg.rangeApply(smx.back() + 1, v + 1, {-a[v]});
        }
        while (smn.size() > 1 && a[i] < a[smn.back()]) {
            int v = smn.back();
            smn.pop_back();
            seg.rangeApply(smn.back() + 1, v + 1, {a[v]});
        }
        seg.rangeApply(smx.back() + 1, i + 1, {a[i]});
        seg.rangeApply(smn.back() + 1, i + 1, {-a[i]});
        smx.push_back(i);
        smn.push_back(i);
        seg.rangeApply(0, n, {0, 0});
        
        while (j < q && std::get<0>(queries[j]) == i + 1) {
            auto [r, l, k] = queries[j++];
            ans[k] = seg.rangeQuery(l, r).his.cnt;
        }
    }
    
    for (int i = 0; i < q; i++) {
        std::cout << ans[i] << "\n";
    }
    
    return 0;
}