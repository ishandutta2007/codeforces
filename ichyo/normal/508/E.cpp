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

const int MAX_N = 606;
int N;
int L[MAX_N], R[MAX_N];
char memo[MAX_N][MAX_N];
bool rec(int a, int b) {
    //[a, b)
    assert(a <= b);
    if(a == b) return true;
    if(memo[a][b] != -1) return memo[a][b];
    int mid = 2 * (b - a - 1) + 1;
    if(L[a] <= mid && mid <= R[a]) {
        if(rec(a+1, b)) return memo[a][b] = true;
    }
    for(int k = a + 1; k < b; k++) {
        if(rec(a, k) && rec(k, b)) return memo[a][b] = true;
    }
    return memo[a][b] = false;
}
string slow(int a, int b) {
    assert(a <= b);
    if(a == b) return "";
    //if(memo[a][b] != -1) return memo[a][b];
    int mid = 2 * (b - a - 1) + 1;
    if(L[a] <= mid && mid <= R[a]) {
        if(rec(a+1, b)) return "(" + slow(a+1, b) + ")";
    }
    for(int k = a + 1; k < b; k++) {
        if(rec(a, k) && rec(k, b)) return slow(a, k) + slow(k, b);
    }
    return "NG";
}
int main(){
    iostream_init();

    while(cin >> N) {
        REP(i, N) cin >> L[i] >> R[i];
        memset(memo, -1, sizeof(memo));
        if(rec(0, N)) {
            cout << slow(0, N) << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}

/* vim:set foldmethod=marker: */