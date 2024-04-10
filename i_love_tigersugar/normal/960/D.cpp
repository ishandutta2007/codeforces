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
    void minimize(X &x, const Y &y) {
        if (x > y) x = y;
    }
template<class X, class Y>
    void maximize(X &x, const Y &y) {
        if (x < y) x = y;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

const int MAX_LEVEL = 60;
long long shift[MAX_LEVEL * 3];

int getLevel(long long node) {
    REP(i, MAX_LEVEL + 1) if (MASK(i) <= node && node < MASK(i + 1)) return i;
    assert(false);
}

long long getNumNode(int level) {
    return MASK(level);
}

long long getRealValue(long long node) {
    int level = getLevel(node);
    long long numNode = getNumNode(level);
    node -= numNode;
    return numNode + (node - shift[level] + numNode) % numNode;
}

long long getRealNodeID(long long value) {
    int level = getLevel(value);
    long long numNode = getNumNode(level);
    value -= numNode;
    return numNode + (value + shift[level]) % numNode;
}

vector<long long> getPath(long long node) {
    vector<long long> res;
    while (node > 0) {
        res.push_back(getRealValue(node));
        node >>= 1;
    }
    return res;
}

void shiftValue(long long value, long long dist) {
    int level = getLevel(value);
    long long numNode = getNumNode(level);
    dist = (dist % numNode + numNode) % numNode;
    shift[level] = (shift[level] + dist) % numNode;
}

void shiftSubtree(long long value, long long dist) {
    int level = getLevel(value);
    long long numNode = getNumNode(level);
    dist = (dist % numNode + numNode) % numNode;
    FOR(i, level, MAX_LEVEL) {
        shift[i] = (shift[i] + dist) % numNode;
        dist <<= 1;
        numNode <<= 1;
    }
}

void process(void) {
    int numQuery; cin >> numQuery;
    REP(aye, numQuery) {
        int type;
        long long value, range;
        cin >> type >> value;
        if (type == 3) {
            vector<long long> path = getPath(getRealNodeID(value));
            FORE(it, path) cout << *it << " ";
            cout << "\n";
        } else {
            cin >> range;
            if (type == 1) shiftValue(value, range);
            else shiftSubtree(value, range);
        }
    }
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/