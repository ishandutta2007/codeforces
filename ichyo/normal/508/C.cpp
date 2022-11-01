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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}
//}}}

int main(){
    iostream_init();

    int M, T, R;
    cin >> M >> T >> R;
    vector<int> w(M);
    REP(i, M) cin >> w[i];

    vector<int> cnt(M);

    int ans = 0;

    for(int t = -303; t <= 303; t++) {
        bool add = false;
        REP(i, M){
            if(t < w[i]) {
                int max_cnt = cnt[i] + (w[i] - t);
                if(max_cnt <= R) {
                    add = true;
                    break;
                }
            } else if(t == w[i]) {
                if(cnt[i] < R){
                    ans = -1;
                    break;
                }
            }
        }

        if(ans < 0) break;

        if(!add) continue;

        ans++;

        int l = t + 1;
        int r = t + 1 + T;
        // [l, r)
        REP(i, M) if(l <= w[i] && w[i] < r) {
            cnt[i] ++;
        }
    }

    cout << ans << endl;

    return 0;
}

/* vim:set foldmethod=marker: */