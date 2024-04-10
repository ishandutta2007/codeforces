#include <bits/stdc++.h>

const int LIMIT = 2e5;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];
    long long cnt = 0;
    std::string ans;
    if (n == 1) {
        if (a[0] == b[0]) {
            std::cout << "SMALL\n";
            std::cout << 0 << "\n";
        } else {
            std::cout << "IMPOSSIBLE\n";
        }
    } else if (n == 2) {
        bool rev = false;
        if (a[0] > a[1]) {
            std::swap(a[0], a[1]);
            rev = true;
        }
        while (true) {
            if (b[0] > b[1]) {
                std::swap(b[0], b[1]);
                if (cnt <= LIMIT) ans += 'R';
            }
            if (b[0] == a[0] && b[1] >= a[1] && (b[1] - a[1]) % b[0] == 0) {
                cnt += (b[1] - a[1]) / b[0];
                if (cnt <= LIMIT) ans += std::string((b[1] - a[1]) / b[0], 'P');
                break;
            }
            if (b[1] % b[0] == 0) {
                std::cout << "IMPOSSIBLE\n";
                return 0;
            }
            cnt += b[1] / b[0];
            if (cnt <= LIMIT) ans += std::string(b[1] / b[0], 'P');
            b[1] %= b[0];
        }
        if (rev && cnt <= LIMIT) ans += 'R';
        if (cnt > LIMIT) {
            std::cout << "BIG\n";
            std::cout << cnt << "\n";
        } else {
            if (ans.length() >= 2 && ans[ans.length() - 2] == 'R' &&
                ans.back() == 'R') {
                ans.pop_back();
                ans.pop_back();
            }
            std::reverse(ans.begin(), ans.end());
            std::cout << "SMALL\n";
            std::cout << ans.length() << "\n";
            std::cout << ans << "\n";
        }
    } else {
        while (true) {
            if (a == b) break;
            std::reverse(b.begin(), b.end());
            if (a == b) {
                if (cnt <= LIMIT) ans += 'R';
                break;
            }
            std::reverse(b.begin(), b.end());
            if (!std::is_sorted(b.begin(), b.end())) {
                std::reverse(b.begin(), b.end());
                if (cnt <= LIMIT) ans += 'R';
            }
            for (int i = n - 2; i >= 0; --i) {
                if (b[i + 1] <= b[i]) {
                    std::cout << "IMPOSSIBLE\n";
                    return 0;
                }
                b[i + 1] -= b[i];
            }
            ++cnt;
            if (cnt <= LIMIT) ans += 'P';
        }
        if (cnt <= LIMIT) {
            std::reverse(ans.begin(), ans.end());
            std::cout << "SMALL\n";
            std::cout << ans.length() << "\n";
            std::cout << ans << "\n";
        } else {
            std::cout << "BIG\n";
            std::cout << cnt << "\n";
        }
    }
    return 0;
}