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

#define MAX   200200

int n, q;
pair<int, int> actions[MAX];
int lastAct[MAX];
vector<int> haveAct[MAX];
set<pair<int, int>, greater<pair<int, int> > > curAct;

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) {
        int x, y; scanf("%d%d", &x, &y);
        actions[i] = make_pair(x, y);
        haveAct[x].push_back(i);
        lastAct[x] = i;
    }
}

bool haveFull(const vector<int> &people, int id) {
    int sum = n - id + 1;
    FORE(it, people) if (!haveAct[*it].empty()) {
        vector<int> &cur = haveAct[*it];
        int t = lower_bound(ALL(cur), id) - cur.begin();
        sum -= cur.size() - t;
    }
    return sum == 0;
}
int findLastID(const vector<int> &people, int id) {
    assert(!haveAct[id].empty());

    int L = 0;
    int R = haveAct[id].size() - 1;

    while (true) {
        if (L == R) return haveAct[id][L];
        if (R - L == 1) return haveAct[id][haveFull(people, haveAct[id][L]) ? L : R];
        int M = (L + R) >> 1;
        if (haveFull(people, haveAct[id][M])) R = M;
        else L = M + 1;
    }
}

void process(void) {
    FOR(i, 1, n) if (lastAct[i] > 0) curAct.insert(make_pair(lastAct[i], i));

    scanf("%d", &q);
    REP(love, q) {
        int k; scanf("%d", &k);
        vector<int> v;
        REP(love, k) {
            int x; scanf("%d", &x);
            v.push_back(x);
        }

        FORE(it, v) if (lastAct[*it] > 0) assert(curAct.erase(make_pair(lastAct[*it] ,*it)));
        if (curAct.empty()) printf("%d %d\n", 0, 0);
        else {
            int perID = curAct.begin()->se;
            v.push_back(perID);
            int actID = findLastID(v, perID);
            printf("%d %d\n", perID, actions[actID].se);
            v.pop_back();
        }
        FORE(it, v) if (lastAct[*it] > 0) assert(curAct.insert(make_pair(lastAct[*it], *it)).se);
    }
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/