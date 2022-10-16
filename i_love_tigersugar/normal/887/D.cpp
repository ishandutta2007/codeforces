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

#define MAX   300300
#define LOG   19

const int INF = (int)2e9 + 7;
const long long INF_LL = (long long)1e18 + 7LL;

#define POSITIVE   1
#define NEGATIVE   0

int numEvent, addOut, decOut, addIn, decIn, start, length;
int type[MAX], pos[MAX];

long long sumOut[MAX], sumIn[MAX], minSumOut[MAX][LOG + 1], minSumIn[MAX][LOG + 1];
int lg2[MAX];

void init(void) {
    cin >> numEvent >> addOut >> decOut >> addIn >> decIn >> start >> length;
    FOR(i, 1, numEvent) cin >> pos[i] >> type[i];
    pos[0] = -1;
    pos[numEvent + 1] = INF;
}

void prepare(void) {
    FOR(i, 1, numEvent) {
        if (type[i] == POSITIVE) {
            sumIn[i] = sumIn[i - 1] + addIn;
            sumOut[i] = sumOut[i - 1] + addOut;
        } else {
            sumIn[i] = sumIn[i - 1] - decIn;
            sumOut[i] = sumOut[i - 1] - decOut;
        }
    }

    FOR(i, 1, numEvent) {
        minSumIn[i][0] = sumIn[i];
        minSumOut[i][0] = sumOut[i];
    }

    FOR(j, 1, LOG) FOR(i, 1, numEvent - MASK(j) + 1) {
        minSumIn[i][j] = min(minSumIn[i][j - 1], minSumIn[i + MASK(j - 1)][j - 1]);
        minSumOut[i][j] = min(minSumOut[i][j - 1], minSumOut[i + MASK(j - 1)][j - 1]);
    }

    FOR(i, 1, numEvent) {
        while (MASK(lg2[i]) <= i) lg2[i]++;
        lg2[i]--;
    }
}

long long getMin(long long sum[][LOG + 1], int l, int r) {
    if (l > r) return INF_LL;
    int k = lg2[r - l + 1];
    return min(sum[l][k], sum[r - MASK(k) + 1][k]);
}

bool canFit(int l, int r) {
    return pos[r] - pos[l] + 1 <= length && pos[r + 1] - pos[l - 1] > length;
}

bool checkNegative(int l, int r) {
    if (l > r) return start + getMin(minSumOut, 1, numEvent) >= 0;

    if (start + getMin(minSumOut, 1, l - 1) < 0) return false;
    long long minDelta = getMin(minSumIn, l, r) - sumIn[l - 1];
    if (start + sumOut[l - 1] + minDelta < 0) return false;
    return true;
}

void process(void) {
    long long best = INF_LL;
    if (start + getMin(minSumOut, 1, numEvent) >= 0) {
        minimize(best, pos[numEvent] + 1);
        FOR(i, 1, numEvent) if (pos[i - 1] + length < pos[i])
            minimize(best, pos[i - 1] + 1);
    }

    FOR(i, 1, numEvent) {
        int R = upper_bound(pos, pos + numEvent + 2, pos[i] - 1 + length) - pos - 1;
        int L = upper_bound(pos, pos + numEvent + 2, pos[i - 1] + length) - pos - 1;
        FOR(j, L, R) if (i <= j && checkNegative(i, j)) {
            long long tmp = max(pos[i - 1] + 1, pos[j] - length + 1);
            minimize(best, tmp);
        }
    }

    cout << (best < INF_LL ? best : -1) << endl;
}

int main(void) {
    ios::sync_with_stdio(false);

    init();
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/