#include<bits/stdc++.h>
#define MAX   500500
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
const char yes[] = "Yes";
const char no[] = "No";
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
#define ONLYS   0
#define ONLYT   1
#define BOTH   2
#define NONE   3
struct Component {
    int edgeS, edgeT;
    Component() {
        edgeS = edgeT = -1;
    }
    int status(void) const {
        if (edgeS > 0) return edgeT > 0 ? BOTH : ONLYS;
        else return edgeT > 0 ? ONLYT : NONE;
    }
};
int limS, limT, n, m, s, t;
pair<int, int> edges[MAX];
bool mustUse[MAX];
Component components[MAX];
int numComp, root[MAX], compID[MAX];
int onlyS, onlyT, both;
void loadGraph(void) {
    scanf("%d%d", &n, &m);
    FOR(i, 1, m) scanf("%d%d", &edges[i].fi, &edges[i].se);
    scanf("%d%d%d%d", &s, &t, &limS, &limT);
}
bool goodEdge(int u, int v) {
    return u != s && u != t && v != s && v != t;
}
void findComponents(void) {
    DisjointSet dsu(n);
    FOR(i, 1, m) if (goodEdge(edges[i].fi, edges[i].se)) mustUse[i] = dsu.join(edges[i].fi, edges[i].se);
    FOR(i, 1, n) if (i != s && i != t && dsu.find(i) == i) {
        root[++numComp] = i;
        compID[i] = numComp;
    }
    FOR(i, 1, numComp) components[i].edgeS = components[i].edgeT = -1;
    FOR(i, 1, m) {
        int u = edges[i].fi;
        int v = edges[i].se;
        if (u == s || v == s) {
            int other = u ^ v ^ s;
            if (other != t) components[compID[dsu.find(other)]].edgeS = other;
        }
        if (u == t || v == t) {
            int other = u ^ v ^ t;
            if (other != s) components[compID[dsu.find(other)]].edgeT = other;
        }
    }
    FOR(i, 1, numComp) {
        int tmp = components[i].status();
        if (tmp == ONLYS) onlyS++;
        if (tmp == ONLYT) onlyT++;
        if (tmp == BOTH) both++;
    }
}
void printOtherEdges(void) {
    FOR(i, 1, m) if (mustUse[i]) printf("%d %d\n", edges[i].fi, edges[i].se);
    exit(0);
}
void connectComponents(int except, int limS, int limT) {
    int usedS = 0, usedT = 0;
    FOR(i, 1, numComp) if (i != except) {
        if (components[i].edgeT <= 0) {
            usedS++;
            printf("%d %d\n", s, components[i].edgeS);
        } else if (components[i].edgeS <= 0) {
            usedT++;
            printf("%d %d\n", t, components[i].edgeT);
        }
    }
    FOR(i, 1, numComp) if (i != except && components[i].edgeS > 0 && components[i].edgeT > 0) {
        if (usedS < limS) {
            usedS++;
            printf("%d %d\n", s, components[i].edgeS);
        } else {
            usedT++;
            printf("%d %d\n", t, components[i].edgeT);
        }
    }
}
void excludeCase(void) {
    FOR(i, 1, numComp) if (components[i].status() == BOTH) {
        int limS = ::limS - 1;
        int limT = ::limT - 1;
        if (onlyS > limS || onlyT > limT || onlyS + onlyT + both - 1 > limS + limT) continue;
        printf("%s\n", yes);
        printf("%d %d\n", s, components[i].edgeS);
        printf("%d %d\n", t, components[i].edgeT);
        connectComponents(i, limS, limT);
        return printOtherEdges();
    }
}
void includeCase(void) {
    int limS = ::limS - 1;
    int limT = ::limT - 1;
    if (onlyS > limS || onlyT > limT || onlyS + onlyT + both > limS + limT) return;
    printf("%s\n", yes);
    printf("%d %d\n", s, t);
    connectComponents(-1, limS, limT);
    printOtherEdges();
}
void process(void) {
    excludeCase();
    FOR(i, 1, m) {
        int u = edges[i].fi;
        int v = edges[i].se;
        if (u != s && v != s) continue;
        if (u != t && v != t) continue;
        includeCase();
        break;
    }
    printf("%s\n", no);
}
int main(void) {
    loadGraph();
    findComponents();
    process();
    return 0;
}