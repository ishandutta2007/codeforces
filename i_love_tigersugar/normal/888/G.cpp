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

#define NUM_BIT   30

struct Node {
    Node *child[2];
    vector<int> *numbers;

    Node() {
        REP(i, 2) child[i] = NULL;
        numbers = NULL;
    }

    int findEdge(int level, int dir, int value) const {

        Node *p = child[dir ^ 1];
        assert(p != NULL);

        int res = MASK(level - 1);
        FORD(bit, level - 2, 0) {
            int j = BIT(value, bit);
            bool ok = false;
            REP(i, 2) if (p->child[j ^ i] != NULL) {
                p = p->child[j ^ i];
                res |= i << bit;
                ok = true;
                break;
            }
            assert(ok);
        }

        //printf("FOR %d level %d dir %d is %d\n", value, level, dir, res);
        return res;
    }

    long long calcCost(int level) {
        if (level == 0) return 0;
        if (child[0] == NULL && child[1] == NULL) return 0;

        if (child[0] == NULL) {
            long long res = child[1]->calcCost(level - 1);
            numbers = child[1]->numbers;
            return res;
        }

        if (child[1] == NULL) {
            long long res = child[0]->calcCost(level - 1);
            numbers = child[0]->numbers;
            return res;
        }

        long long res = child[0]->calcCost(level - 1) + child[1]->calcCost(level - 1);
        int small = child[0]->numbers->size() < child[1]->numbers->size() ? 0 : 1;

        long long bestEdge = INF;
        FORE(it, *child[small]->numbers) minimize(bestEdge, findEdge(level, small, *it));

        numbers = child[small ^ 1]->numbers;
        FORE(it, *child[small]->numbers) numbers->push_back(*it);

        return res + bestEdge;
    }
};

#define MAX   200200

Node *root;

void addNumber(int x) {
    Node *p = root;
    FORD(i, NUM_BIT - 1, 0) {
        int j = BIT(x, i);
        if (p->child[j] == NULL) p->child[j] = new Node();
        p = p->child[j];
    }

    if (p->numbers == NULL) p->numbers = new vector<int>();
    p->numbers->push_back(x);
}

void process(void) {
    root = new Node();

    int n; cin >> n;
    REP(love, n) {
        int x; cin >> x;
        addNumber(x);
    }

    cout << root->calcCost(NUM_BIT) << endl;
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/