#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
const int INF = (int) 1e9 + 7;
int mode, hour, minute;
bool valid(int mode, int x, int y) {
    if (y < 0 || y >= 60) return false;
    if (mode == 12) return 1 <= x && x <= 12;
    if (mode == 24) return 0 <= x && x <= 23;
    assert(false);
}
int diff(int x, int y) {
    if (x < 0 || y < 0) return INF;
    int res = 0;
    if (x % 10 != y % 10) res++;
    if (x / 10 != y / 10) res++;
    return res;
}
int main(void) {
    string s; cin >> mode >> s;
    hour = (s[0] - '0') * 10 + s[1] - '0';
    minute = (s[3] - '0') * 10 + s[4] - '0';
    pair<int, int> best(-1, -1);
    REP(i, 24) REP(j, 60) if (valid(mode, i, j)) {
        if (diff(hour, i) + diff(minute, j) < diff(hour, best.fi) + diff(minute, best.se)) best = make_pair(i, j);
    }
    cout << best.fi / 10 << best.fi % 10 << ":" << best.se / 10 << best.se % 10 << endl;
    return 0;
}