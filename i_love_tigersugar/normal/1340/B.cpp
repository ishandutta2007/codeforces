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

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

const string DIGITS[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
const int LENGTH = 7;

#define MAX   2020

int numDigit, numStick;
bool possible[MAX][MAX];
int digits[MAX], state[MAX];

int getMask(const string &s) {
    assert(s.size() == LENGTH);
    int mask = 0;
    REP(i, LENGTH) if (s[i] == '1') mask |= MASK(i);
    return mask;
}

void init(void) {
    cin >> numDigit >> numStick;
    FOR(i, 1, numDigit) {
        string tmp; cin >> tmp;
        state[numDigit - i + 1] = getMask(tmp);
    }

    REP(i, 10) digits[i] = getMask(DIGITS[i]);
}

bool ok(int pos, int dig) {
    return (state[pos] & ~digits[dig]) == 0;
}

void process(void) {
    possible[0][0] = true;
    REP(i, numDigit) REP(j, numStick + 1) if (possible[i][j])
        REP(k, 10) if (ok(i + 1, k)) {
            int newJ = j + __builtin_popcount(digits[k]) - __builtin_popcount(state[i + 1]);
            if (newJ <= numStick) possible[i + 1][newJ] = true;
        }

    if (!possible[numDigit][numStick]) {
        printf("-1\n");
        return;
    }

    int j = numStick;
    FORD(i, numDigit, 1) {
        bool ahihi = false;
        FORD(k, 9, 0) if (ok(i, k)) {
            int prevJ = j - (__builtin_popcount(digits[k]) - __builtin_popcount(state[i]));
            if (prevJ >= 0 && possible[i - 1][prevJ]) {
                printf("%d", k);
                j = prevJ;
                ahihi = true;
                break;
            }
        }
        assert(ahihi);
    }
    printf("\n");
}

int main(void) {
    init();
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/