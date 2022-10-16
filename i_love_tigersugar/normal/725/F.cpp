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

/* Author: Van Hanh Pham - skyvn97 */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

//This solution is based on the editorial

#define MAX   100100

pair<long long, long long> val[MAX][2];
int n;

void init(void) {
    cin >> n;
    REP(i, n) REP(j, 2) cin >> val[i][j].fi >> val[i][j].se;
    REP(i, n) REP(j, 2) {
        val[i][j].fi *= 2;
        val[i][j].se *= 2;
    }
}

void process(void) {
    long long res = 0;
    vector<pair<long long, long long> > photos;
    REP(i, n) {
        if (val[i][0].fi + val[i][0].se >= val[i][1].fi + val[i][1].se) {
            REP(j, 2) photos.push_back(val[i][j]);
        } else if (val[i][0].fi > val[i][1].se) {
            long long tmp = val[i][0].fi - val[i][1].se;
            photos.push_back(make_pair(tmp, -tmp));
        } else if (val[i][0].se > val[i][1].fi) {
            long long tmp = val[i][1].fi - val[i][0].se;
            photos.push_back(make_pair(tmp, -tmp));
        }
    }
    vector<long long> values;
    FORE(it, photos) {
        res += (it->fi - it->se) / 2;
        values.push_back((it->fi + it->se) / 2);
    }
    sort(ALL(values), greater<long long> ());
    REP(i, values.size()) res += (i % 2 ? -values[i] : values[i]);
    cout << res / 2 << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/