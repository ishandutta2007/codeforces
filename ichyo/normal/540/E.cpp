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
int main(){
    iostream_init();
    int n;
    while(cin >> n) {
        vector<int> x;
        vector<pair<int, int>> ps;
        x.push_back(0);
        x.push_back(1000000000 + 10);
        REP(i, n) {
            int a, b;
            cin >> a >> b;
            x.push_back(a);
            x.push_back(b);
            ps.push_back(make_pair(a, b));
        }
        sort(x.begin(), x.end());
        x.resize(unique(x.begin(), x.end()) - x.begin());
        map<int, int> m;
        REP(i, x.size()) m[ x[i] ] = i;

        vector<int> perm(x.size());
        REP(i, perm.size()) perm[i] = i;

        REP(i, n) {
            int a = m[ ps[i].first ];
            int b = m[ ps[i].second ];
            // dump(a);
            // dump(b);
            swap(perm[a], perm[b]);
        }

        BIT bit(perm.size() + 10);
        long long ans = 0;
        for(int i = 0; i+1 < perm.size(); i++) {
            // dump(perm[i]);
            ans += bit.get(perm.size() + 9) - bit.get(perm[i]-1);
            bit.add(perm[i], 1);

            // dump(bit.get(perm.size() + 9) - bit.get(perm[i]-1));
            int len = x[i+1]-x[i]-1;
            ans += (LL)len * (bit.get(perm.size() + 9) - bit.get(i));
            bit.add(i, len);
            // dump(i);
            // dump(len);
            // dump(bit.get(perm.size() + 9));
            // dump(i);
            // dump(bit.get(i));
            // dump((LL)len * (bit.get(perm.size() + 9) - bit.get(i)));
            // cout << "add : " << perm[i] << endl;
        }
        cout << ans << endl;
    }
    return 0;
}

/* vim:set foldmethod=marker: */