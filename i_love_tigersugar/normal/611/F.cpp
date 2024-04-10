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
        if (x > y) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
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

const long long INF = (long long)1e18 + 7LL;
const int MOD = (int)1e9 + 7;
struct Number {
    int value;

    Number(long long x = 0) {
        value = x % MOD + MOD;
        if (value >= MOD) value -= MOD;
    }

    Number operator + (const Number &x) const {
        Number res;
        res.value = value + x.value;
        if (res.value >= MOD) res.value -= MOD;
        assert(res.value >= 0 && res.value < MOD);
        return res;
    }

    Number& operator += (const Number &x) {
        value += x.value;
        if (value >= MOD) value -= MOD;
        assert(value >= 0 && value < MOD);
        return *this;
    }

    Number operator - (const Number &x) const {
        Number res;
        res.value = value - x.value;
        if (res.value < 0) res.value += MOD;
        assert(res.value >= 0 && res.value < MOD);
        return res;
    }

    Number operator * (const Number &x) const {
        Number res;
        res.value = 1LL * value * x.value % MOD;
        assert(res.value >= 0 && res.value < MOD);
        return res;
    }

    int cmp(const Number &x) const {
        return (value > x.value) - (value < x.value);
    }

    #define DEFINE_OPERATOR(o) bool operator o (const Number &x) const { return cmp(x) o 0; }
    DEFINE_OPERATOR(==) DEFINE_OPERATOR(!=)
    DEFINE_OPERATOR(>=) DEFINE_OPERATOR(<=)
    DEFINE_OPERATOR(>)  DEFINE_OPERATOR(<)
    #undef DEFINE_OPERATOR
};

ostream& operator << (ostream &os, const Number &x) {
    return os << x.value;
}

Number inverse(Number x) {
    Number res = 1, mul = x;
    int k = MOD - 2;
    while (k > 0) {
        if (k & 1) res = res * mul;
        mul = mul * mul;
        k >>= 1;
    }
    return res;
}
Number INV_2 = inverse(2);
Number INV_6 = inverse(6);

Number sum(Number n) {
    return n * (n + 1) * INV_2;
}
Number sumSquare(Number n) {
    return n * (n + 1) * (n * 2 + 1) * INV_6;
}

// sum (a + b*t)(c + d*t) with t from 1 to n
Number getSum(Number n, Number a, Number b, Number c, Number d) {
    return a * c * n + (a * d + b * c) * sum(n) + b * d * sumSquare(n);
}

void update(char step, int &x, int &y) {
    if (step == 'U') y++;
    else if (step == 'D') y--;
    else if (step == 'L') x--;
    else if (step == 'R') x++;
    else assert(false);
}

int solve(const string &steps, long long width, long long height) {
    int roundDx = 0, roundDy = 0;
    int maxUp = 0, maxDown = 0, maxLeft = 0, maxRight = 0;
    Number res;

    FOR(i, 1, steps.size()) {
        update(steps[i - 1], roundDx, roundDy);
        int curWidth = maxLeft + maxRight + 1;
        int curHeight = maxUp + maxDown + 1;
        if (maximize(maxUp, roundDy) || maximize(maxDown, -roundDy)) {
            curHeight++;
            if (curWidth <= width && curHeight <= height + 1)
                res += Number(width - curWidth + 1) * i;
        }
        if (maximize(maxLeft, -roundDx) || maximize(maxRight, roundDx)) {
            curWidth++;
            if (curHeight <= height && curWidth <= width + 1)
                res += Number(height - curHeight + 1) * i;
        }
    }

    if (roundDx == 0 && roundDy == 0 && maxRight + maxLeft + 1 <= width && maxUp + maxDown + 1 <= height) return -1;
    if (roundDx == 0 && roundDy == 0) return res.value;

    int curX = roundDx, curY = roundDy;
    roundDx = Abs(roundDx); roundDy = Abs(roundDy);

    FOR(i, 1, steps.size()) {
        update(steps[i - 1], curX, curY);
        int curWidth = maxLeft + maxRight + 1;
        int curHeight = maxUp + maxDown + 1;
        if (maximize(maxUp, curY) || maximize(maxDown, -curY)) {
            curHeight++;
            if (curWidth <= width && curHeight <= height + 1) {
                long long maxRound = INF;
                // curWidth + (round - 1) * roundDx <= width
                if (roundDx > 0) minimize(maxRound, (width - curWidth + roundDx) / roundDx);
                // curHeight + (round - 1) * roundDy <= height + 1
                if (roundDy > 0) minimize(maxRound, (height + 1 - curHeight + roundDy) / roundDy);
                if (maxRound > 0) {
                    // numChoices: width - curWidth - (round - 1) * roundDx + 1
                    // time: round * steps.size() + i
                    res += getSum(maxRound, width - curWidth + roundDx + 1, -roundDx, i, (int)steps.size());
                }
            }
        }

        if (maximize(maxLeft, -curX) || maximize(maxRight, curX)) {
            curWidth++;
            if (curWidth <= width + 1 && curHeight <= height) {
                long long maxRound = INF;
                // curHeight + (round - 1) * roundDy <= height
                if (roundDy > 0) minimize(maxRound, (height - curHeight + roundDy) / roundDy);
                // curWidth + (round - 1) * roundDx <= width + 1
                if (roundDx > 0) minimize(maxRound, (width + 1 - curWidth + roundDx) / roundDx);
                if (maxRound > 0) {
                    // numChoices: height - curHeight - (round - 1) * roundDy + 1
                    // time: round * steps.size() + i
                    res += getSum(maxRound, height - curHeight + roundDy + 1, -roundDy, i, (int)steps.size());
                }
            }
        }
    }

    return res.value;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, h, w; string steps;
    while ((cin >> n >> h >> w) && n > 0 && h > 0 && w > 0) {
        cin >> steps;
        cout << solve(steps, w, h) << endl;
    }
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/