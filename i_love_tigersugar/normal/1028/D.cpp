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

const string ADD = "ADD";
const string REMOVE = "ACCEPT";

#define BUY   -1
#define SELL   1
#define UNKNOWN   0

#define MAX   500500
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9 + 7;

int numQuery;
pair<string, int> queries[MAX];
map<int, int> status;

void foundError(void) {
    cout << 0 << endl;
    exit(EXIT_SUCCESS);
}

void setStatus(int key, int value) {
    int &cur = status[key];
    if (cur == value || cur == UNKNOWN) cur = value;
    else foundError();
}

int getStatus(int key) {
    return status[key];
}

int getMax(const set<int> &s) {
    __typeof(s.begin()) it = s.end(); it--;
    return *it;
}

int getMin(const set<int> &s) {
    __typeof(s.begin()) it = s.begin();
    return *it;
}

void checkSet(const set<int> &left, const set<int> &right) {
    if (left.empty() || right.empty()) return;
    if (getMax(left) < getMin(right)) return;
    foundError();
}

void process(void) {
    cin >> numQuery;
    FOR(i, 1, numQuery) cin >> queries[i].fi >> queries[i].se;
    FOR(i, 1, numQuery) status[queries[i].se] = UNKNOWN;

    set<int> types[3];
    FOR(i, 1, numQuery) {
        int key = queries[i].se;
        if (queries[i].fi == ADD) {
            if (!types[2].empty() && key > getMin(types[2]))
                setStatus(key, SELL);
            if (!types[0].empty() && key < getMax(types[0]))
                setStatus(key, BUY);
            types[getStatus(key) + 1].insert(key);
        } else {
            while (!types[1].empty()) {
                int tmp = getMin(types[1]);
                types[1].erase(tmp);
                if (tmp == key) continue;
                int newStatus = tmp < key ? BUY : SELL;
                setStatus(tmp, newStatus);
                types[newStatus + 1].insert(tmp);
            }
            types[getStatus(key) + 1].erase(key);
        }
        FOR(j, 0, 2) FOR(k, j + 1, 2) checkSet(types[j], types[k]);
    }

    int numFinalUnknown = types[1].size();

    REP(i, 3) types[i].clear();
    FOR(i, 1, numQuery) {
        int key = queries[i].se;
        int stt = getStatus(key);
        if (queries[i].fi == ADD) types[stt + 1].insert(key);
        else {
            if (stt == BUY && key != getMax(types[0])) foundError();
            if (stt == SELL && key != getMin(types[2])) foundError();
            types[stt + 1].erase(key);
        }
        FOR(j, 0, 2) FOR(k, j + 1, 2) checkSet(types[j], types[k]);
    }

    int numUnknown = 0;
    FORE(it, status) if (it->se == UNKNOWN) numUnknown++;
    int res = 1;
    REP(love, numUnknown - numFinalUnknown) res = res * 2 % MOD;
    cout << 1LL * res * (numFinalUnknown + 1) % MOD << endl;
}

int main(void) {
    ios::sync_with_stdio(false);
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/