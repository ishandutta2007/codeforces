#include <bits/stdc++.h>

int n, q;

std::string s, t;

std::vector<int> l, r, pos;

template <int P>
struct Hash {
    const int Base;
    std::vector<int> pow, h;
    Hash(std::string s)
        : Base(std::chrono::steady_clock::now().time_since_epoch().count() %
                   100000 +
               233) {
        pow.resize(s.length() + 1);
        h.resize(s.length() + 1);
        pow[0] = 1;
        for (int i = 1; i <= int(s.length()); ++i) {
            pow[i] = 1ll * pow[i - 1] * Base % P;
        }
        for (int i = 0; i < int(s.length()); ++i) {
            h[i + 1] = (1ll * h[i] * Base + s[i] + 99) % P;
        }
    }
    int hash(int l, int r) {
        return (h[r] + 1ll * h[l] * (P - pow[r - l])) % P;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> s >> q;
    r.resize(n + 1);
    for (int i = n - 1; i >= 0; --i) r[i] = s[i] == '1' ? r[i + 1] + 1 : 0;
    l.resize(n + 1);
    for (int i = 0; i < n; ++i) l[i + 1] = s[i] == '1' ? l[i] + 1 : 0;
    pos.resize(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            pos[i] = t.length();
            t += '0';
        } else if (!t.empty() && t.back() == '1') {
            t.pop_back();
        } else {
            t += '1';
        }
    }
    Hash<998'244'353> h1(t);
    Hash<1'000'000'007> h2(t);
    for (int i = 0; i < q; ++i) {
        int l1, l2, len;
        std::cin >> l1 >> l2 >> len, --l1, --l2;
        int r1 = l1 + len, r2 = l2 + len;
        if (r[l1] >= len || r[l2] >= len) {
            if (r[l1] >= len && r[l2] >= len) {
                std::cout << "Yes\n";
            } else {
                std::cout << "No\n";
            }
        } else if (r[l1] % 2 == r[l2] % 2 && l[r1] % 2 == l[r2] % 2) {
            l1 = pos[l1 + r[l1]];
            l2 = pos[l2 + r[l2]];
            r1 = pos[r1 - 1 - l[r1]] + 1;
            r2 = pos[r2 - 1 - l[r2]] + 1;
            if (r1 - l1 == r2 - l2 && h1.hash(l1, r1) == h1.hash(l2, r2) &&
                h2.hash(l1, r1) == h2.hash(l2, r2)) {
                std::cout << "Yes\n";
            } else {
                std::cout << "No\n";
            }
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}