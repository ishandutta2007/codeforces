#include <bits/stdc++.h>

template <class T>
void Mad(T &x, const T &y) {
    if (y > x) x = y;
}

template <class T>
void sort(std::vector<T> &a) {
    std::sort(a.begin(), a.end());
}

int read() {
    int x = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return x;
}

int main() {
    int a = read();
    int b = read();
    int n = a + b;
    std::vector<std::pair<int, int>> segments;
    for (int l = 1, r; l <= n; l = r + 1) {
        int t = n / l;
        r = n / t;
        if ((a + t) / (t + 1) > a / t || (b + t) / (t + 1) > b / t) continue;
        int L = std::max(l, (a + t) / (t + 1) + (b + t) / (t + 1));
        int R = std::min(r, a / t + b / t) + 1;
        if (L < R) segments.emplace_back(L, R);
    }
    sort(segments);
    int ans = 0;
    int r = 0;
    for (auto [L, R] : segments) ans += std::max(0, R - std::max(L, r)), Mad(r, R);
    printf("%d\n", ans);
    return 0;
}