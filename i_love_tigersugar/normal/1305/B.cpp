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

#define MAX   100100
char input[MAX];
int n, cntOpen[MAX], cntClose[MAX];

void process(void) {
    scanf("%s", input + 1);
    n = strlen(input + 1);

    FOR(i, 1, n) cntOpen[i] = cntOpen[i - 1] + (input[i] == '(');
    FORD(i, n, 1) cntClose[i] = cntClose[i + 1] + (input[i] == ')');

    FOR(i, 0, n) if (cntOpen[i] == 0 && cntClose[i + 1] == 0) {
        cout << 0 << endl;
        return;
    }

    FOR(i, 0, n) if (cntOpen[i] == cntClose[i + 1]) {
        vector<int> indices;
        FOR(j, 1, i) if (input[j] == '(') indices.push_back(j);
        FOR(j, i + 1, n) if (input[j] == ')') indices.push_back(j);
        cout << 1 << "\n" << indices.size() << endl;
        FORE(jt, indices) cout << *jt << " "; cout << endl;
        return;
    }
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/