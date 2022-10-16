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

struct Node {
    int cnt;
    Node *child[2];

    Node(int x = 0) {
        cnt = x;
        REP(i, 2) child[i] = NULL;
    }
};

struct Query {
    #define INSERT   1
    #define REMOVE   2
    #define ASK   3

    int type, value, limit;

    Query() {
        type = value = limit = 0;
    }

    void input(void) {
        scanf("%d%d", &type, &value);
        if (type == ASK) scanf("%d", &limit);
    }
};

#define MAX   100100
#define NUM_BIT   30

Query queries[MAX];
int numQuery;
Node *root;

void addNumber(int x) {
    Node *p = root;
    FORD(i, NUM_BIT - 1, 0) {
        int j = BIT(x, i);
        if (p->child[j] == NULL) p->child[j] = new Node();
        p = p->child[j];
    }
}

void init(void) {
    scanf("%d", &numQuery);
    REP(i, numQuery) queries[i].input();

    root = new Node();
    REP(i, numQuery) {
        if (queries[i].type == INSERT) addNumber(queries[i].value);
        if (queries[i].type == ASK) addNumber(queries[i].value ^ queries[i].limit);
    }
}

void update(int x, int v) {
    Node *p = root;

    FORD(i, NUM_BIT - 1, 0) {
        int j = BIT(x, i);
        assert(p->child[j] != NULL);
        p = p->child[j];
        p->cnt += v;
    }
}

int answer(int value, int limit) {
    Node *p = root;
    int res = 0;

    FORD(i, NUM_BIT - 1, 0) {
        assert(p != NULL);
        int j = BIT(value ^ limit, i);

        if (BIT(limit, i) && p->child[j ^ 1] != NULL) res += p->child[j ^ 1]->cnt;
        p = p->child[j];
    }

    return res;
}

void process(void) {
    REP(i, numQuery) {
        if (queries[i].type != ASK) update(queries[i].value, queries[i].type == INSERT ? 1 : -1);
        else printf("%d\n", answer(queries[i].value, queries[i].limit));
    }
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/