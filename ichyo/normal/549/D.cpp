// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

#ifdef LOCAL
#include "contest.h"
#else
#define dump(x) 
#endif

class range {
    struct Iterator {
        int val, inc;
        int operator*() {return val;}
        bool operator!=(Iterator& rhs) {return val < rhs.val;}
        void operator++() {val += inc;}
    };
    Iterator i, n;
    public:
    range(int e) : i({0, 1}), n({e, 1}) {}
    range(int b, int e) : i({b, 1}), n({e, 1}) {}
    range(int b, int e, int inc) : i({b, inc}), n({e, inc}) {}
    Iterator& begin() {return i;}
    Iterator& end() {return n;}
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}
//}}}

struct BIT{
    vector<LL> sums;
    BIT(int n) : sums(n) {}

    // v[at] += by
    void add(int at, LL by) {
        while(at < sums.size()){
            sums[at] += by;
            at |= at + 1;
        }
    }

    // v[0] + ... + v[at]
    LL get(int at) {
        LL res = 0;
        while(at >= 0) {
            res += sums[at];
            at = (at & (at + 1)) - 1;
        }
        return res;
    }

    // --- optional ---
    int size() const { return sums.size(); }
    LL operator [](int idx) const { return sums[idx]; }
};

struct BITRange{
    BIT bit0, bit1;
    BITRange(int n) : bit0(n + 1), bit1(n + 1) {}

    // v[a], v[a+1], ..., v[b-1] += by
    void add(int a, int b, LL by) {
        bit0.add(a, -by * a);
        bit0.add(b, +by * b);
        bit1.add(a, by);
        bit1.add(b, -by);
    }

    // v[0] + v[1] + ... + v[c-1]
    LL get(int c) {
        LL A = bit0.get(c);
        LL B = bit1.get(c);
        return A + B * c;
    }
};

int main(){
    iostream_init();
    int H, W;
    while(cin >> H >> W) {
        string grid[128];
        REP(y, H) cin >> grid[y];
        vector<BITRange> bits;
        REP(y, H) bits.push_back(BITRange(W));
        int value[256] = {};
        value['W'] = 1;
        value['B'] = -1;
        int ans = 0;
        for(int i = W + H - 1; i >= 0; i--) {
            for(int x = min(W-1, i); x + H-1 >= i && x >= 0; x--) {
                int y = i - x;
                int t = bits[y].get(x+1) - bits[y].get(x);
                const int add = value[(int)grid[y][x]] - t;
                if(add != 0) {
                    // if(H < 10) cout << x << " " << y << " " << grid[y][x] << " " << t << " " << add << endl;
                    ans++;
                    for(int j = 0; j <= y; j++) {
                        bits[j].add(0, x+1, add);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/* vim:set foldmethod=marker: */