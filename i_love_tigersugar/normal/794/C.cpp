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

string solve(string a, string b) {
    int n = a.size();
    deque<char> s, t;

    sort(ALL(a));
    FORE(it, a) s.push_back(*it);
    sort(ALL(b));
    FORE(it, b) t.push_back(*it);

    bool firstPlayer = true;

    string res(n, '$');
    REP(pmp, n) {
        if (t.back() <= s.front()) {
            FORD(i, n - 1, 0) if (res[i] == '$') {
                if (firstPlayer) {
                    res[i] = '(';
                } else {
                    res[i] = ')';
                }
                firstPlayer ^= 1;
            }

            REP(i, n) {
                if (res[i] == '(') {
                    res[i] = s.front(); s.pop_front();
                } else if (res[i] == ')') {
                    res[i] = t.back(); t.pop_back();
                }
            }
            return res;
        }

        if (firstPlayer) {
            res[pmp] = s.front(); s.pop_front();
        } else {
            res[pmp] = t.back(); t.pop_back();
        }

        firstPlayer ^= 1;
    }

    return res;
}

int main(void) {
    string s, t;
    while (cin >> s >> t) cout << solve(s, t) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/