#include <bits/stdc++.h>

template <typename _Tp>
inline _Tp max(_Tp x, _Tp y) {
    return x > y ? x : y;
}

template <typename _Tp, typename... Args>
inline _Tp max(_Tp x, _Tp y, Args... args) {
    return max(max(x, y), args...);
}

template <typename _Tp>
inline _Tp &mad(_Tp &x, _Tp y) {
    return x > y ? x : (x = y);
}

template <typename _Tp, typename... Args>
inline _Tp &mad(_Tp &x, _Tp y, Args... args) {
    return mad(mad(x, y), args...);
}

struct seg {
    /**
     * 0: ----  1: <<<<  2: >>>> 3: >><<
     * 4: <<>>  5: <<><  6: ><>> 7: ><><
     */
    int type, ans, left, right;
    seg() : type(0), ans(0), left(0), right(0) {}
    seg(int t, int a, int l, int r)
        : type(t), ans(max(a, l, r)), left(l), right(r) {}
};

/**       1 <<<<   2 >>>>   3 >><<   4 <<>>   5 <<><   6 ><>>   7 ><><
 * 1 <<<< <<<<<<<< <<<<>>>> <<<<>><< <<<<<<>> <<<<<<>< <<<<><>> <<<<><><
 * 2 >>>> >>>><<<< >>>>>>>> >>>>>><< >>>><<>> >>>><<>< >>>>><>> >>>>><><
 * 3 >><< >><<<<<< >><<>>>> >><<>><< >><<<<>> >><<<<>< >><<><>> >><<><><
 * 4 <<>> <<>><<<< <<>>>>>> <<>>>><< <<>><<>> <<>><<>< <<>>><>> <<>>><><
 * 5 <<>< <<><<<<< <<><>>>> <<><>><< <<><<<>> <<><<<>< <<><><>> <<><><><
 * 6 ><>> ><>><<<< ><>>>>>> ><>>>><< ><>><<>> ><>><<>< ><>>><>> ><>>><><
 * 7 ><>< ><><<<<< ><><>>>> ><><>><< ><><<<>> ><><<<>< ><><><>> ><><><><
 */
inline seg operator+(seg a, seg b) {
    if (a.type == 1) {
        if (b.type == 1) {
            return seg(1, a.ans + b.ans, 0, 0);
        } else if (b.type == 2) {
            return seg(4, 0, a.ans, b.ans);
        } else if (b.type == 3) {
            return seg(5, 0, a.ans, b.ans);
        } else if ((b.type & 2) == 0) {
            return seg(b.type, b.ans, a.ans + b.left, b.right);
        } else {
            return seg(b.type ^ 2, b.ans, a.ans, b.right);
        }
    } else if (a.type == 2) {
        if (b.type < 4) {
            return seg(b.type == 2 ? 2 : 3, a.ans + b.ans, 0, 0);
        } else {
            return seg(b.type | 2, b.ans, a.ans + b.left, b.right);
        }
    } else if (a.type == 3) {
        if (b.type == 1) {
            return seg(3, a.ans + b.ans, 0, 0);
        } else if (b.type == 2) {
            return seg(6, 0, a.ans, b.ans);
        } else if (b.type == 3) {
            return seg(7, 0, a.ans, b.ans);
        } else if ((b.type & 2) == 0) {
            return seg(b.type | 2, b.ans, a.ans + b.left, b.right);
        } else {
            return seg(b.type, b.ans, a.ans, b.right);
        }
    } else if (b.type == 1) {
        return seg(a.type | 1, a.ans, a.left, a.right + b.ans);
    } else if (b.type == 2) {
        if ((a.type & 1) == 0) {
            return seg(a.type, a.ans, a.left, a.right + b.ans);
        } else {
            return seg(a.type ^ 1, a.ans, a.left, b.ans);
        }
    } else if (b.type == 3) {
        if ((a.type & 1) == 0) {
            return seg(a.type | 1, a.ans, a.left, a.right + b.ans);
        } else {
            return seg(a.type, a.ans, a.left, b.ans);
        }
    } else {
        seg ret(a.type & 6 | b.type & 1, max(a.ans, b.ans), a.left, b.right);
        if ((a.type & 1) == 0 || (b.type & 2) == 0) {
            mad(ret.ans, a.right + b.left);
        }
        return ret;
    }
}

inline std::ostream &operator<<(std::ostream &out, seg x) {
    return out << '(' << x.type << ", " << x.ans << ", " << x.left << ", "
               << x.right << ")";
}

struct node {
    seg s, sr;
    node(){};
    node(seg a, seg b) : s(a), sr(b) {}
    inline node &reverse() { return std::swap(s, sr), *this; }
};

inline node operator+(node a, node b) { return node(a.s + b.s, a.sr + b.sr); }

inline std::ostream &operator<<(std::ostream &out, node x) {
    return out << '{' << x.s << ", " << x.sr << '}';
}

seg sa(1, 1, 0, 0), sb(2, 1, 0, 0);

node na(sa, sb), nb(sb, sa);

const int N = 1048576;

char s[N];

int n, q, x, y;
int lazy[N];

node nd[N];

inline void build(int u, int l, int r) {
    if (l == r) return void(nd[u] = s[l] == '<' ? na : nb);
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    nd[u] = nd[u << 1] + nd[u << 1 | 1];
}

inline node reverse(int u, int l, int r) {
    if (l >= x && r <= y) return lazy[u] ^= 1, nd[u].reverse();
    int mid = l + r >> 1;
    node ret;
    if (y <= mid) {
        ret = reverse(u << 1, l, mid);
    } else if (x > mid) {
        ret = reverse(u << 1 | 1, mid + 1, r);
    } else {
        ret = reverse(u << 1, l, mid) + reverse(u << 1 | 1, mid + 1, r);
    }
    nd[u] = nd[u << 1] + nd[u << 1 | 1];
    if (lazy[u]) nd[u].reverse(), ret.reverse();
    return ret;
}

struct tree {} tr;

inline void outt(std::ostream &out, int u, int l, int r) {
    out << '(' << u << ", " << l << ", " << r << "): " << nd[u] << std::endl;
    if (l == r) return;
    int mid = l + r >> 1;
    outt(out, u << 1, l, mid);
    outt(out, u << 1 | 1, mid + 1, r);
}

inline std::ostream &operator<<(std::ostream &out, tree x) {
    return outt(out, 1, 1, n), out;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> q >> s + 1;
    build(1, 1, n);
    // std::cout << tr << std::endl;
    while (q--) {
        std::cin >> x >> y;
        std::cout << reverse(1, 1, n).s.ans << std::endl;
        // std::cout << tr << std::endl;
    }
    return 0;
}