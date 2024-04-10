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

void solve() {
    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;
    int cnt1 = 0;
    int cnt2 = 0;
    int sum = 0;
    REP(i, k) {
        int a;
        cin >> a;
        sum += a;
        if(a < y) cnt1++;
    }
    if(cnt1 >= n/2+1) {
        cout << -1 << endl;
        return;
    }
    vector<int> res;
    while(y > 1 && cnt1+1 <= n/2 && res.size()+k < n) {
        cnt1++;
        res.push_back(1);
    }
    while(res.size() + k < n) {
        res.push_back(y);
    }
    REP(i, res.size()) sum += res[i];
    if(sum > x) {
        cout << -1 << endl;
        return;
    }
    REP(i, res.size()) {
        cout << res[i];
        if(i+1 != res.size()) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}
int main(){
    iostream_init();
    solve();
    return 0;
}

/* vim:set foldmethod=marker: */