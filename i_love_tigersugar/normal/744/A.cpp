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
	bool sameSet(int u, int v) {
        return find(u) == find(v);
	}
};


/* Author: Van Hanh Pham - skyvn97 */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   100100

int n, m, q;
vector<int> nodes;

long long comb2(int x) {
    return x < 2 ? 0 : 1LL * x * (x - 1) / 2;
}

void process(void) {
    scanf("%d%d%d", &n, &m, &q);
    REP(love, q) {
        int x; scanf("%d", &x);
        nodes.push_back(x);
    }

    DisjointSet dsu(n);
    REP(love, m) {
        int u, v; scanf("%d%d", &u, &v);
        dsu.join(u, v);
    }

    long long res = 0;
    long long sum = 0;
    FORE(it, nodes) sum += comb2(dsu.getSize(*it));

    int numFree = 0;
    FOR(i, 1, n) {
        bool isFree = true;
        FORE(it, nodes) if (dsu.sameSet(*it, i)) isFree = false;
        if (isFree) numFree++;
    }

    FORE(it, nodes) {
        int oldSize = dsu.getSize(*it);
        int newSize = oldSize + numFree;
        maximize(res, sum - comb2(oldSize) + comb2(newSize));
    }
    cout << res - m << endl;
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/