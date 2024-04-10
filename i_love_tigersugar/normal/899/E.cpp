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

class CompareSecond {
public:
    bool operator () (const pair<int, int> &a, const pair<int, int> &b) const {
        return a.se == b.se ? a.fi > b.fi : a.se < b.se;
    }
};

#define MAX   200200
int seq[MAX], n;

set<pair<int, int>> segments;
set<pair<int, int>, CompareSecond> segmentsByLength;

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &seq[i]);
    vector<int> pos;
    pos.push_back(1);
    FOR(i, 2, n) if (seq[i] != seq[i - 1]) pos.push_back(i);
    pos.push_back(n + 1);
    REP(i, (int)pos.size() - 1) segments.insert(make_pair(pos[i], pos[i + 1] - pos[i]));
}

#define NA   make_pair(-1, -1)

void process(void) {
    FORE(it, segments) segmentsByLength.insert(*it);

    int res = 0;
    while (!segments.empty()) {
        res++;
        __typeof(segmentsByLength.begin()) __it = segmentsByLength.end(); __it--;
        pair<int, int> toRemove = *__it;
        segmentsByLength.erase(__it);

        __typeof(segments.begin()) it = segments.find(toRemove); assert(it != segments.end());
        pair<int, int> prev = it == segments.begin() ? NA : *((--it)++);
        pair<int, int> next = (++it)-- == segments.end() ? NA : *((++it)--);
        segments.erase(it);
        if (prev != NA && next != NA && seq[prev.fi] == seq[next.fi]) {
            pair<int, int> newPair(prev.fi, prev.se + next.se);
            segments.erase(prev);
            segments.erase(next);
            segments.insert(newPair);
            segmentsByLength.erase(prev);
            segmentsByLength.erase(next);
            segmentsByLength.insert(newPair);
        }
    }

    printf("%d\n", res);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/