#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   111

int length[MAX];
int numSegment;
int value[MAX];

long long profit[MAX];
long long bestSegment[MAX][MAX][MAX];
long long tmp[MAX][MAX];
int countOdd[MAX], countEven[MAX];
long long best[MAX];

void init(void) {
    string input; cin >> input >> input;
    vector<int> pos;
    REP(i, input.size()) if (i == 0 || input[i] != input[i - 1]) pos.push_back(i);
    pos.push_back(input.size());

    numSegment = pos.size() - 1;
    FOR(i, 1, numSegment) length[i] = pos[i] - pos[i - 1];

    FOR(i, 1, input.size()) cin >> value[i];
    FOR(i, 1, input.size()) FOR(j, 1, i) maximize(profit[i], profit[i - j] + value[j]);
}

int getLimit(int l, int r) {
    if (l > r) return 0;
    return l % 2 == 0 ? countEven[r] - countEven[l - 1] : countOdd[r] - countOdd[l - 1];
}

void calc(int l, int r) {
    memset(tmp, -0x3f, sizeof tmp);
    tmp[l - 1][0] = 0;

//    printf("CALC from %d to %d\n", l, r);
    FOR(cur, l - 1, r - 1) REP(curLength, getLimit(l, cur) + 1) if (tmp[cur][curLength] >= 0) {
//        printf("at %d, len %d is %lld\n", cur, curLength, tmp[cur][curLength]);
        for (int next = cur + 1; next <= r; next += 2)
            REP(nextLength, getLimit(cur + 1, next) + 1)
                if (bestSegment[cur + 1][next][nextLength] >= 0) {
                    int sumLength = (next - l) % 2 == 0 ? curLength + nextLength : curLength;
                    long long addMore = (next - l) % 2 == 0 ? 0 : profit[nextLength];
                    maximize(tmp[next][sumLength],
                             tmp[cur][curLength] + bestSegment[cur + 1][next][nextLength] + addMore);
                }
    }


    REP(k, getLimit(l, r) + 1) {
        bestSegment[l][r][k] = tmp[r][k];
//        if (bestSegment[l][r][k] >= 0) printf("Best with %d is %lld\n", k, bestSegment[l][r][k]);
    }
//    printf("___END___\n");
}

void process(void) {
    FOR(i, 1, numSegment) {
        countOdd[i] = countOdd[i - 1] + (i % 2 == 1 ? length[i] : 0);
        countEven[i] = countEven[i - 1] + (i % 2 == 0 ? length[i] : 0);
    }

    memset(bestSegment, -0x3f, sizeof bestSegment);
    FOR(i, 1, numSegment) bestSegment[i][i][length[i]] = 0;
    for (int delta = 2; delta < numSegment; delta += 2)
        FOR(i, 1, numSegment - delta) calc(i, i + delta);

    memset(best, -0x3f, sizeof best);
    best[0] = 0;
    FOR(i, 1, numSegment) FOR(j, 1, i) if ((i - j) % 2 == 0) {
        long long tmp = 0;
        REP(k, getLimit(j, i) + 1) maximize(tmp, bestSegment[j][i][k] + profit[k]);
        maximize(best[i], best[j - 1] + tmp);
    }

    cout << best[numSegment] << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/