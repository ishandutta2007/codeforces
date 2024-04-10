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

#define MAX   1000100
const int mod = (int)1e9 + 7;

vector<pair<int, int> > haveAt[MAX];
int numRoom, numType, types[MAX];
int frac[MAX];

bool compType(const int &x, const int &y) {
    vector<pair<int, int> > &a = haveAt[x];
    vector<pair<int, int> > &b = haveAt[y];

    if (a.size() != b.size()) return a.size() < b.size();
    REP(i, a.size()) if (a[i] != b[i]) return a[i] < b[i];
    return false;
}

void process(void) {
    frac[0] = 1;
    FOR(i, 1, MAX - 1) frac[i] = 1LL * frac[i - 1] * i % mod;

    scanf("%d%d", &numRoom, &numType);
    FOR(i, 1, numRoom) {
        map<int, int> cnt;
        int t; scanf("%d", &t);
        REP(love, t) {
            int x; scanf("%d", &x);
            cnt[x]++;
        }

        FORE(it, cnt) haveAt[it->fi].push_back(make_pair(i, it->se));
    }

    FOR(i, 1, numType) types[i] = i;
    sort(types + 1, types + numType + 1, compType);

    vector<int> comps;
    FOR(i, 1, numType) {
        if (i == 1 || compType(types[i - 1], types[i])) comps.push_back(1);
        else comps.back()++;
    }

    int res = 1;
    FORE(it, comps) res = 1LL * res * frac[*it] % mod;
    cout << res << endl;
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/