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

const int POINT_DECREASE_RATE = 250;
const int NUM_SOLVED_SPLIT = 32;

const int NUM_LEVEL = 6;
const int POINT_VALUE[NUM_LEVEL] = {3000, 2500, 2000, 1500, 1000, 500};
const int MAX_RATE[NUM_LEVEL] = {1, 2, 4, 8, 16, 32};

const int NUM_PROBLEM = 5;

#define MAX   1111
const int INF = (int)1e9 + 8;

int submitTime[MAX][NUM_PROBLEM];
int numSolved[NUM_PROBLEM];
int minAvailable[NUM_LEVEL];
int numPerson;

void init(void) {
    cin >> numPerson;
    REP(i, numPerson) REP(j, NUM_PROBLEM) cin >> submitTime[i][j];
}

void prepare(void) {
    REP(i, NUM_LEVEL) {
        while (true) {
            int cur = minAvailable[i];
            int L = i == 0 ? 0 : MAX_RATE[i - 1] * cur / NUM_SOLVED_SPLIT + 1;
            int R = MAX_RATE[i] * cur / NUM_SOLVED_SPLIT;
            if (L <= R) break;
            minAvailable[i]++;
        }
    }

    REP(i, numPerson) REP(j, NUM_PROBLEM) if (submitTime[i][j] >= 0) numSolved[j]++;
}

bool ok(int curSolved, int level, int numMore) {
    long long L = level == 0 ? 0 : 1LL * MAX_RATE[level - 1] * (numPerson + numMore) / NUM_SOLVED_SPLIT + 1 - curSolved;
    long long R = 1LL * MAX_RATE[level] * (numPerson + numMore) / NUM_SOLVED_SPLIT - curSolved;
    maximize(L, 0);
    minimize(R, numMore);
    return L <= R;
}

int findMinAccount(int curSolved, int level) {
    int L = 0, R = INF;

    while (true) {
        if (L == R) return L;
        if (R - L == 1) return ok(curSolved, level, L) ? L : R;
        int M = (L + R) >> 1;
        if (ok(curSolved, level, M)) R = M; else L = M + 1;
    }
}

int minAccount(int level[]) {
    int res = 0;
    REP(i, NUM_PROBLEM) if (submitTime[0][i] >= 0)
        maximize(res, findMinAccount(numSolved[i], level[i]));

    REP(i, NUM_PROBLEM) if (submitTime[0][i] < 0) {
        long long L = 1LL * numSolved[i] * NUM_SOLVED_SPLIT / MAX_RATE[level[i]] - numPerson;
        minimize(L, INF);
        maximize(res, L);
        if (level[i] > 0) {
            long long R = 1LL * numSolved[i] * NUM_SOLVED_SPLIT / MAX_RATE[level[i] - 1] - 1 - numPerson;
            if (res > R) return INF;
        }
    }
    return res;
}

int submitScore(int maxScore, int time) {
    return time < 0 ? 0 : maxScore - maxScore / POINT_DECREASE_RATE * time;
}

int totalScore(int per, int level[]) {
    int res = 0;
    REP(i, NUM_PROBLEM) res += submitScore(POINT_VALUE[level[i]], submitTime[per][i]);
    return res;
}

void process(void) {
    int res = INF;
    REP(a, NUM_LEVEL) REP(b, NUM_LEVEL) REP(c, NUM_LEVEL) REP(d, NUM_LEVEL) REP(e, NUM_LEVEL) {
        int level[] = {a, b, c, d, e};
        if (totalScore(0, level) > totalScore(1, level)) {
            //printf("with %d %d %d %d %d is %d - %d need %d\n", a, b, c, d, e, totalScore(0, level), totalScore(1, level), minAccount(level));
            minimize(res, minAccount(level));
        }

    }
    printf("%d\n", res < INF ? res : -1);
}

int main(void) {
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY

    init();
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/