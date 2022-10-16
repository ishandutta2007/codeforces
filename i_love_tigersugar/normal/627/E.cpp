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
#define index   ___index
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

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

#define MAX   3030
int numRow, numCol, numPoint, range;
vector<int> pointsInRow[MAX], pointsInCol[MAX];
long long result, numRec;

int index[MAX][MAX];
int pos[MAX], numPos, prev[MAX], next[MAX];

int leftDelta[MAX], numLeftDelta;
int rightDelta[MAX], numRightDelta;

void init(void) {
    scanf("%d%d%d%d", &numRow, &numCol, &numPoint, &range); range--;
    REP(love, numPoint) {
        int x, y; scanf("%d%d", &x, &y);
        pointsInRow[x].push_back(y);
        pointsInCol[y].push_back(x);
    }
}

#define COMB(x) (1LL * (x) * ((x) - 1) / 2)

void prepareTopRow(int top) {
    numPos = 0;
    pos[++numPos] = 0;
    FOR(i, 1, numCol) FORE(jt, pointsInCol[i]) if (*jt >= top) {
        pos[++numPos] = i;
        index[*jt][i] = numPos;
    }
    pos[++numPos] = numCol + 1;

    FOR(i, 1, numPos - 1) next[i] = i + 1;
    FOR(i, 2, numPos) prev[i] = i - 1;

    numRec = 0;
    FOR(i, 1, numPos - 1) numRec += COMB(pos[i + 1] - pos[i]);
    FOR(i, 1, numPos - 1) FOR(j, i + 1, min(i + range, numPos - 1))
        numRec += 1LL * (pos[i + 1] - pos[i]) * (pos[j + 1] - pos[j]);
}

void removePos(int index) {
//    printf("Removing index %d\n", index);
    int beforeLeft = pos[index] - pos[prev[index]];
    int beforeRight = pos[next[index]] - pos[index];
    int after = beforeLeft + beforeRight;
    numRec += COMB(after) - COMB(beforeLeft) - COMB(beforeRight);

    numLeftDelta = numRightDelta = 0;
    int tmp = prev[index];
    while (numLeftDelta < range && tmp > 1) {
        leftDelta[++numLeftDelta] = pos[tmp] - pos[prev[tmp]];
        tmp = prev[tmp];
    }
    tmp = next[index];
    while (numRightDelta < range && tmp < numPos) {
        rightDelta[++numRightDelta] = pos[next[tmp]] - pos[tmp];
        tmp = next[tmp];
    }

//    cerr << "AHUHU " << numRec << endl;
//    printf("Left deltas:");
//    FOR(i, 1, numLeftDelta) printf(" %d", leftDelta[i]);
//    printf("\n");
//    printf("Right deltas:");
//    FOR(i, 1, numRightDelta) printf(" %d", rightDelta[i]);
//    printf("\n");

    if (range > 0) numRec -= 1LL * beforeLeft * beforeRight;
    FOR(i, 1, numLeftDelta) numRec -= 1LL * leftDelta[i] * (i < range ? (beforeLeft + beforeRight) : beforeLeft);
    FOR(i, 1, numRightDelta) numRec -= 1LL * rightDelta[i] * (i < range ? (beforeLeft + beforeRight) : beforeRight);

//    cerr << "AHIHI " << numRec << endl;

    FOR(i, 1, numLeftDelta) if (range - i <= numRightDelta) numRec += 1LL * leftDelta[i] * rightDelta[range - i];
    FOR(i, 1, numLeftDelta) numRec += 1LL * after * leftDelta[i];
    FOR(i, 1, numRightDelta) numRec += 1LL * after * rightDelta[i];

    prev[next[index]] = prev[index];
    next[prev[index]] = next[index];
}

void process(void) {
    FOR(top, 1, numRow) {
        prepareTopRow(top);
//        printf("after preparing row %d: %lld\n", top, numRec);
        FORD(bot, numRow, top) {
            result += numRec;
            FORE(it, pointsInRow[bot]) removePos(index[bot][*it]);
//            printf("after removing row %d: %lld\n", bot, numRec);
        }
    }
    cout << 1LL * numRow * (numRow + 1) / 2 * numCol * (numCol + 1) / 2 - result << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/