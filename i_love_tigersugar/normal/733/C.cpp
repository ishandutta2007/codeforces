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

#define MAX   555
const char YES[] = "YES";
const char NO[] = "NO";

int sta[MAX], fin[MAX], numSta, numFin;
vector<pair<int, int> > segments;
vector<pair<int, char> > events;

void noAnswer(void) {
    printf("%s\n", NO);
    exit(0);
}

void init(void) {
    scanf("%d", &numSta);
    FOR(i, 1, numSta) scanf("%d", &sta[i]);
    scanf("%d", &numFin);
    FOR(i, 1, numFin) scanf("%d", &fin[i]);
}

void getPair(void) {
    int j = 1;
    FOR(i, 1, numFin) {
        int L = j;
        while (fin[i] > 0) {
            if (j > numSta || sta[j] > fin[i]) noAnswer();
            fin[i] -= sta[j++];
        }
        segments.push_back(make_pair(L, j - 1));
    }
    if (j <= numSta) noAnswer();
}

void printSegment(int l, int r) {
    if (l == r) return;
    int maxValue = sta[l];
    FOR(i, l, r) maximize(maxValue, sta[i]);
    FOR(i, l, r) if (sta[i] == maxValue) {
        bool haveLeft = i > l && sta[i - 1] < sta[i];
        bool haveRight = i < r && sta[i + 1] < sta[i];
        if (haveLeft) {
            FORD(j, i, l + 1) events.push_back(make_pair(j, 'L'));
            REP(love, r - i) events.push_back(make_pair(l, 'R'));
            return;
        }
        if (haveRight) {
            REP(love, r - i) events.push_back(make_pair(i, 'R'));
            FORD(j, i, l + 1) events.push_back(make_pair(j, 'L'));
            return;
        }
    }
    noAnswer();
}

void process(void) {
    reverse(ALL(segments));
    FORE(it, segments) printSegment(it->fi, it->se);
    printf("%s\n", YES);
    FORE(it, events) printf("%d %c\n", it->fi, it->se);
}

int main(void) {
    init();
    getPair();
    process();
    return 0;
}
/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/