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

class FenwickTree {
private:
    vector<int> v;
    int n;

public:
    FenwickTree(int n = 0) {
        this->n = n;
        if (n > 0) v.assign(n + 7, 0);
    }

    void update(int x, int d) {
        for (; x <= n; x += x & -x) v[x] += d;
    }

    int get(int x) const {
        int res = 0;
        for (; x >= 1; x &= x - 1) res += v[x];
        return res;
    }

    int getSum(int l, int r) const {
        return l == 1 ? get(r) : get(r) - get(l - 1);
    }
};

struct Block {
    int l, r;
    FenwickTree bit;

    Block(int l = 0, int r = 0, int n = 0) {
        this->l = l; this->r = r;
        bit = FenwickTree(n);
    }

    int size(void) const {
        return r - l + 1;
    }

    void change(int prev, int cur) {
        bit.update(prev, -1);
        bit.update(cur, 1);
    }

    int count(int l, int r) const {
        return l > r ? 0 : bit.getSum(l, r);
    }
};

#define MAX   200200

int perm[MAX], n, q, blockSize, numBlock;
int blockID[MAX];
Block blocks[MAX];
long long numInverse;

void init(void) {
    scanf("%d%d", &n, &q);
    FOR(i, 1, n) perm[i] = i;

    int logN = 0;
    while (MASK(logN) <= n) logN++;
    while (1LL * blockSize * blockSize < n * logN) blockSize++;

    FOR(i, 1, n) {
        if (i == 1 || blocks[numBlock].size() >= blockSize) {
            blocks[++numBlock] = Block(i, i, n);
            blockID[i] = numBlock;
        } else {
            blocks[numBlock].r++;
            blockID[i] = numBlock;
        }
    }

    FOR(i, 1, n) blocks[blockID[i]].bit.update(i, 1);
}

int countValue(int l, int r, int minValue, int maxValue) {
    if (l > r || minValue > maxValue) return 0;

    int res = 0;
    if (blockID[l] == blockID[r]) {
        FOR(i, l, r) if (minValue <= perm[i] && perm[i] <= maxValue) res++;
        return res;
    }

    FOR(i, blockID[l] + 1, blockID[r] - 1) res += blocks[i].count(minValue, maxValue);
    FOR(i, l, blocks[blockID[l]].r) if (minValue <= perm[i] && perm[i] <= maxValue) res++;
    FOR(i, blocks[blockID[r]].l, r) if (minValue <= perm[i] && perm[i] <= maxValue) res++;
    return res;
}

void query(int l, int r) {
    if (l == r) return;
    if (l > r) return query(r, l);

    if (perm[l] < perm[r]) {
        int tmp = countValue(l + 1, r - 1, perm[l] + 1, perm[r] - 1);
        numInverse += 2 * tmp + 1;
    } else {
        int tmp = countValue(l + 1, r - 1, perm[r] + 1, perm[l] - 1);
        numInverse -= 2 * tmp + 1;
    }

    blocks[blockID[l]].change(perm[l], perm[r]);
    blocks[blockID[r]].change(perm[r], perm[l]);
    swap(perm[l], perm[r]);
}

void process(void) {
    REP(love, q) {
        int l, r; scanf("%d%d", &l, &r);
        query(l, r);
        cout << numInverse << "\n";
    }
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/