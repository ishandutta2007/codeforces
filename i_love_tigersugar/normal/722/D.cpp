#include<bits/stdc++.h>
#define MAX   100100
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
const int NBIT = 30;
struct Node {
    bool used;
    int remain, numReq;
    Node* child[2];
    Node() {
        used = false;
        remain = numReq = 0;
        REP(i, 2) child[i] = NULL;
    }
    void clearData(void) {
        REP(i, 2) if (child[i] != NULL) child[i]->clearData();
        used = false;
        remain = numReq = 0;
    }
    void calcRemain(bool canUse) {
        remain = numReq;
        REP(i, 2) if (child[i] != NULL) {
            child[i]->calcRemain(true);
            remain += child[i]->remain;
        }
        if (canUse) {
            used = remain > 0;
            if (remain > 0) remain--;
        } else used = false;
    }
    void trace(int value) {
        REP(i, 2) if (child[i] != NULL) child[i]->trace(2 * value + i);
        if (used) printf("%d ", value);
    }
};
const int INF = (int) 1e9 + 7;
int a[MAX], n;
Node *root;
void addNumber(int x) {
    bool leading = true;
    Node *p = root;
    FORD(i, NBIT - 1, 0) {
        int j = BIT(x, i);
        if (leading && j == 0) continue;
        leading = false;
        if (p->child[j] == NULL) p->child[j] = new Node();
        p=p->child[j];
    }
}
void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    root = new Node();
    FOR(i, 1, n) addNumber(a[i]);
}
void getReq(int x, int lim) {
    int val = 0;
    bool leading = true;
    Node *p = root;
    FORD(i, NBIT - 1, 0) {
        int j = BIT(x, i);
        if (leading && j == 0) continue;
        leading = false;
        val = val * 2 + j;
        if (val > lim) break;
        assert(p->child[j] != NULL);
        p=p->child[j];
    }
    p->numReq++;
}
bool ok(int lim) {
    root->clearData();
    FOR(i, 1, n) getReq(a[i], lim);
    root->calcRemain(false);
    return root->remain == 0;
}
int findResult(void) {
    int L = 1;
    int R = INF;
    while (true) {
        if (L == R) return (L);
        if (R - L == 1) return (ok(L) ? L : R);
        int M = (L + R) >> 1;
        if (ok(M)) R = M; else L = M + 1;
    }
}
void trace(void) {
    assert(ok(findResult()));
    root->trace(0);
    printf("\n");
}
int main(void) {
    init();
    trace();
    return 0;
}