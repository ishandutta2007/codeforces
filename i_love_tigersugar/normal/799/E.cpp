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

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

const long long INF = (long long)1e18 + 7LL;

class SegmentTree {
private:
    vector<long long> sum;
    vector<int> cnt;
    int n;

public:
    SegmentTree(int n = 0) {
        this->n = n;
        sum.assign(4 * n + 7, 0);
        cnt.assign(4 * n + 7, 0);
    }

    void insert(int pos, int value) {
        int i = 1, l = 1, r = n;

        while (true) {
            sum[i] += value; cnt[i]++;
            if (l == r) return;

            int m = (l + r) >> 1;
            if (pos > m) {
                i = 2 * i + 1; l = m + 1;
            } else {
                i = 2 * i; r = m;
            }
        }
    }

    long long getSum(int need) const {
        if (need > cnt[1]) return INF;
        int i = 1, l = 1, r = n;
        long long res = 0;

        while (true) {
            if (l == r) {
                if (cnt[i] > 0) res += (sum[i] / cnt[i]) * need;
                return res;
            }

            int m = (l + r) >> 1;
            if (need >= cnt[2 * i]) {
                res += sum[2 * i];
                need -= cnt[2 * i];
                i = 2 * i + 1; l = m + 1;
            } else {
                i = 2 * i; r = m;
            }
        }
    }
};

#define MAX   200200

vector<int> values, both, onlyA, onlyB, none;
int cost[MAX], n, need, needLike;
bool likeA[MAX], likeB[MAX];

void init(void) {
    scanf("%d%d%d", &n, &need, &needLike);
    FOR(i, 1, n) scanf("%d", &cost[i]);

    int t; scanf("%d", &t);
    REP(pmp, t) {
        int x; scanf("%d", &x); likeA[x] = true;
    }

    scanf("%d", &t);
    REP(pmp, t) {
        int x; scanf("%d", &x); likeB[x] = true;
    }
}

void prepare(void) {
    FOR(i, 1, n) values.push_back(cost[i]);
    sort(ALL(values)); values.resize(unique(ALL(values)) - values.begin());

    FOR(i, 1, n) {
        if (likeA[i]) {
            if (likeB[i]) both.push_back(cost[i]);
            else onlyA.push_back(cost[i]);
        } else {
            if (likeB[i]) onlyB.push_back(cost[i]);
            else none.push_back(cost[i]);
        }
    }

    sort(ALL(both));
    sort(ALL(onlyA));
    sort(ALL(onlyB));
    sort(ALL(none));
}

#define POS(x) (lower_bound(ALL(values), x) - values.begin() + 1)

void process(void) {
    long long costBoth = 0, costOnlyA = 0, costOnlyB = 0, best = INF;

    SegmentTree myit(values.size());
    FORE(it, none) myit.insert(POS(*it), *it);

    REP(numBoth, both.size() + 1) {
        int numOnly = max(needLike - numBoth, 0);

        bool ok = numOnly <= onlyA.size() && numOnly <= onlyB.size() && numBoth + 2 * numOnly <= need;

        if (numBoth == 0) {
            REP(i, onlyA.size()) {
                if (i < numOnly) costOnlyA += onlyA[i];
                else myit.insert(POS(onlyA[i]), onlyA[i]);
            }

            REP(i, onlyB.size()) {
                if (i < numOnly) costOnlyB += onlyB[i];
                else myit.insert(POS(onlyB[i]), onlyB[i]);
            }
        } else {
            costBoth += both[numBoth - 1];

            int prevOnly = max(needLike - (numBoth - 1), 0);
            int prevA = min(prevOnly, (int)onlyA.size());
            int prevB = min(prevOnly, (int)onlyB.size());

            if (numOnly < prevA) {
                costOnlyA -= onlyA[numOnly];
                myit.insert(POS(onlyA[numOnly]), onlyA[numOnly]);
            }
            if (numOnly < prevB) {
                costOnlyB -= onlyB[numOnly];
                myit.insert(POS(onlyB[numOnly]), onlyB[numOnly]);
            }
        }

        //printf("AT %d both = %lld, A = %lld, B = %lld\n", numBoth, costBoth, costOnlyA, costOnlyB);

        int numOther = need - (numBoth + 2 * numOnly);
        if (ok) minimize(best, costBoth + costOnlyA + costOnlyB + myit.getSum(numOther));
    }

    cout << (best < INF ? best : -1) << endl;
}

int main(void) {
    init();
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/