#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    void minimize(X &x, const Y &y) {
        if (x > y) x = y;
    }
template<class X, class Y>
    void maximize(X &x, const Y &y) {
        if (x < y) x = y;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

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
	bool sameSet(int x, int y) {
	    return find(x) == find(y);
	}
};

const string YES = "Yes";
const string NO = "No";

void answer(const string &s) {
    cout << s << endl;
    exit(EXIT_SUCCESS);
}

#define MAX   55
#define MARKED   '#'

char board[MAX][MAX];
int numRow, numCol;
vector<int> compRow[MAX], compCol[MAX];

void init(void) {
    scanf("%d%d", &numRow, &numCol);
    FOR(i, 1, numRow) scanf("%s", board[i] + 1);
}

bool check(const vector<int> &rows, const vector<int> &cols) {
    if (rows.empty() || cols.empty()) return true;
    char c = board[rows[0]][cols[0]];

    FORE(it, rows) FORE(jt, cols) if (board[*it][*jt] != c) return false;
    return true;
}

void process(void) {
    DisjointSet rows(numRow), cols(numCol);
    FOR(i, 1, numRow) {
        vector<int> indices;
        FOR(j, 1, numCol) if (board[i][j] == MARKED) indices.push_back(j);

        if (indices.size() < 2) continue;
        REP(k, indices.size() - 1) cols.join(indices[k], indices[k + 1]);
    }

    FOR(j, 1, numCol) {
        vector<int> indices;
        FOR(i, 1, numRow) if (board[i][j] == MARKED) indices.push_back(i);

        if (indices.size() < 2) continue;
        REP(k, indices.size() - 1) rows.join(indices[k], indices[k + 1]);
    }

    FOR(i, 1, numRow) compRow[rows.find(i)].push_back(i);
    FOR(j, 1, numCol) compCol[cols.find(j)].push_back(j);

    FOR(i1, 1, numRow) FOR(i2, i1 + 1, numRow) if (rows.sameSet(i1, i2))
        FOR(j, 1, numCol) if (board[i1][j] != board[i2][j]) answer(NO);

    FOR(j1, 1, numCol) FOR(j2, j1 + 1, numCol) if (cols.sameSet(j1, j2))
        FOR(i, 1, numRow) if (board[i][j1] != board[i][j2]) answer(NO);

    FOR(i, 1, numRow) if (rows.find(i) == i)
        FOR(j, 1, numCol) if (cols.find(j) == j)
            if (!check(compRow[i], compCol[j])) answer(NO);

    answer(YES);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/