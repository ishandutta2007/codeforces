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

int main(){
    iostream_init();
    int n;
    cin >> n;
    int A[100][100];
    REP(i, n) {
        REP(j, n) {
            cin >> A[i][j];
        }
    }
    vector<int> ans;
    REP(i, n) {
        bool ok = true;
        REP(j, n) if(A[i][j] == 3 || A[i][j] == 1) ok = false;
        REP(j, n) if(A[j][i] == 3 || A[j][i] == 2) ok = false;
        if(ok) ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i];
        if(i + 1 == ans.size()) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    return 0;
}

/* vim:set foldmethod=marker: */