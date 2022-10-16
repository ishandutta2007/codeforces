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

using namespace std;
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
/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   300300
const int MOD = (int)1e9 + 7;

pair<int, int> edges[MAX];
int numNode, numEdge;
int cntNode[MAX], cntEdge[MAX];
bool haveLoop[MAX];

void loadGraph(void) {
    int n; scanf("%d", &n);
    numNode = 2 * n; numEdge = n;
    FOR(i, 1, numEdge) {
        int u, v; scanf("%d%d", &u, &v);
        assert(1 <= u && u <= numNode);
        assert(1 <= v && v <= numNode);
        edges[i] = make_pair(u, v);
    }
}

void process(void) {
    DisjointSet dsu(numNode);
    FOR(i, 1, numEdge) dsu.join(edges[i].fi, edges[i].se);

    FOR(i, 1, numNode) cntNode[dsu.find(i)]++;
    FOR(i, 1, numEdge) cntEdge[dsu.find(edges[i].fi)]++;
    FOR(i, 1, numEdge) if (edges[i].fi == edges[i].se)
        haveLoop[dsu.find(edges[i].fi)] = true;

    int res = 1;
    FOR(i, 1, numNode) if (dsu.find(i) == i) {
        int numWay = 0;
        if (cntEdge[i] > cntNode[i]) numWay = 0;
        else if (cntEdge[i] == cntNode[i]) numWay = haveLoop[i] ? 1 : 2;
        else numWay = cntNode[i];
        res = 1LL * res * numWay % MOD;
    }
    cout << res << endl;
}

int main(void) {
    loadGraph();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/