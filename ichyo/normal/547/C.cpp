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

const int MAX_N = 5 * 100000 + 2;
void calc_div(int x, vector<pair<int, int>>& ps) {
    vector<int> p;
    for(int i = 2; i*i <= x; i++) {
        if(x % i == 0) {
            for(; x % i == 0; x /= i) { ; }
            p.push_back(i); 
        }
    }
    if(x > 1) {
        p.push_back(x);
    }
    REP(s, 1<<p.size()) {
        int b = __builtin_popcount(s);
        int m = 1;
        REP(i, p.size()) if(s >> i & 1) m *= p[i];
        ps.push_back(make_pair(m, b));
    }
}
vector<pair<int, int>> divs[MAX_N];
int bucket[MAX_N];
LL calc_num(int x) {
    LL sum = 0;
    for(auto p : divs[x]) {
        if(p.second % 2 == 0) {
            sum += bucket[p.first];
        } else {
            sum -= bucket[p.first];
        }
    }
    return sum;
}

int main(){
    int n, q;
    while(cin >> n >> q) {
        memset(bucket, 0, sizeof(bucket));
        vector<int> a(n);
        REP(i, n) scanf("%d", &a[i]);

        REP(i, n) if(divs[ a[i] ].empty()) {
            calc_div(a[i], divs[ a[i] ]);
        }

        LL ans = 0;
        vector<bool> used(n);
        REP(_, q) {
            int idx;
            scanf("%d", &idx);
            idx--;
            int x = a[idx];

            if(used[idx]) {
                used[idx] = false;
                for(auto p : divs[x]) {
                    bucket[ p.first ]--;
                }

                ans -= calc_num(x);
            } else {
                used[idx] = true;
                ans += calc_num(x);

                for(auto p : divs[x]) {
                    bucket[ p.first ]++;
                }
            }

            assert(ans >= 0);

            cout << ans << endl;
        }
    }
    return 0;
}

/* vim:set foldmethod=marker: */