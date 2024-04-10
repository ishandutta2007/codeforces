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

#define MAX   5050

const char YES[] = "YES";
const char NO[] = "NO";

vector<int> children[MAX];
int par[MAX], nodes[5], numLeaf[MAX];
int n;
bool branchPos[5][MAX];
vector<int> path[MAX];

bool tmpDP[MAX][MAX];
bool markDist[MAX], mark[MAX];

vector<int> subsetValue(const vector<int> &v) {
    int n = v.size();
    int sum = 0;
    FORE(it, v) sum += *it;

    REP(i, n + 1) REP(j, sum + 1) tmpDP[i][j] = false;

    tmpDP[0][0] = true;
    REP(i, n) REP(j, sum + 1) if (tmpDP[i][j]) {
        tmpDP[i + 1][j] = true;
        tmpDP[i + 1][j + v[i]] = true;
    }

    vector<int> res;
    REP(i, sum + 1) if (tmpDP[n][i]) res.push_back(i);
    return res;
}

void loadTree(void) {
    scanf("%d", &n);
    REP(i, 4) scanf("%d", &nodes[i]);
    FOR(i, 2, n) {
        int p; scanf("%d", &p);
        par[i] = p;
        children[p].push_back(i);
    }
}

void dfs(int u) {
    if (children[u].empty()) {
        numLeaf[u] = 1;
        return;
    }

    FORE(it, children[u]) {
        dfs(*it);
        numLeaf[u] += numLeaf[*it];
    }
}

void calcBranchPos(int u, vector<int> &path, bool pos[]) {
    int cur = u;
    while (cur > 1) {
        path.push_back(cur);
        cur = par[cur];
    }

    reverse(ALL(path));
    vector<int> values;
    REP(i, (int)path.size() - 1) FORE(it, children[path[i]]) if (*it != path[i + 1])
        values.push_back(numLeaf[*it]);

    vector<int> tmp = subsetValue(values);
    FORE(it, tmp) pos[*it + 1] = true;

//    printf("from leave %d\n", u);
//    printf("Path: "); FORE(it, path) printf("%d ", *it); printf("\n");
//    printf("Pos: "); REP(i, MAX) if (pos[i]) printf("%d ", i); printf("\n");
}

bool check(int left, int mid, int right, int exclude) {
    set<int> s;
    s.insert(path[left].front());
    s.insert(path[mid].front());
    s.insert(path[right].front());
    s.insert(path[exclude].front());

    vector<int> branches;
    FORE(it, children[1]) if (s.find(*it) == s.end()) branches.push_back(numLeaf[*it]);

    vector<int> values = subsetValue(branches);
    FORE(it, values) *it += numLeaf[path[mid].front()];

//    printf("left = %d, right = %d, mid = %d, exclude = %d\n", nodes[left], nodes[right], nodes[mid], nodes[exclude]);
//    printf("Values: "); FORE(it, values) printf("%d ", *it); printf("\n");

    memset(mark, false, sizeof mark);
    memset(markDist, false, sizeof markDist);

    FOR(i, 1, numLeaf[path[left].front()]) if (branchPos[left][i])
        FOR(j, 1, numLeaf[path[right].front()]) if (branchPos[right][j])
            markDist[j + numLeaf[path[left].front()] - i] = true;

    FOR(i, 1, n) if (markDist[i]) FORE(it, values) mark[i + *it] = true;
    return numLeaf[1] % 2 == 0 && mark[numLeaf[1] / 2];
}

void process(void) {
    dfs(1);
    if (numLeaf[1] % 2 != 0) {
        printf("%s\n", NO);
        return;
    }

    REP(i, 4) calcBranchPos(nodes[i], path[i], branchPos[i]);

    if (!check(0, 2, 1, 3)) {
        printf("%s\n", NO);
        return;
    }

    if (!check(2, 0, 3, 1)) {
        printf("%s\n", NO);
        return;
    }

    printf("%s\n", YES);
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/