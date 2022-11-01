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
    cout.setf(ios::fixed);
    cout.precision(12);
}
//}}}

int main(){
    iostream_init();

    int n;
    while(cin >> n) {
        vector<pair<int, int>> ps(n);
        REP(i, n) {
            int x, w;
            cin >> x >> w;
            ps[i] = make_pair(x-w, x+w);
        }
        sort(ps.begin(), ps.end());
        // cout << ps << endl;
        vector<int> dp(n + 2, 0);
        for(int i = 0; i < n; i++) {
            dp[i+1] = max(dp[i+1], dp[i]);
            int j = lower_bound(ps.begin(), ps.end(), make_pair(ps[i].second, INT_MIN)) - ps.begin();
            // cout << i << " " << j << endl;
            dp[j+1] = max(dp[j+1], dp[i+1] + 1);
        }
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }

    return 0;
}

/* vim:set foldmethod=marker: */