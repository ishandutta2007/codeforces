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
#define MAX_SIZE   100000

pair<int, int> bridges[MAX];
int n;
long long dur;
vector<long long> drinkTime;
long long numDrink;

void init(void) {
    cin >> n >> dur;
    FOR(i, 1, n) cin >> bridges[i].fi;
    FOR(i, 1, n) cin >> bridges[i].se;
    FOR(i, 1, n) if (bridges[i].fi > bridges[i].se) {
        cout << -1 << endl;
        exit(0);
    }
}

long long ceil(long long a, long long b) {
    assert(b != 0);
    return a % b == 0 ? a / b : a / b + 1;
}
void process(void) {
    long long prevDur = 0;
    long long startTime = 0;
    FOR(i, 1, n) {
        int len = bridges[i].fi;
        int allow = bridges[i].se;
        if (prevDur >= len) {
            prevDur -= len;
            startTime += len;
            continue;
        }
        int needFastTime = max(0LL, prevDur - allow + 2 * (len - prevDur));
        int needDrink = ceil(needFastTime, dur);
        numDrink += needDrink;
        int runTime = prevDur + needFastTime + 2 * (len - prevDur - needFastTime);
        assert(prevDur + needFastTime <= len && runTime <= allow);
        startTime += runTime;
        if (numDrink <= MAX_SIZE) {
            long long time = startTime - needFastTime;
            REP(love, needDrink) {
                drinkTime.push_back(time);
                time += dur;
            }
        }
        prevDur = 1LL * needDrink * dur - needFastTime;
        assert(prevDur <= dur);
    }
    cout << numDrink << endl;
    if (numDrink <= MAX_SIZE) {
        sort(ALL(drinkTime));
        FORE(it, drinkTime) cout << *it << " ";
        cout << endl;
    }
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/