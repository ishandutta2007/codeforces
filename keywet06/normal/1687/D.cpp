#include <bits/stdc++.h>

#define Deb std::cerr
#define Delin Deb << "[Debug] at Line " << __LINE__
#define Debug Delin << " : "
#define Deline Delin << std::endl

#define templ template <typename Type1, typename Type2>
templ inline Type1 &Mid(Type1 &x, Type2 y) { return x < y ? x : x = y; }
templ inline Type1 &Mad(Type1 &x, Type2 y) { return x > y ? x : x = y; }
#undef templ

using int64 = long long;

const int N = 1000005;
const int M = 2000005;

int n;
int a[N], Pos[M];

inline int GetPos(int64 x) { return x > a[n] ? n + 1 : Pos[x]; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        for (int j = a[i - 1] + 1; j <= a[i]; ++j) Pos[j] = i;
    }
    for (int64 p = 1;; ++p) {
        if (a[1] > p * p + p) continue;
        bool Flag = false;
        int64 l = 0, r = INT64_MAX;
        for (int64 i = 1, c = p, j; i <= n && !(Flag = l > r); i = j + 1) {
            while (a[i] + l > c * c + c) ++c;
            Mad(l, c * c - a[i]), Mid(r, c * c + c - a[i]);
            if (Flag = l > r) break;
            j = GetPos(c * c + c - l + 1) - 1;
            Mad(l, c * c - a[j]), Mid(r, c * c + c - a[j]);
        }
        if (Flag) continue;
        std::cout << l << std::endl;
        return 0;
    }
    return 0;
}