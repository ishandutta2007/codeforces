#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }

/* Author: Van Hanh Pham - skyvn97 */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   111

struct Move {
    int x, y, z;
    Move() {
        x = y = z = 0;
    }
    Move(int _x, int _y, int _z = -1) {
        x = _x; y = _y; z = _z;
    }

    bool operator == (const Move &m) const {
        return x == m.x && y == m.y && z == m.z;
    }
};

const vector<Move> NA(1, Move(-1, -1, -1));

int a[MAX], need[MAX], n;

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
}

vector<Move> choosePair(void) {
    priority_queue<pair<int, int> > q;
    int sumNeed = 0;
    int maxNeed = 0;
    FOR(i, 1, n) {
        sumNeed += need[i];
        maximize(maxNeed, need[i]);
    }

    if (2 * maxNeed > sumNeed) return NA;

    FOR(i, 1, n) if (need[i] > 0) q.push(make_pair(need[i], i));
    vector<Move> res;
    while (!q.empty()) {
        assert(q.size() > 1);
        pair<int, int> x = q.top(); q.pop();
        pair<int, int> y = q.top(); q.pop();
        x.fi--; y.fi--;
        res.push_back(Move(x.se, y.se));
        if (x.fi > 0) q.push(x);
        if (y.fi > 0) q.push(y);
    }
    return res;
}

vector<Move> removeTo(int goal) {
    if (goal == 0) {
        vector<Move> res;
        for (int i = 1; i < n; i += 2) REP(love, max(a[i], a[i + 1])) res.push_back(Move(i, i + 1));
        REP(love, max(a[n - 1], a[n])) res.push_back(Move(n - 1, n));
        return res;
    }
    FOR(i, 1, n) if (a[i] < goal) return NA;
    int sum = 0;
    FOR(i, 1, n) {
        need[i] = a[i] - goal;
        sum += need[i];
    }
    if (sum % 2 == 0) return choosePair();
    FOR(i, 1, n) if (need[i] > 0) FOR(j, i + 1, n) if (need[j] > 0) FOR(k, j + 1, n) if (need[k] > 0) {
        need[i]--; need[j]--; need[k]--;
        vector<Move> tmp = choosePair();
        if (tmp != NA) {
            tmp.push_back(Move(i, j, k));
            return tmp;
        }
        need[i]++; need[j]++; need[k]++;
    }
    return NA;
}

void process(void) {
    FORD(i, 222, 0) {
        vector<Move> res = removeTo(i);
        if (res != NA) {
            printf("%d\n%d\n", i, (int)res.size());
            FORE(it, res) {
                string tmp(n, '0');
                if (it->x > 0) tmp[it->x - 1] = '1';
                if (it->y > 0) tmp[it->y - 1] = '1';
                if (it->z > 0) tmp[it->z - 1] = '1';
                printf("%s\n", tmp.c_str());
            }
            return;
        }
    }
    assert(false);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/