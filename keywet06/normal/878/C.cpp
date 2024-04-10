#include <bits/stdc++.h>

struct Group {
    int sz;
    std::vector<int> lo, hi;

    Group(int* a, int* b) : sz(1), lo(a, b), hi(a, b) {}

    bool operator<(const Group& o) const {
        for (int i = 0; i < hi.size(); ++i) {
            if (hi[i] >= o.lo[i]) return false;
        }
        return true;
    }

    void merge(const Group& o) {
        sz += o.sz;
        for (int i = 0; i < lo.size(); ++i) lo[i] = std::min(lo[i], o.lo[i]), hi[i] = std::max(hi[i], o.hi[i]);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, k, s[10];
    std::cin >> n >> k;
    std::set<Group> grps;
    while (n--) {
        for (int i = 0; i < k; ++i) std::cin >> s[i];
        Group grp(s, s + k);
        auto i0 = grps.lower_bound(grp), i1 = grps.upper_bound(grp);
        while (i0 != i1) {
            grp.merge(*i0);
            i0 = grps.erase(i0);
        }
        grps.insert(i0, grp);
        std::cout << grps.rbegin()->sz << '\n';
    }
    return 0;
}