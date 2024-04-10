// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
#ifdef HITONANODE_LOCAL
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl
#else
#define dbg(x) (x)
#endif

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    const int D = floor_lg(M) + 2;
    bitset<1 << 19> cnt;

    while (N--) {
        int c;
        cin >> c;
        cnt.flip(c);
    }

    vector cum(D, cnt);
    REP(d, D) {
        REP(i, cnt.size()) if (i % (1 << d)) cum[d][i] = cum[d][i] ^ cum[d][i - 1];
        FOR(i, (1 << d), cnt.size()) cum[d][i] = cum[d][i] ^ cum[d][i - (1 << d)];
    }

    int Q;
    cin >> Q;

    auto get_rect = [&](auto xl, auto xr, auto yl, auto yr, int d) -> bool {
        if (xl > xr) return 0;
        if (yl > yr) return 0;
        bool ret = cum[d][xr + (yr << d)];
        if (xl) ret ^= cum[d][(xl - 1) + (yr << d)];
        if (yl) ret ^= cum[d][xr + ((yl - 1) << d)];
        if (xl and yl) ret ^= cum[d][(xl - 1) + ((yl - 1) << d)];
        return ret;
    };

    auto solve = [&](int l, int r) {
        bool flg = true;
        FOR(d, 1, D) {
            const int mask = (1 << d) - 1;
            const int yl = l >> d, yr = r >> d;
            const int xl = l & mask, xr = r & mask;
            const int ml = (xl + (1 << (d - 1))) & mask;
            const int mr = (xl + mask) & mask;
            bool s = 0;
            if (yl == yr) {
                if (ml <= mr) {
                    s ^= get_rect(max(ml, xl), min(mr, xr), yl, yr, d);
                } else {
                    s ^= get_rect(max(0, xl), min(mr, xr), yl, yr, d);
                    s ^= get_rect(max(ml, xl), min(mask, xr), yl, yr, d);
                }
            } else if (ml <= mr) {
                s ^= get_rect(ml, mr, yl + 1, yr - 1, d);
                s ^= get_rect(max(ml, xl), mr, yl, yl, d);
                s ^= get_rect(ml, min(mr, xr), yr, yr, d);
            } else {
                s ^= get_rect(ml, mask, yl + 1, yr - 1, d);
                s ^= get_rect(0, mr, yl + 1, yr - 1, d);

                s ^= get_rect(xl, mr, yl, yl, d);
                s ^= get_rect(max(ml, xl), mask, yl, yl, d);

                s ^= get_rect(ml, xr, yr, yr, d);
                s ^= get_rect(0, min(mr, xr), yr, yr, d);
            }
            if (s) {
                flg = false;
                break;
            }
        }
        return flg;
    };

    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << (char)('A' + solve(l, r));
    }
    cout << '\n';
}