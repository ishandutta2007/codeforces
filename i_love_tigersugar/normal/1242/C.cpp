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

const char YES[] = "Yes";
const char NO[] = "No";

void answerNo(void) {
    printf("%s\n", NO);
    exit(EXIT_SUCCESS);
}

#define MAX   16

int numSet;
vector<long long> sets[MAX];
long long sumSet[MAX], sumAll, expectedSum;
map<long long, int> setIndex;

pair<int, long long> beCircle[MASK(MAX)];

int canSplit[MASK(MAX)];
pair<long long, int> res[MAX];

void init(void) {
    scanf("%d", &numSet);
    REP(i, numSet) {
        int x; scanf("%d", &x);
        REP(love, x) {
            int y; scanf("%d", &y);

            sets[i].push_back(y);
            setIndex[y] = i;

            sumAll += y;
            sumSet[i] += y;
        }
    }

    if (sumAll % numSet != 0) answerNo();
    expectedSum = sumAll / numSet;
}

int getSetIndex(long long value) {
    __typeof(setIndex.begin()) it = setIndex.find(value);
    return it == setIndex.end() ? -1 : it->se;
}

bool tryFirst(long long value, bool trace) {
    int firstID = getSetIndex(value); assert(firstID >= 0);
    long long firstValue = value;
    int id = firstID;
    int used = MASK(id);

    vector<pair<int, long long>> perm;
    if (trace) perm.push_back(make_pair(firstID, firstValue));

    while (true) {
        long long prevValue = expectedSum - (sumSet[id] - value);
        int prevID = getSetIndex(prevValue);

        if (prevID == firstID && prevValue == firstValue) {
            beCircle[used] = make_pair(firstID, firstValue);
            if (trace) {
                REP(i, perm.size()) {
                int j = i - 1;
                if (j < 0) j += (int)perm.size();
                res[perm[i].fi] = make_pair(perm[i].se, perm[j].fi);
                }
            }

            return true;
        }

        if (prevID < 0 || BIT(used, prevID)) return false;
        id = prevID;
        value = prevValue;
        used |= MASK(id);

        if (trace) perm.push_back(make_pair(id, value));
    }
}

void process(void) {
    REP(mask, MASK(numSet)) beCircle[mask] = make_pair(-1, -1);
    FORE(it, setIndex) tryFirst(it->fi, false);

    memset(canSplit, -1, sizeof canSplit);
    canSplit[0] = 0;
    REP(mask, MASK(numSet)) if (canSplit[mask] >= 0) {
        int remain = (MASK(numSet) - 1) ^ mask;
        FORD(subset, remain, 0) {
            subset &= remain;
            if (beCircle[subset].fi >= 0) canSplit[mask | subset] = subset;
        }
    }

    int curMask = MASK(numSet) - 1;
    if (canSplit[curMask] < 0) answerNo();

    while (curMask > 0) {
        int subset = canSplit[curMask];
        assert(subset > 0);
        assert(tryFirst(beCircle[subset].se, true));
        curMask ^= subset;
    }

    printf("%s\n", YES);
    REP(i, numSet) cout << res[i].fi << " " << res[i].se + 1 << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/