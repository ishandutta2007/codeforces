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

static const int ST_SIZE = 1 << 20;
vector<int> data[ST_SIZE];
struct Query{
    vector<int> a;
    Query(const vector<int>& a_) : a(a_) {
        init();
    }
    // in b[l, r), count b[idx] < x
    int query(int l, int r, int x) {
        const int res = fast(l, r, x-1);
        //assert(res == slow(l, r, x));
        return res;
    }

    int slow(int l, int r, int x) {
        int cnt = 0;
        for(int i = l; i < r; i++) {
            if(a[i] < x) cnt++;
        }
        return cnt;
    }

    int n;
    void init() {
        assert(ST_SIZE > 800000);
        REP(i, ST_SIZE) data[i].clear();
        n  = a.size();
        init(0, 0, n);
    }
    void init(int k, int l, int r) {
        if(r - l == 1) {
            data[k].push_back(a[l]);
        } else {
            int lch = k*2 + 1, rch = lch + 1;
            init(lch, l, (l+r) / 2);
            init(rch, (l+r) / 2, r);
            data[k].resize(r-l);
            merge(data[lch].begin(), data[lch].end(), data[rch].begin(), data[rch].end(), data[k].begin());
        }
    }
    int fast(int i, int j, int x) {
        return fast(i, j, x, 0, 0, n);
    }
    int fast(int i, int j, int x, int k, int l, int r) {
        if(j <= l || r <= i) {
            return 0;
        } else if(i <= l && r <= j)  {
            return upper_bound(data[k].begin(), data[k].end(), x) - data[k].begin();
        } else {
            int lc = fast(i, j, x, k*2+1, l, (l+r)/2);
            int rc = fast(i, j, x, k*2+2, (l+r)/2, r);
            return lc + rc;
        }
    }
};
int main(){
    iostream_init();
    int n;
    while(cin >> n) {
        vector<int> a(n);
        REP(i, n) cin >> a[i];
        Query Q(a);

        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            for(int k = 1; k < n; k++) {
                int L = k*i + 1;
                int R = L + k;
                // [L, R)
                if(L > n-1) break;
                if(R > n) R = n;
                ans[k] += Q.query(L, R, a[i]);
            }
        }

        for(int k = 1; k < n; k++) {
            cout << ans[k];
            if(k == n-1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
    return 0;
}

/* vim:set foldmethod=marker: */