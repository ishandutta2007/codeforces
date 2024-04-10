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

#define MAX   100100

int allow[MAX], req[MAX], numDay, numSub;
int passAt[MAX], need[MAX];

void init(void) {
    scanf("%d%d", &numDay, &numSub);
    FOR(i, 1, numDay) scanf("%d", &allow[i]);
    FOR(i, 1, numSub) scanf("%d", &req[i]);
}

bool compare(const int &x, const int &y) {
    return passAt[x] < passAt[y];
}
bool ok(int x) {
    memset(passAt, -1, sizeof passAt);
    FOR(i, 1, numSub) need[i] = req[i];

    FOR(i, 1, x) if (allow[i] > 0) maximize(passAt[allow[i]], i);
    FOR(i, 1, numSub) if (passAt[i] < 0) return false;

    vector<int> subjects;
    FOR(i, 1, numSub) subjects.push_back(i);
    sort(ALL(subjects), compare);

    int id = 0;
    FOR(i, 1, x) {
        if (allow[i] > 0 && passAt[allow[i]] == i) {
            if (need[allow[i]] > 0) return false;
        } else {
            while (id < subjects.size() && need[subjects[id]] <= 0) id++;
            if (id < subjects.size()) need[subjects[id]]--;
        }
    }
    return true;
}

int process(void) {
    if (!ok(numDay)) return -1;
    int L = 0;
    int R = numDay;
    while (true) {
        if (L == R) return L;
        if (R - L == 1) return (ok(L) ? L : R);
        int M = (L + R) >> 1;
        if (ok(M)) R = M; else L = M + 1;
    }
}
int main(void) {
    init();
    printf("%d\n", process());
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/