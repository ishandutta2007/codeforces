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

/* Array tn4 is the 4-direction changes in coordinate system.
 * The directions in order is {right, up, left, down}.
 */
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

const int N = 100005;

bool check(char *num, int len);

char ntr[N], num[N];
int len, flag;
int ans[N];

bool check(char *t, int len) {
    for (int i = 0; i <= len >> 1; ++i) {
        int l = i, r = len - i - 1;
        if (t[l] == t[r]) continue;
        if (t[l] - 1 == t[r] && r - l != 1) {
            --t[l], t[l + 1] += 10;
        } else if (t[l] - 1 == t[r] + 10) {
            --t[l], t[l + 1] += 10;
            if (r - l == 1) continue;
            t[r] += 10, --t[r - 1];
        } else if (t[l] == t[r] + 10 && r - l != 1) {
            t[r] += 10, --t[r - 1];
        } else {
            return 0;
        }
    }
    if (len & 1) {
        if (t[len >> 1] & 1 || !oct::in(int(t[len >> 1]), 0, 18)) return 0;
        ans[len >> 1] = t[len >> 1] >> 1;
    }
    for (int i = 0; i < len >> 1; ++i) {
        if (!oct::in(int(t[i]), 0, 18)) return 0;
        ans[i] = (t[i] + 1) >> 1, ans[len - i - 1] = t[i] >> 1;
    }
    return ans[0] > 0;
}


int main() {
    oct::sync();
    std::cin >> ntr + 1;
    len = strlen(ntr + 1);
    for (int i = 1; i <= len; ++i) num[i] = ntr[i] -= '0';
    if (check(num + 1, len)) {
        for (int i = 0; i < len; ++i) std::cout << ans[i];
        std::cout << std::endl;
    } else {
        memcpy(num, ntr, sizeof(ntr));
        if (num[1] == 1) {
            num[2] += 10;
            if (flag = check(num + 2, len - 1)) {
                for (int i = 0; i < len - 1; ++i) std::cout << ans[i];
                std::cout << std::endl;
            }
        }
        if (!flag) std::cout << 0 << std::endl;
    }
    return 0;
}