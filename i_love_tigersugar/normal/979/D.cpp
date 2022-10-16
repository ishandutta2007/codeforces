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

struct Node {
    static const int INF = (int)1e9 + 7;

    int minValue;
    Node *child[2];

    Node() {
        REP(i, 2) child[i] = NULL;
        minValue = INF;
    }
};

#define MAX   100100
#define NUM_BIT   17

const int SQRT = 250;

vector<int> divs[MAX];
Node *root[SQRT + 3];

bool marked[MAX];

void prepare(void) {
    FOR(i, 1, MAX - 1)
        for (int j = i; j < MAX; j += i)
            divs[j].push_back(i);
    REP(i, SQRT + 1) root[i] = new Node();
}

void addNumber(Node *root, int value) {
    Node *p = root;
    minimize(p->minValue, value);
    FORD(i, NUM_BIT - 1, 0) {
        int j = BIT(value, i);
        if (p->child[j] == NULL) p->child[j] = new Node();
        p = p->child[j];
        minimize(p->minValue, value);
    }
}

void update(int v) {
    if (marked[v]) return;
    marked[v] = true;
    FORE(it, divs[v]) if (*it <= SQRT) addNumber(root[*it], v);
}

int bigK(int x, int k, int s) {
    int best = -1;
    for (int v = k; v <= s - x; v += k) if (marked[v]) {
        if (best < 0 || (x ^ v) > (x ^ best)) best = v;
    }
    return best;
}

int smallK(int x, int k, int s) {
    int value = 0;

    Node *p = root[k];
    FORD(i, NUM_BIT - 1, 0) {
        bool ok = false;
        FORD(b, 1, 0) {
            int need = BIT(x, i) ^ b;
            if (p->child[need] != NULL && x + p->child[need]->minValue <= s) {
                value |= need << i;
                p = p->child[need];
                ok = true;
                break;
            }
        }
        if (!ok) return -1;
    }
    return value;
}

int query(int x, int k, int s) {
    if (x % k != 0 || s < x) return -1;
    return k < SQRT ? smallK(x, k, s) : bigK(x, k, s);
}

void process(void) {
    int q; scanf("%d", &q);
    REP(aye, q) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int v; scanf("%d", &v);
            update(v);
        } else {
            int x, k, s; scanf("%d%d%d", &x, &k, &s);
            printf("%d\n", query(x, k, s));
        }
    }
}

int main(void) {
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/