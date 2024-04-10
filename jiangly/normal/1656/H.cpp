#include <bits/stdc++.h>

using i128 = __int128;

std::istream &operator>>(std::istream &is, i128 &n) {
    n = 0;
    std::string s;
    is >> s;
    
    for (auto c : s) {
        n = 10 * n + c - '0';
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n > 0) {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

i128 gcd(i128 a, i128 b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<i128> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    
    std::set<i128> p;
    std::function<void(i128)> add = [&](i128 n) {
        if (n == 1) {
            return;
        }
        for (auto x : p) {
            while (n % x == 0) {
                n /= x;
            }
        }
        if (n == 1) {
            return;
        }
        for (auto it = p.begin(); it != p.end(); it++) {
            i128 x = *it;
            i128 g = gcd(n, x);
            if (g != 1) {
                p.erase(it);
                add(g);
                add(n / g);
                add(x / g);
                return;
            }
        }
        p.insert(n);
    };
    
    for (int i = 0; i < n; i++) {
        add(a[i]);
    }
    for (int i = 0; i < m; i++) {
        add(b[i]);
    }
    
    int N = p.size();
    std::vector<i128> primes(p.begin(), p.end());
    std::vector<std::set<std::pair<int, int>>> sa(N), sb(N);
    std::vector<bool> ca(n, true), cb(m, true);
    std::vector<std::vector<std::pair<int, int>>> pa(n), pb(m);
    for (int i = 0; i < N; i++) {
        sa[i].emplace(0, -1);
        sb[i].emplace(0, -1);
    }
    
    auto factor = [&](auto n) {
        std::vector<std::pair<int, int>> p;
        for (int i = 0; i < N; i++) {
            int t = 0;
            while (n % primes[i] == 0) {
                n /= primes[i];
                t++;
            }
            if (t > 0) {
                p.emplace_back(i, t);
            }
        }
        return p;
    };
    
    for (int i = 0; i < n; i++) {
        pa[i] = factor(a[i]);
        for (auto [j, t] : pa[i]) {
            sa[j].emplace(t, i);
        }
    }
    for (int i = 0; i < m; i++) {
        pb[i] = factor(b[i]);
        for (auto [j, t] : pb[i]) {
            sb[j].emplace(t, i);
        }
    }
    
    std::function<void(int, int)> del;
    
    auto check = [&](int i) {
        if (sa[i].rbegin()->first > sb[i].rbegin()->first) {
            del(sa[i].rbegin()->second, 0);
        }
        if (sa[i].rbegin()->first < sb[i].rbegin()->first) {
            del(sb[i].rbegin()->second, 1);
        }
    };
    
    del = [&](int i, int w) {
        if (w == 0) {
            if (!ca[i]) {
                return;
            }
            ca[i] = false;
            for (auto [j, t] : pa[i]) {
                sa[j].erase({t, i});
                check(j);
            }
        } else {
            if (!cb[i]) {
                return;
            }
            cb[i] = false;
            for (auto [j, t] : pb[i]) {
                sb[j].erase({t, i});
                check(j);
            }
        }
    };
    
    for (int i = 0; i < N; i++) {
        check(i);
    }
    
    if (ca != std::vector(n, false) && cb != std::vector(m, false)) {
        std::cout << "YES\n";
        std::vector<int> ansa, ansb;
        for (int i = 0; i < n; i++) {
            if (ca[i]) {
                ansa.push_back(i);
            }
        }
        for (int i = 0; i < m; i++) {
            if (cb[i]) {
                ansb.push_back(i);
            }
        }
        std::cout << ansa.size() << " " << ansb.size() << "\n";
        for (auto i : ansa) {
            std::cout << a[i] << " \n"[i == ansa.back()];
        }
        for (auto i : ansb) {
            std::cout << b[i] << " \n"[i == ansb.back()];
        }
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}