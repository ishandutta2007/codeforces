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

map<pair<int, int>, vector<pair<int, int> > > mp;

long long fractionCompare(long long a, long long b, long long c, long long d) {
    assert(b != 0 && d != 0);
    long long ab = a / b;
    long long cd = c / d;
    if (ab != cd) return ab - cd;
    a %= b;
    c %= d;
    if (a == 0) return -c;
    if (c == 0) return a;
    return -fractionCompare(b, a, d, c);
}

void process(void) {
    int n; scanf("%d", &n);
    FOR(i, 1, n) {
        vector<pair<int, int> > len;
        REP(j, 3) {
            int x; scanf("%d", &x);
            len.push_back(make_pair(j, x));
        }
        sort(ALL(len));
        do {
            int x = len[0].se;
            int y = len[1].se;
            int z = len[2].se;
            mp[make_pair(x, y)].push_back(make_pair(z, i));
        } while (next_permutation(ALL(len)));
    }

    int best = -1;
    vector<int> result;
    FORE(it, mp) {
        vector<pair<int, int> > &cur = it->se;
        sort(ALL(cur), greater<pair<int, int> > ());
        cur.resize(unique(ALL(cur)) - cur.begin());
        int tmp = 0;
        REP(i, min((int)cur.size(), 2)) tmp += cur[i].fi;
        minimize(tmp, it->fi.fi);
        minimize(tmp, it->fi.se);
        if (best < tmp) {
            best = tmp;
            result.clear();
            REP(i, min((int)cur.size(), 2)) result.push_back(cur[i].se);
        }
    }
    printf("%d\n", (int) result.size());
    FORE(it, result) printf("%d ", *it); printf("\n");
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/