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

int pw[10];
void precalc(void) {
	pw[0] = 1;
	FOR(i, 1, 9) pw[i] = 10 * pw[i - 1];
}

class SegmentTree {
	private:
	struct Node {
		long long sumValue[10];
		int lazy[10];
		
		Node() {
			memset(sumValue, 0, sizeof sumValue);
			REP(i, 10) lazy[i] = i;
		}
		
		long long totalValue(void) const {
			long long res = 0;
			REP(i, 10) res += i * sumValue[i];
			return res;
		}
		
		void sumUp(const Node &L, const Node &R) {
			REP(i, 10) sumValue[i] = L.sumValue[i] + R.sumValue[i];
		}
		
		void applyChange(int from, int to) {
			REP(i, 10) if (lazy[i] == from) lazy[i] = to;
			sumValue[to] += sumValue[from];
			sumValue[from] = 0;
		}
		
		void applyLazy(int par[]) {
			long long newSum[10];
			memset(newSum, 0, sizeof newSum);
		
			REP(i, 10) {
				newSum[par[i]] += sumValue[i];
				lazy[i] = par[lazy[i]];
			}
			REP(i, 10) sumValue[i] = newSum[i];			
		}
		
		void resetLazy(void) {
			REP(i, 10) lazy[i] = i;
		}
	};
	
	vector<Node> tree;
	int n;
	
	void pushDown(int i) {
		FOR(j, 2 * i, 2 * i + 1) tree[j].applyLazy(tree[i].lazy);
		tree[i].resetLazy();
	}
	
	void update(int i, int l, int r, int u, int v, int from, int to) {
		if (l > v || r < u || l > r || v < u) return;
		if (u <= l && r <= v) return tree[i].applyChange(from, to);
		
		pushDown(i);
		int m = (l + r) >> 1;
		update(2 * i, l, m, u, v, from, to);
		update(2 * i + 1, m + 1, r, u, v, from, to);
		tree[i].sumUp(tree[2 * i], tree[2 * i + 1]);
	}
	
	long long getSum(int i, int l, int r, int u, int v) {
		if (l > v || r < u || l > r || v < u) return 0;
		if (u <= l && r <= v) return tree[i].totalValue();
		
		pushDown(i);
		int m = (l + r) >> 1;
		long long L = getSum(2 * i, l, m, u, v);
		long long R = getSum(2 * i + 1, m + 1, r, u, v);
		return L + R;
	}
	
	void build(int i, int l, int r, int value[]) {
		if (l == r) {
			int x = value[r], pos = 0;
			while (x > 0) {
				int dig = x % 10; x /= 10;
				tree[i].sumValue[dig] += pw[pos++];
			}
			return;
		}
		
		int m = (l + r) >> 1;
		build(2 * i, l, m, value);
		build(2 * i + 1, m + 1, r, value);
		tree[i].sumUp(tree[2 * i], tree[2 * i + 1]);
	}
	
	public:
	SegmentTree(int n = 0, int value[] = NULL) {
		this->n = n;
		tree.assign(4 * n + 7, Node());		
		if (n > 0) build(1, 1, n, value);
	}
	
	void update(int l, int r, int from, int to) {
		if (from == to) return;
		update(1, 1, n, l, r, from, to);
	}
	
	long long getSum(int l, int r) {
		return getSum(1, 1, n, l, r);
	}
};

#define MAX   300300
int a[MAX];

void process(void) {
	int n, q; scanf("%d%d", &n, &q);
	FOR(i, 1, n) scanf("%d", &a[i]);
	
	SegmentTree myit(n, a);
	
	REP(PMP, q) {
		int type, l, r; scanf("%d%d%d", &type, &l, &r);
		if (type == 1) {
			int from, to; scanf("%d%d", &from, &to);
			myit.update(l, r, from, to);
		} else cout << myit.getSum(l, r) << "\n";
	}
}

int main(void) {
	precalc();
	process();
	return 0;
}
/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/