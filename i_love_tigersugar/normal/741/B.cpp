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

class DisjointSet {
	private:
	vector<int> label; //label[x] stores the root of x if x is not root, otherwise it stores -(size of x's set).
	public:
	DisjointSet(){}
	DisjointSet(int n) {
		label.assign(n+7,-1); //label should contains at least n+1 elements, as x is 1-indexed.
		//At first, each node is a seperate set of size 1.
	}
	int find(int x) { //find the root of set which contains x.
		if (label[x]<0) return (x); //x is root iff label[x] is negative.
		label[x]=find(label[x]);
		return (label[x]); //find the root of x by recursion.
	}
	bool join(int a,int b) { // join the sets which contains a and b. Return false iff a and b are already in the same set.
		int x=find(a);
		int y=find(b);
		if (x==y) return (false); //A set contains both a and b.
		if (label[x]>label[y]) swap(x,y); //label[x]>label[y] means size(x)<size(y).
		//We speed up the disjoint set by joinning the smaller set to the bigger set
		label[x]+=label[y];
		label[y]=x; //Update the label of x and y.
		return (true);
	}
	int getSize(int x) { //return the size of set which contains x.
		return (-label[find(x)]);
	}
};

struct Comp {
    int sumCost, sumValue;
    vector<pair<int, int> > nodes;

    Comp() {
        sumCost = sumValue = 0;
        nodes.clear();
    }
};

#define MAX   1111

Comp comps[MAX];
int numComp, n, m, lim;
int cost[MAX], value[MAX], compID[MAX];
int f[MAX][MAX];

void init(void) {
    scanf("%d%d%d", &n, &m, &lim);
    FOR(i, 1, n) scanf("%d", &cost[i]);
    FOR(i, 1, n) scanf("%d", &value[i]);
}

void prepare(void) {
    DisjointSet dsu(n);
    REP(love, m) {
        int u, v; scanf("%d%d", &u, &v);
        dsu.join(u, v);
    }

    FOR(i, 1, n) if (dsu.find(i) == i) compID[i] = ++numComp;
    FOR(i, 1, n) {
        int u = compID[dsu.find(i)];
        comps[u].nodes.push_back(make_pair(cost[i], value[i]));
        comps[u].sumCost += cost[i];
        comps[u].sumValue += value[i];
    }
}

void process(void) {
    memset(f, -1, sizeof f);
    f[0][0] = 0;
    REP(i, numComp) REP(j, lim + 1) if (f[i][j] >= 0) {
        Comp &cur = comps[i + 1];

        maximize(f[i + 1][j], f[i][j]);
        if (j + cur.sumCost <= lim)
            maximize(f[i + 1][j + cur.sumCost], f[i][j] + cur.sumValue);
        FORE(it, cur.nodes) if (j + it->fi <= lim) maximize(f[i + 1][j + it->fi], f[i][j] + it->se);
    }

    int res = 0;
    REP(j, lim + 1) maximize(res, f[numComp][j]);
    printf("%d\n", res);
}

int main(void) {
    init();
    prepare();
    process();
    return 0;
}
/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/