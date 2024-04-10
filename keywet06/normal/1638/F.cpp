#include <bits/stdc++.h>

using int64 = long long;

template <typename Type1, typename Type2>
inline Type1 &Mid(Type1 &x, Type2 y) {
    return x < y ? x : (x = y);
}

template <typename Type1, typename Type2>
inline Type1 &Mad(Type1 &x, Type2 y) {
    return x > y ? x : (x = y);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int64> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::vector<int64> MaxL(n), MaxR(n);
    int64 Ans = 0;
    for (int i = 0; i < n; ++i) {
        std::vector<int64> b(n);
        int l = i, r = i;
        int64 x = b[i] = a[i];
        for (int j = i - 1; j >= 0; --j) b[j] = std::min(b[j + 1], a[j]);
        for (int j = i + 1; j < n; ++j) b[j] = std::min(b[j - 1], a[j]);
        while (l > 0 && b[l - 1] == x) --l;
        while (r + 1 < n && b[r + 1] == x) ++r;
        int64 s = (r - l + 1) * x;
        for (int64 j = l; j <= i; ++j, s -= x) Mad(MaxR[j], s);
        s = (i - l + 1) * x;
        for (int64 j = i; j <= r; ++j, s += x) Mad(MaxL[j], s);
        s = (r - l + 1) * x;
        int c = 0, Tl = l, Tr = r;
        while (l > 0 || r + 1 < n) {
            int64 T = std::max(l > 0 ? b[l - 1] : 0, r + 1 < n ? b[r + 1] : 0);
            while (l > 0 && b[l - 1] == T) --l, ++c;
            while (r + 1 < n && b[r + 1] == T) ++r, ++c;
            Mad(Ans, T * c + s);
        }
        l = 0, r = Tr;
        int64 Max = 0, T = 0;
        while (l < i || r < n) {
            T = std::max(std::min(b[l], r + 1 < n ? x - b[r + 1] : x), T + 1);
            while (l < i && b[l] < T) ++l;
            while (r + 1 < n && b[r + 1] >= x - T) ++r;
            if (b[l] < T || b[r] < x - T) break;
            Mad(Max, (Tr - l + 1) * T), Mad(Ans, Max + (r - Tl + 1) * (x - T));
        }
    }
    for (int i = 1; i < n; ++i) Mad(MaxL[i], MaxL[i - 1]);
    for (int i = n - 2; i >= 0; --i) Mad(MaxR[i], MaxR[i + 1]);
    Mad(Ans, MaxL.back()), Mad(Ans, MaxR.front());
    for (int i = 1; i < n; ++i) Mad(Ans, MaxL[i - 1] + MaxR[i]);
    std::cout << Ans << std::endl;
    return 0;
}