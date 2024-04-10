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

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

map<string, int> cnt;
vector<string> a, b;

bool process(void) {
    int m, n; cin >> m >> n;

    REP(love, m) {
        string s; cin >> s;
        a.push_back(s);
        cnt[s]++;
    }
    REP(love, n) {
        string s; cin >> s;
        b.push_back(s);
        cnt[s]++;
    }

    int numA = 0, numB = 0, both = 0;
    FORE(it, a) {
        if (cnt[*it] == 1) numA++; else both++;
    }
    FORE(it, b) {
        if (cnt[*it] == 1) numB++;
    }

    bool first = true;
    while (true) {
        if (first) {
            if (numA == 0 && both == 0) return false;
            if (both > 0) both--; else numA--;
        } else {
            if (numB == 0 && both == 0) return true;
            if (both > 0) both--; else numB--;
        }

        first = !first;
    }
}

int main(void) {
    cout << (process() ? "YES" : "NO") << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/