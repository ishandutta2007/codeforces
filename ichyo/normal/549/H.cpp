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
namespace {
    pair<double, double> calc(double a, double b, double x) {
        vector<double> p = {a - x, a, a + x};
        if(abs(a) <= x) p.push_back(0);
        vector<double> q = {b - x, b, b + x};
        if(abs(b) <= x) q.push_back(0);
        vector<double> res;
        for(double v : p) for(double w : q) {
            res.push_back(v * w);
        }
        return make_pair(*min_element(res.begin(), res.end()), *max_element(res.begin(), res.end()));
    }
    bool ok(LL a, LL b, LL c, LL d, double x) {
        auto p = calc(a, d, x);
        auto q = calc(b, c, x);
        double min = p.first - q.second;
        double max = p.second - q.first;
        return min <= 0 && 0 <= max;
    }
}
int main(){
    iostream_init();
    LL a, b, c, d;
    while(cin >> a >> b >> c >> d) {
        double lb = 0, ub = 1e18;
        REP(_, 100)  {
            double x = (lb + ub) / 2;
            if(ok(a, b, c, d, x)) {
                ub = x;
            } else {
                lb = x;
            }
        }
        cout << ub << endl;
    }
    return 0;
}

/* vim:set foldmethod=marker: */