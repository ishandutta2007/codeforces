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

struct Data{
    int N;
    multiset<int> s;
    set<pair<int, int>> sg;
    Data(int w) {
        N = w;
        s.insert(N);
        sg.insert(make_pair(0, N));
    }
    int max() {
        return *(--s.end());
    }
    void cut(int x) {
        auto it = --sg.lower_bound(make_pair(x, INT_MIN));
        auto p = *it;
        auto p1 = make_pair(p.first, x);
        auto p2 = make_pair(x, p.second);
        sg.erase(it);
        sg.insert(p1);
        sg.insert(p2);

        int l = p.second - p.first;
        int l1 = x - p.first;
        int l2 = p.second - x;
        s.erase(s.find(l));
        s.insert(l1);
        s.insert(l2);
    }
};
int main(){
    iostream_init();

    int w, h, n;
    while(cin >> w >> h >> n) {
        Data W(w);
        Data H(h);
        REP(i, n) {
            string a;
            int t;
            cin >> a >> t;
            if(a == "H") {
                H.cut(t);
            } else {
                W.cut(t);
            }
            cout << (long long)H.max() * W.max() << endl;
        }
    }

    return 0;
}

/* vim:set foldmethod=marker: */