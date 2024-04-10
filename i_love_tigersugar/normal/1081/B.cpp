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

const string YES = "Possible";
const string NO = "Impossible";

#define MAX   100100
int have[MAX], group[MAX];
int numGroup, numPerson;
map<int, vector<int>> pos;

void process(void) {
    scanf("%d", &numPerson);
    FOR(i, 1, numPerson) {
        int x; scanf("%d", &x);
        have[i] = numPerson - x;
        pos[have[i]].push_back(i);
    }

    FORE(it, pos) {
        int sz = it->fi;
        vector<int> &v = it->se;
        if (v.size() % sz != 0) {
            cout << NO << endl;
            return;
        }

        REP(j, v.size()) group[v[j]] = numGroup + 1 + j / sz;
        numGroup += v.size() / sz;
    }

    cout << YES << endl;
    FOR(i, 1, numPerson) printf("%d ", group[i]); printf("\n");
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/