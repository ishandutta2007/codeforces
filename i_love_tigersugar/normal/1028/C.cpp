#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
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

struct Rectangle {
    int bot, top, left, right;

    Rectangle(int bot = 0, int left = 0, int top = 0, int right = 0) {
        this->bot = bot;
        this->top = top;
        this->left = left;
        this->right = right;
    }

    bool isEmpty(void) const {
        return bot > top || left > right;
    }

    Rectangle join(const Rectangle &r) const {
        return Rectangle(max(bot, r.bot), max(left, r.left), min(top, r.top), min(right, r.right));
    }

    void printRandomPoint(void) const {
        if (isEmpty()) return;
        printf("%d %d\n", top, right);
        exit(EXIT_SUCCESS);
    }
};

#define MAX   1000100

Rectangle recs[MAX], prefix[MAX], suffix[MAX];
int n;

void process(void) {
    scanf("%d", &n);
    FOR(i, 1, n) {
        int bot, left, top, right; scanf("%d%d%d%d", &bot, &left, &top, &right);
        recs[i] = Rectangle(bot, left, top, right);
    }

    prefix[1] = recs[1];
    FOR(i, 2, n) prefix[i] = prefix[i - 1].join(recs[i]);
    suffix[n] = recs[n];
    FORD(i, n - 1, 1) suffix[i] = suffix[i + 1].join(recs[i]);
    prefix[n - 1].printRandomPoint();
    suffix[2].printRandomPoint();
    FOR(i, 2, n - 1) prefix[i - 1].join(suffix[i + 1]).printRandomPoint();
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/