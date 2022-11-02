// oct code title CF/CF706E.cpp

#ifndef OCT_CODE_INSERT_PREx2dDOCUMENT  // oct code insert pre-document
#define OCT_CODE_INSERT_PREx2dDOCUMENT

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif

#ifndef STL_BITS__2F_STDCx2Bx2Bx2FH
#define STL_BITS__2F_STDCx2Bx2Bx2FH
#include <bits/stdc++.h>
#endif

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
#define reg register

using uint8 = unsigned char;
using uint16 = unsigned short int;
using uint32 = unsigned int;
using uint64 = unsigned long long;
using int8 = signed char;
using int16 = short int;
using int32 = int;
using int64 = long long;
using pi32 = std::pair<int32, int32>;
using pi64 = std::pair<int64, int64>;

namespace oct {

/* Array tn4 is the 4-direction changes in coordinate system.
 * The directions in order is {right, up, left, down}.
 */
const int tn4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int tn8[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                       {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
const double exp = 1e-8;

void sync(int pre = 8);
template <typename _Tp>
_Tp &mad(_Tp &x, _Tp y);
template <typename _Tp>
_Tp &mid(_Tp &x, _Tp y);
template <typename _Tp>
bool in(_Tp x, _Tp l, _Tp r);
template <typename _Tp>
bool in(_Tp x, _Tp y, _Tp l, _Tp r);
template <typename _Tp>
_Tp sqr(_Tp x);
template <typename _Tp>
_Tp power(_Tp x, int64 m);
template <typename _Tp>
void sort(_Tp &x, _Tp &y);
template <typename _Tp1, typename _Tp2>
std::pair<_Tp1, _Tp2> operator+(std::pair<_Tp1, _Tp2> x,
                                std::pair<_Tp1, _Tp2> y);
template <typename _Tp>
_Tp &operator+=(_Tp &x, _Tp y);
template <typename _Tp>
_Tp gcd(_Tp &x, _Tp &y);

inline void sync(int pre) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cout.flags(std::ios::fixed);
    std::cout.precision(pre);
    std::cout.setf(std::ios::showpoint);
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
inline bool in(_Tp x, _Tp y, _Tp l, _Tp r) {
    return l <= x && y <= r;
}
template <typename _Tp>
inline _Tp sqr(_Tp x) {
    return x * x;
}
template <typename _Tp>
inline _Tp power(_Tp x, int64 m) {
    return m == 1 ? x : (m & 1 ? power(x * x, m / 2) * x : power(x * x, m / 2));
}
template <typename _Tp>
inline void sort(_Tp &x, _Tp &y) {
    if (x > y) std::swap(x, y);
}
template <typename _Tp1, typename _Tp2>
inline std::pair<_Tp1, _Tp2> operator+(std::pair<_Tp1, _Tp2> x,
                                       std::pair<_Tp1, _Tp2> y) {
    return x.fir += y.fir, x.sec += y.sec, x;
}
template <typename _Tp>
inline _Tp &operator+=(_Tp &x, _Tp y) {
    return x = x + y;
}
template <typename _Tp>
inline _Tp gcd(_Tp &x, _Tp &y) {
    return std::__gcd(x, y);
}

}  // namespace oct

#endif  // oct code end pre-document

#define inc(i, l, r) for (int i = l; i <= r; i++)
#define dec(i, r, l) for (int i = r; i >= l; i--)

const int C = 26;
const int N = 3e5 + 10;

inline int64 read() {
    int64 x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

typedef struct AC {
    int fair[N], ch[N][C], st[N], tot = 0, sum[N], cnt = 0, rt[21], key[N];
    std::queue<int> que;
    AC() { inc(i, 0, 20) rt[i] = 0; }
    void newnode(int &x) {
        x = tot ? st[tot--] : ++cnt;
        fair[x] = sum[x] = key[x] = 0;
        inc(i, 0, 25) ch[x][i] = 0;
    }
    void insert(char s[]) {
        newnode(rt[0]);
        int len = strlen(s);
        int temp = rt[0];
        for (int i = 0; i < len; i++) {
            int t = s[i] - 'a';
            if (!ch[temp][t]) newnode(ch[temp][t]);
            temp = ch[temp][t];
        }
        key[temp] = 1;
    }
    void merge(int &x, int y) {
        if (x) {
            sum[x] = fair[x] = 0;
        }
        if (!y) return;
        if (!x) return void(x = y);
        st[++tot] = y;
        key[x] += key[y];
        for (int i = 0; i < C; i++) merge(ch[x][i], ch[y][i]);
    }
    void Fair(int x) {
        que.push(x);
        while (!que.empty()) {
            int t = que.front();
            que.pop();
            for (int i = 0; i < C; i++) {
                if (!ch[t][i]) continue;
                if (!fair[t]) {
                    fair[ch[t][i]] = x;
                    sum[ch[t][i]] = key[ch[t][i]];
                    que.push(ch[t][i]);
                    continue;
                }
                int temp = fair[t];
                while (temp && !ch[temp][i]) temp = fair[temp];
                if (!temp) {
                    fair[ch[t][i]] = x, sum[ch[t][i]] = key[ch[t][i]];
                } else {
                    fair[ch[t][i]] = ch[temp][i];
                    sum[ch[t][i]] = sum[ch[temp][i]] + key[ch[t][i]];
                }
                que.push(ch[t][i]);
            }
        }
    }
    void Insert(char s[]) {
        insert(s);
        for (int i = 1; i <= 20; i++) {
            if (rt[i]) {
                merge(rt[i], rt[i - 1]);
                rt[i - 1] = 0;
            } else {
                merge(rt[i], rt[i - 1]);
                rt[i - 1] = 0;
                Fair(rt[i]);
                break;
            }
        }
    }
    int querty(char s[]) {
        int len = strlen(s);
        int ans = 0;
        for (int i = 1; i <= 20; i++) {
            if (!rt[i]) continue;
            int temp = rt[i];
            for (int j = 0; j < len; j++) {
                int t = s[j] - 'a';
                if (!ch[temp][t]) {
                    int p = temp;
                    while (p && !ch[p][t]) p = fair[p];
                    temp = p ? ch[p][t] : rt[i];
                } else {
                    temp = ch[temp][t];
                }
                ans += sum[temp];
            }
        }
        return ans;
    }
} AC;
AC *add, *delet;

char str[N];

int main() {
    int m = read();
    add = new AC();
    delet = new AC();
    while (m--) {
        int op = read();
        scanf("%s", str);
        if (op == 1)
            add->Insert(str);
        else if (op == 2)
            delet->Insert(str);
        else
            printf("%d\n", add->querty(str) - delet->querty(str));
        fflush(stdout);
    }
    return 0;
}