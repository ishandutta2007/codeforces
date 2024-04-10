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

const double EPS = 1e-9;

const string YES = "YES";
const string NO = "NO";

int main(void) {
    vector<double> v;
    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;
    h %= 12; t1 %= 12; t2 %= 12;

    v.push_back(h + (m + s > 0 ? 0.5 : 0.0));
    v.push_back(m / 5 + (m % 5 + s > 0 ? 0.5 : 0.0));
    v.push_back(s / 5 + (s % 5 > 0 ? 0.5 : 0.0));
    v.push_back(t1);
    v.push_back(t2);

    sort(ALL(v));
    REP(i, v.size()) {
        int j = (i + 1) % v.size();
        if (Abs(v[i] - t1) <= EPS && Abs(v[j] - t2) <= EPS) {
            cout << YES << endl;
            return 0;
        }
        if (Abs(v[i] - t2) <= EPS && Abs(v[j] - t1) <= EPS) {
            cout << YES << endl;
            return 0;
        }
    }

    cout << NO << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/