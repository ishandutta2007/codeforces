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

#define HEXA_MASK(i) MASK((i) << 2)
#define HEXA_DIGIT(x, i) (((x) >> ((i) << 2)) & 15)
#define CLEAR_HEXA_DIGIT(x, i) ((x) & ~(15 << ((i) << 2)))
#define SET_HEXA_DIGIT(x, i, d) (CLEAR_HEXA_DIGIT(x, i) ^ ((d) << ((i) << 2)))

#define LENGTH   5
#define BLANK   10
#define VALUE   100100
vector<int> primes[LENGTH + 1][HEXA_MASK(LENGTH) + 1];
bool notPrime[VALUE];

// least significant digit in x becomes most significant digit in the hexa code
int toHexa(int x, int numDigit) {
    int res = 0;
    REP(love, numDigit) {
        res = (res << 4) ^ (x % 10);
        x /= 10;
    }
    return x > 0 ? -1 : res;
}

void prepare(void) {
    REP(i, 2) notPrime[i] = true;
    FOR(i, 2, VALUE - 1) if (!notPrime[i]) for (int j = 2 * i; j < VALUE; j += i) notPrime[j] = true;

    FOR(i, 2, VALUE - 1) if (!notPrime[i]) FOR(length, 1, LENGTH) {
        int code = toHexa(i, length);
        if (code < 0) continue;

        REP(mask, MASK(length)) {
            int newCode = code;
            REP(i, length) if (BIT(mask, i)) newCode = SET_HEXA_DIGIT(newCode, i, BLANK);
            primes[length][newCode].push_back(code);
        }
    }
}

int res;
void backtrack(vector<int> &state, int filled) {
    int numRow = state.size();
    if (__builtin_popcount(filled) == numRow) {
        res++;
        return;
    }

    int row = -1, numCandidate = VALUE;
    if (!BIT(filled, numRow - 1)) {
        row = numRow - 1;
        numCandidate = primes[numRow][state[row]].size();
    } else {
        REP(i, numRow) if (!BIT(filled, i)) {
            int tmpCandidate = primes[numRow][state[i]].size();
            if (minimize(numCandidate, tmpCandidate)) row = i;
        }
    }

    if (numCandidate == 0) return;
    if (__builtin_popcount(filled) == numRow - 1) {
        res += numCandidate;
        return;
    }

    int oldState = state[row];

    vector<int> &candidates = primes[numRow][oldState];
    FORE(it, candidates) {
        REP(j, numRow) {
            // state[row][j] = state[j][row] = HEXA_DIGIT(*it, j)
            state[row] = SET_HEXA_DIGIT(state[row], j, HEXA_DIGIT(*it, j));
            state[j] = SET_HEXA_DIGIT(state[j], row, HEXA_DIGIT(*it, j));
        }
        backtrack(state, filled | MASK(row));
    }

    state[row] = oldState;
    REP(i, numRow) state[i] = SET_HEXA_DIGIT(state[i], row, HEXA_DIGIT(oldState, i));
}

int numDigit(int x) {
    return x < 10 ? 1 : numDigit(x / 10) + 1;
}

int solve(int x) {
    int numRow = numDigit(x);
    int code = toHexa(x, numRow);
    vector<int> state(numRow, 0);

    REP(i, numRow) REP(j, numRow) // state[i][j] = BLANK
        state[i] = SET_HEXA_DIGIT(state[i], j, BLANK);

    REP(i, numRow) {
        // state[0][i] = state[i][0] = HEXA_DIGIT(code, i)
        state[0] = SET_HEXA_DIGIT(state[0], i, HEXA_DIGIT(code, i));
        state[i] = SET_HEXA_DIGIT(state[i], 0, HEXA_DIGIT(code, i));
    }

    res = 0;
    backtrack(state, MASK(0));
    return res;
}

int main(void) {
    prepare();
    int t; scanf("%d", &t);
    REP(love, t) {
        int x; scanf("%d", &x);
        printf("%d\n", solve(x));
    }
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/