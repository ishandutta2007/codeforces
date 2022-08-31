#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2E5;

bool check(i64 a, i64 b, int k) {
    k += 2;
    b += a;
    int even = k - 1;
    if (even % 2) {
        even--;
    }
    a += 1LL * even * (even / 2 + 1) / 2;
    b -= even / 2 + 1;
    if (b > 0 || b < -k) {
        return false;
    }
    b = -b;
    i64 l = 1LL * b * (b - 1) / 2;
    i64 r = 1LL * b * (k - b + k - 1) / 2;
    return l <= a && a <= r;
}

void construct(i64 a, i64 b, int k, std::vector<int> &ans) {
    k += 2;
    b += a;
    int even = k - 1;
    if (even % 2) {
        even--;
    }
    a += 1LL * even * (even / 2 + 1) / 2;
    b -= even / 2 + 1;
    b = -b;
    std::vector<bool> f(k);
    for (int i = k - 1; i >= 0; i--) {
        if (b == i + 1) {
            f[i] = true;
            a -= i;
            b--;
            continue;
        }
        if (b == 0) {
            continue;
        }
        i64 l = 1LL * b * (b - 1) / 2;
        i64 r = 1LL * b * (i - b + i - 1) / 2;
        if (l <= a && a <= r) {
            continue;
        }
        f[i] = true;
        a -= i;
        b--;
    }
    for (int i = 0; i < k; i++) {
        if (f[i] ^ (i % 2 == 0)) {
            ans.push_back(k - 1 - i);
        }
    }
}

void solve() {
    int n, m;
    std::cin >> n;
    
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::cin >> m;
    std::vector<i64> b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    
    std::vector<i64> A(n), B(m);
    for (int i = 2; i < n; i++) {
        A[i] = a[i - 2] + 2 * a[i - 1] + a[i];
    }
    for (int i = 2; i < m; i++) {
        B[i] = b[i - 2] + 2 * b[i - 1] + b[i];
    }
    
    std::bitset<N> cur, good;
    for (int i = 0; i <= n - m; i++) {
        good[i] = 1;
    }
    std::vector<int> pa(n - 2), pb(m - 2);
    std::iota(pa.begin(), pa.end(), 2);
    std::iota(pb.begin(), pb.end(), 2);
    std::sort(pa.begin(), pa.end(), [&](int i, int j) {
        return A[i] < A[j];
    });
    std::sort(pb.begin(), pb.end(), [&](int i, int j) {
        return B[i] < B[j];
    });
    int i1 = 0, i2 = 0;
    for (auto j : pb) {
        while (i2 < n - 2 && A[pa[i2]] <= B[j]) {
            cur.flip(pa[i2]);
            i2++;
        }
        while (i1 < n - 2 && A[pa[i1]] <= B[j] - 2) {
            cur.flip(pa[i1]);
            i1++;
        }
        good &= cur >> j;
    }
    for (int k = 0; k <= n - m; k++) {
        bool nice = check(b[0] - a[k], b[1] - a[k + 1], k) && good[k];
        if (nice) {
            std::vector<int> ans;
            for (int i = 2; i < m; i++) {
                if (A[k + i] == B[i] - 1) {
                    ans.push_back(k + i);
                }
            }
            construct(b[0] - a[k], b[1] - a[k + 1], k, ans);
            std::cout << ans.size() << "\n";
            for (int i = 0; i < int(ans.size()); i++) {
                std::cout << ans[i] + 1 << " \n"[i == int(ans.size()) - 1];
            }
            return;
        }
    }
    std::cout << "-1\n";
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