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
    int n, k;
    while(cin >> n >> k) {
        vector<int> a(n);
        REP(i, n) cin >> a[i];
        int q;
        cin >> q;
        map<int, int> val;
        val[0] = 0;
        REP(i, n) REP(p, k) {
            int sum = a[i] * (p+1);
            if(!val.count(sum)) val[sum] = p+1;
            val[sum] = min(val[sum], p+1);
        }
        while(q--) {
            int x;
            cin >> x;
            int ans = INT_MAX;
            REP(i, n) REP(p, k) {
                int sum = a[i] * (p+1);
                int rest = x - sum;
                if(val.count(rest)) {
                    ans = min(ans, val[rest] + p+1);
                }
            }
            if(ans > k) ans = -1;
            cout << ans << endl;
        }
    }
    return 0;
}

/* vim:set foldmethod=marker: */