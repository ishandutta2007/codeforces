#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define debug std::cerr << "Debug(" << __LINE__ << "): "
#define pub push_back
#define pob pop_back
#define pup push
#define mkp make_pair
#define fir first
#define sec second
#define ite iterator
#define lob lower_bound
#define upb upper_bound

using uint8 = unsigned char;
using uint16 = unsigned short int;
using uint32 = unsigned int;
using uint64 = unsigned long long;
using int8 = signed char;
using int16 = short int;
using int32 = int;
using int64 = long long;
using pi32 = std::pair<int32, int32>;
using vi32 = std::vector<int32>;
using qi32 = std::queue<int32>;
using spi32 = std::set<pi32>;

namespace oct {

const int tn4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int tn8[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                       {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

void sync();
template <typename _Tp>
_Tp &mad(_Tp &x, _Tp y);
template <typename _Tp>
_Tp &mid(_Tp &x, _Tp y);
template <typename _Tp>
bool in(_Tp x, _Tp l, _Tp r);
template <typename _Tp>
_Tp sqr(_Tp x);

inline void sync() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
}
template <typename _Tp>
inline _Tp &mad(_Tp &x, _Tp y) {
    return x = std::max(x, y);
}
template <typename _Tp>
inline _Tp &mid(_Tp &x, _Tp y) {
    return x = std::min(x, y);
}
template <typename _Tp>
inline bool in(_Tp x, _Tp l, _Tp r) {
    return l <= x && x <= r;
}
template <typename _Tp>
inline _Tp sqr(_Tp x) {
    return x * x;
}

}  // namespace oct

// the pre-document end

const int N = 400000;

int judge(int cnt);
int bsearch(int l, int r);

int n, a, b, c;
int num[N];

inline int judge(int cnt) {
    int aa = 0, bb = 0, cc = 0, s = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (num[i] <= c) {
            if (cc < cnt) {
                cc++;
            } else if (bb < cnt) {
                bb++;
            } else if (aa < cnt) {
                aa++;
            } else {
                return 0;
            }
        } else if (num[i] <= b) {
            if (bb < cnt) {
                bb++;
            } else if (aa < cnt) {
                aa++;
            } else {
                return 0;
            }
        } else if (num[i] <= a) {
            if (aa < cnt) {
                aa++;
            } else if (num[i] <= b + c && bb < cnt && cc < cnt) {
                bb++, cc++, s++;
            } else {
                return 0;
            }
        } else if (num[i] <= b + c) {
            if (bb < cnt && cc < cnt) {
                bb++, cc++, s++;
            } else if (aa < cnt && cc < cnt) {
                aa++, cc++, s++;
            } else if (aa < cnt && bb < cnt) {
                aa++, bb++, s++;
            } else {
                return 0;
            }
        } else if (num[i] <= a + c) {
            if (aa < cnt && cc < cnt) {
                aa++, cc++, s++;
            } else if (aa < cnt && bb < cnt) {
                aa++, bb++, s++;
            } else {
                return 0;
            }
        } else if (num[i] <= a + b) {
            if (aa < cnt && bb < cnt) {
                aa++, bb++, s++;
            } else {
                return 0;
            }
        } else if (num[i] <= a + b + c) {
            if (aa < cnt && bb < cnt && cc < cnt) {
                aa++, bb++, cc++, s++;
            } else {
                return 0;
            }
        }
    }
    if (s > cnt) return 0;
    return 1;
}
inline int bsearch(int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (!judge(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    oct::sync();
    while (std::cin >> n) {
        std::cin >> a >> b >> c;
        if (a < b) std::swap(a, b);
        if (a < c) std::swap(a, c);
        if (b < c) std::swap(b, c);
        for (int i = 0; i < n; ++i) std::cin >> num[i];
        std::sort(num, num + n);
        if (num[n - 1] > a + b + c) {
            std::cout << -1 << '\n';
            continue;
        }
        if (num[n - 1] <= c) {
            if (n % 3 == 0) {
                std::cout << n / 3 << '\n';
            } else {
                std::cout << n / 3 + 1 << '\n';
            }
            continue;
        }
        std::cout << bsearch(n / 3, n) << '\n';
    }
    return 0;
}