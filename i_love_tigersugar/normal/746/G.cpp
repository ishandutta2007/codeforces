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

#define MAX   200200

int n, dis, needLeaf, nextNode, curNonLeaf;
set<int> leaves[MAX], nonLeaves[MAX];
int high[MAX], par[MAX], needHigh[MAX];

void noAnswer(void) {
    printf("-1\n");
    exit(0);
}

int createNode(int parNode) {
    int node = nextNode++;
    if (node > n) noAnswer();
    par[node] = parNode;
    high[node] = high[parNode] + 1;
    if (--needHigh[high[node]] < 0) noAnswer();
    leaves[high[node]].insert(node);

    set<int> &tmp = leaves[high[parNode]];
    if (tmp.find(parNode) != tmp.end()) {
        curNonLeaf++;
        tmp.erase(parNode);
        nonLeaves[high[parNode]].insert(parNode);
    }
    return node;
}
void process(void) {
    scanf("%d%d%d", &n, &dis, &needLeaf);
    FOR(i, 1, dis) scanf("%d", &needHigh[i]);

    leaves[0].insert(1);
    nextNode = 2;
    FOR(i, 1, dis) createNode(i);

    FOR(i, 1, dis) while (needHigh[i] > 0) {
        int par;
        if (curNonLeaf < n - needLeaf && !leaves[i - 1].empty()) par = *leaves[i - 1].begin();
        else par = *nonLeaves[i - 1].begin();
        createNode(par);
    }

    if (nextNode != n + 1 || curNonLeaf != n - needLeaf) noAnswer();

    printf("%d\n", n);
    FOR(i, 2, n) printf("%d %d\n", i, par[i]);
    printf("\n");
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/