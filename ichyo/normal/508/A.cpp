// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

template<typename T1, typename T2>
ostream& operator << (ostream& os, const pair<T1, T2>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<T>& v) {
    os << "{";
    for(int i = 0; i < v.size(); i++)
        os << v[i] << (i+1<v.size()?", ":"");
    os << "}";
    return os;
}

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

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}
//}}}

int main(){
    iostream_init();

    int H, W;
    cin >> H >> W;
    int grid[1010][1010] = {};
    int M;
    cin >> M;
    int ans = 0;
    REP(k, M) {
        int x, y;
        cin >> x >> y;
        x++; y++;
        grid[y][x] = 1;
        bool ok = false;
        REP(dx, 2) REP(dy, 2) {
            int nx = x + dx - 1;
            int ny = y + dy - 1;
            int cnt = 0;
            REP(i, 2) REP(j, 2) {
                cnt += grid[ny + i][nx + j];
            }
            if(cnt == 4) ok = true;
        }
        if(ok) {
            ans = k + 1;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}

/* vim:set foldmethod=marker: */