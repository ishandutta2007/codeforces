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
const int INF = (int)1e9 + 7;

int numCar, numStop, len, allowTime;
int cost[MAX], capa[MAX];
int segment[MAX];
long long sum[MAX];

void init(void) {
    scanf("%d%d%d%d", &numCar, &numStop, &len, &allowTime);
    FOR(i, 1, numCar) scanf("%d%d", &cost[i], &capa[i]);

    vector<int> points;
    points.push_back(0);
    points.push_back(len);
    REP(love, numStop) {
        int x; scanf("%d", &x);
        points.push_back(x);
    }

    sort(ALL(points));
    numStop++;
    assert(points.size() == numStop + 1);

    FOR(i, 1, numStop) segment[i] = points[i] - points[i - 1];
    sort(segment + 1, segment + numStop + 1);
    FOR(i, 1, numStop) sum[i] = sum[i - 1] + segment[i];
}

long long calcTime(int capa) {
    if (segment[numStop] > capa) return allowTime + 1;
    int numSmall = upper_bound(segment + 1, segment + numStop + 1, capa / 2) - segment - 1;

    long long timeSmall = sum[numSmall];
    long long timeBig = 3LL * (sum[numStop] - sum[numSmall]) - 1LL * (numStop - numSmall) * capa;
    return timeBig + timeSmall;
}

void process(void) {
    int res = INF;
    FOR(i, 1, numCar) if (calcTime(capa[i]) <= allowTime) minimize(res, cost[i]);
    printf("%d\n", res < INF ? res : -1);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/