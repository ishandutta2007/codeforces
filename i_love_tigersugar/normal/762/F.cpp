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

const int MOD = (int)1e9 + 7;
void add(int &x, const int &y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

class Tree {
    private:
    vector<vector<int> > adj, children;
    vector<vector<int> > numWay;
    int n;

    Tree *small;

    void dfs(int u, int par) {
        FORE(it, adj[u]) if (*it != par) {
            children[u].push_back(*it);
            dfs(*it, u);
        }
    }

    void dfsTree(int root) {
        FOR(i, 1, n) children[i].clear();
        dfs(root, -1);
    }

    int getNumMatch(int u, int v) {
        if (numWay[u][v] >= 0) return numWay[u][v];
        if (small->children[v].empty()) return numWay[u][v] = 1;
        if (small->children[v].size() > children[u].size()) return numWay[u][v] = 0;

        int numChild = small->children[v].size();

        vector<int> tmp(MASK(numChild), 0);
        tmp[0] = 1;

        FORE(it, children[u]) {
            vector<int> newDP = tmp;
            REP(i, MASK(numChild)) REP(j, numChild) if (!BIT(i, j))
                add(newDP[i | MASK(j)], 1LL * tmp[i] * getNumMatch(*it, small->children[v][j]) % MOD);

            tmp = newDP;
        }

        return numWay[u][v] = tmp[MASK(numChild) - 1];
    }

    int countMatch(int root, int smallRoot) {
        FOR(i, 1, n) FOR(j, 1, small->n) numWay[i][j] = -1;
        dfsTree(root);

        return getNumMatch(root, smallRoot);
    }

    int maxAdjNode(void) const {
        int res = 1;
        FOR(i, 1, n) if (adj[i].size() > adj[res].size()) res = i;
        return res;
    }

    public:
    Tree(int n = 0, vector<int> adj[] = NULL) {
        this->n = n;
        if (n == 0) return;
        this->adj.assign(n + 1, vector<int>());
        FOR(i, 1, n) this->adj[i] = adj[i];
        this->children.assign(n + 1, vector<int>());
        small = NULL;
    }

    int countMatch(Tree &small) {
        this->small = &small;
        int smallRoot = small.maxAdjNode();

        small.dfsTree(smallRoot);
        numWay.assign(n + 3, vector<int>(small.n + 3, 0));

        int res = 0;
        FOR(i, 1, n) res = (res + countMatch(i, smallRoot)) % MOD;
        return res;
    }

};

#define MAX_BIG   1111
#define MAX_SMALL   22

vector<int> bigAdj[MAX_BIG], smallAdj[MAX_SMALL];
int numBig, numSmall;

void readTree(int &n, vector<int> adj[]) {
    scanf("%d", &n);
    REP(love, n - 1) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void loadTree(void) {
    readTree(numBig, bigAdj);
    readTree(numSmall, smallAdj);
}

int inverse(int x) {
    int res = 1;
    int mul = x;
    int k = MOD - 2;

    while (k > 0) {
        if (k & 1) res = 1LL * res * mul % MOD;
        mul = 1LL * mul * mul % MOD;
        k >>= 1;
    }

    assert(1LL * res * x % MOD == 1);
    return res;
}
int process(void) {
    Tree bigTree(numBig, bigAdj);
    Tree smallTree(numSmall, smallAdj);
    Tree smallClone = smallTree;

    return 1LL * bigTree.countMatch(smallTree) * inverse(smallClone.countMatch(smallTree)) % MOD;
}

int main(void) {
    loadTree();
    cout << process() << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/