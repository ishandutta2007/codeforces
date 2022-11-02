#include <bits/stdc++.h>

#define templ template <typename Type1, typename Type2>
templ inline Type1 &Mid(Type1 &x, Type2 y) { return x < y ? x : (x = y); }
templ inline Type1 &Mad(Type1 &x, Type2 y) { return x > y ? x : (x = y); }
#undef templ

#define templ template <typename Type>
templ inline Type Min(Type x, Type y) { return x < y ? x : y; }
templ inline Type Max(Type x, Type y) { return x > y ? x : y; }
#undef templ

#define templ template <typename Type, typename... Args>
templ inline Type Min(Type x, Type y, Args... args) { return Min(Min(x, y), args...); }
templ inline Type Max(Type x, Type y, Args... args) { return Max(Max(x, y), args...); }
#undef templ

using int64 = long long;

inline void Fitu(int64 &x, int o) { x = ((x + ((x & 1) ^ o)) + o) / 2; }
inline void Fitd(int64 &x, int o) { x = ((x - ((x & 1) ^ o)) + o) / 2; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        int64 cl1 = INT64_MIN, cl2 = INT64_MIN, cl3 = INT64_MIN, cl4 = INT64_MIN;
        int64 cr1 = INT64_MAX, cr2 = INT64_MAX, cr3 = INT64_MAX, cr4 = INT64_MAX;
        for (int i = 1; i <= n; ++i) {
            int64 x, y, z;
            std::cin >> x >> y >> z;
            Mad(cl1, x + y + z), Mad(cl2, x + y - z), Mad(cl3, x - y + z), Mad(cl4, -x + y + z);
            Mid(cr1, x + y + z), Mid(cr2, x + y - z), Mid(cr3, x - y + z), Mid(cr4, -x + y + z);
        }
        int64 l = Max(0ll, cl1 - cr1, cl2 - cr2, cl3 - cr3, cl4 - cr4) / 2, r = 3e18;
        while (l < r) {
            int64 Mid = l + r >> 1;
            if (([&]() -> bool {
                    for (int i = 0; i < 2; ++i) {
                        int64 bl1 = cl1 - Mid, bl2 = cl2 - Mid, bl3 = cl3 - Mid, bl4 = cl4 - Mid;
                        int64 br1 = cr1 + Mid, br2 = cr2 + Mid, br3 = cr3 + Mid, br4 = cr4 + Mid;
                        Fitu(bl1, i), Fitu(bl2, i), Fitu(bl3, i), Fitu(bl4, i);
                        Fitd(br1, i), Fitd(br2, i), Fitd(br3, i), Fitd(br4, i);
                        if (bl1 > br1 || bl2 > br2 || bl3 > br3 || bl4 > br4) continue;
                        if (bl2 + bl3 + bl4 - i > br1 || br2 + br3 + br4 - i < bl1) continue;
                        return true;
                    }
                    return false;
                })()) {
                r = Mid;
            } else {
                l = Mid + 1;
            }
        }
        for (int i = 0; i < 2; ++i) {
            int64 bl1 = cl1 - l, bl2 = cl2 - l, bl3 = cl3 - l, bl4 = cl4 - l;
            int64 br1 = cr1 + l, br2 = cr2 + l, br3 = cr3 + l, br4 = cr4 + l;
            Fitu(bl1, i), Fitu(bl2, i), Fitu(bl3, i), Fitu(bl4, i);
            Fitd(br1, i), Fitd(br2, i), Fitd(br3, i), Fitd(br4, i);
            if (bl1 > br1 || bl2 > br2 || bl3 > br3 || bl4 > br4) continue;
            if (bl2 + bl3 + bl4 - i > br1 || br2 + br3 + br4 - i < bl1) continue;
            int64 s = std::max(bl1 + i, bl2 + bl3 + bl4), t2 = bl2, t3 = bl3, t4 = bl4, t;
            s -= bl2 + bl3 + bl4;
            t = std::min(s, br2 - bl2), s -= t, t2 += t;
            t = std::min(s, br3 - bl3), s -= t, t3 += t;
            t = std::min(s, br4 - bl4), s -= t, t4 += t;
            t2 = t2 * 2 - i, t3 = t3 * 2 - i, t4 = t4 * 2 - i;
            int64 t1 = t2 + t3 + t4;
            std::cout << (t1 - t4) / 2 << ' ' << (t1 - t3) / 2 << ' ' << (t1 - t2) / 2 << '\n';
            break;
        }
    }
    return 0;
}