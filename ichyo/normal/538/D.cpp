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
    vector<string> grid(n);
    REP(y, n) {
        cin >> grid[y];
    }

    vector<pair<int, int>> ps;
    REP(y, n) REP(x, n) if(grid[y][x] == 'o') ps.push_back(make_pair(y, x));

    vector<string> ans(2*n-1, string(2*n-1, '.'));
    bool no = false;
    bool used[55][55] = {};

    for(int dy = -n+1; dy <= n-1; dy++) 
    for(int dx = -n+1; dx <= n-1; dx++)  {
        int Y = dy+(n-1);
        int X = dx+(n-1);

        if(dy == 0 && dx == 0) {
            ans[Y][X] = 'o';
            continue;
        }

        bool b1 = false;
        bool b2 = false;
        for(auto p : ps) {
            int by = p.first;
            int bx = p.second;
            int y = by + dy;
            int x = bx + dx;
            if(valid(x, n) && valid(y, n)) {
                if(grid[y][x] == 'x' && !used[y][x]) {
                    b1 = true;
                } else if(grid[y][x] == '.') {
                    b2 = true;
                }
            }
        }
        if(b1 && !b2) {
            ans[Y][X] = 'x';
            for(auto p : ps) {
                int by = p.first;
                int bx = p.second;
                int y = by + dy;
                int x = bx + dx;
                if(valid(x, n) && valid(y, n)) {
                    if(grid[y][x] == 'x') {
                        b1 = true;
                        used[y][x] = true;
                    }
                }
            }
        } else {
            ans[Y][X] = '.';
        }
    }
    REP(y, n) REP(x, n) if(grid[y][x] == 'x' && !used[y][x]) no = true;
    if(no) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        REP(y, ans.size()) {
            cout << ans[y] << endl;
        }
    }
    return 0;
}

/* vim:set foldmethod=marker: */