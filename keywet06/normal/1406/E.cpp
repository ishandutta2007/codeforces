#include <bits/stdc++.h>

const int N_ = int(1e5);
const int N = N_ + 5;
const int B = 100;
const int S = 67;

int n, cnt, pr, ans;
int p[N], vis[N];

inline int qA(int x) {
    if (x > n) return 0;
    int ret;
    std::cout << "A " << x << std::endl, std::cin >> ret;
    return ret;
}

inline int qB(int x) {
    if (x > n) return 0;
    int ret;
    std::cout << "B " << x << std::endl, std::cin >> ret;
    return ret;
}

inline int qC(int x) { return std::cout << "C " << x << std::endl, 0; }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    for (int i = 2; i <= N_; ++i) {
        if (!vis[i]) p[++cnt] = i;
        for (int j = 1; j <= cnt && i * p[j] <= N_; ++j) {
            vis[i * p[j]] = p[j];
            if (i % p[j] == 0) break;
        }
    }
    std::cin >> n, pr = n, ans = 1;
    for (int i = S; i <= cnt;) {
        for (int j = 0; j < B && i + j <= cnt; ++j) pr -= qB(p[i + j]);
        if (qA(1) == pr && (i += B)) continue;
        for (int j = 0; j < B && i + j <= cnt; ++j) {
            if (qA(p[i + j]) && (ans = p[i + j])) break;
        }
        break;
    }
    for (int i = 1; i < S; ++i) {
        int x = (qB(p[i]), p[i]);
        while (qA(x)) ans *= p[i], x *= p[i];
    }
    qC(ans);
    return 0;
}