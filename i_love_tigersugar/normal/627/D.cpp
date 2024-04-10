#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
const int INF = (int)1e6 + 7;
template<class X, class Y>
    void minimize(X &x,const Y &y) {
        if (x > y) x = y;
    }
template<class X, class Y>
    void maximize(X &x,const Y &y) {
        if (x < y) x = y;
    }

vector<int> adj[MAX];
int n, req, curLim, val[MAX], numChild[MAX], numGreat[MAX];

void loadTree(void) {
    scanf("%d%d", &n, &req);
    FOR(i, 1, n) scanf("%d", &val[i]);
    REP(love, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void preDFS(int u, int p) {
    numChild[u] = 1;
    FORE(it, adj[u]) if (*it != p) {
        int v = *it;
        preDFS(v, u);
        numChild[u] += numChild[v];
    }
    if (val[u] < curLim) numGreat[u] = 0;
    else {
        int tmp = 0;
        numGreat[u] = 1;
        FORE(it, adj[u]) if (*it != p) {
            int v = *it;
            if (numGreat[v] == numChild[v]) numGreat[u] += numGreat[v];
            else maximize(tmp, numGreat[v]);
        }
        numGreat[u] += tmp;
    }
}

void update(int &best, int &secondBest, int value) {
    if (value > best) {
        secondBest = best;
        best = value;
    } else maximize(secondBest, value);
}

int calcDFS(int u, int p, int parGreat, int parChild) {
    int sumFull = 0;

    int best = -1, secondBest = -1;

    if (parGreat == parChild) sumFull += parGreat;
    else if (parGreat > 0) update(best, secondBest, parGreat);
    FORE(it, adj[u]) if (*it != p) {
        int v = *it;
        if (numGreat[v] == numChild[v]) sumFull += numGreat[v];
        else if (numGreat[v] > 0) update(best, secondBest, numGreat[v]);
    }
    int res = 0;
    if (val[u] >= curLim) {
        int tmp = sumFull + 1;
        if (best >= 0) tmp += best;
        res = tmp;
    }
    FORE(it, adj[u]) if (*it != p) {
        int v = *it;
        int tmpGreat;
        int tmpChild = n - numChild[v];
        if (val[u] < curLim) tmpGreat = 0;
        else if (numGreat[v] == numChild[v]) {
            tmpGreat = sumFull + 1 - numGreat[v];
            if (best >= 0) tmpGreat += best;
        } else if (numGreat[v] > 0) {
            tmpGreat = sumFull + 1;
            int toAdd = best == numGreat[v] ? secondBest : best;
            if (toAdd >= 0) tmpGreat += toAdd;
        } else {
            tmpGreat = sumFull + 1;
            if (best >= 0) tmpGreat += best;
        }
        maximize(res, calcDFS(v, u, tmpGreat, tmpChild));
    }
    return (res);
}

bool ok(int x) {
    memset(numChild, 0, sizeof numChild);
    memset(numGreat, 0, sizeof numGreat);
    curLim = x;
    preDFS(1, -1);
    return (max(numGreat[1], calcDFS(1, -1, 0, 0)) >= req);
}

int process(void) {
    int L = 0;
    int R = INF;
    while (true) {
        if (L == R) return (R);
        if (R - L == 1) return (ok(R) ? R : L);
        int M = (L + R) >> 1;
        if (ok(M)) L = M; else R = M - 1;
    }
}

int main(void) {
    loadTree();
    printf("%d\n", process());
    return 0;
}