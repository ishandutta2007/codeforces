#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

const int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};

int opt[120][132000];
int path[120][132000];

int N;
int A[120];

static unsigned int setbit(unsigned int n, int b) {
	return n | (1<<b);
}

static unsigned int clearbit(unsigned int n, int b) {
	return n & ~(1<<b);
}

static bool isset(unsigned int n, int b) {
	return n & (1<<b);
}

static void consider(int step, int state, int n, int p) {
	if (n < opt[step][state]) {
		opt[step][state] = n;
		path[step][state] = p;
	}
}

static int closest(int a) {
	return 1;
}
static int dist(int a) {
	return abs(a - closest(a));
}

static int closest(int a, int p1) {
	int best = INF;
	int cl = 0;
	for (int t1 = p1; t1 <= 60; t1 *= p1) {
		if (abs(t1-a) < best) {
			best = abs(t1-a);
			cl = t1;
		}
	}
	return cl;
}
static int dist(int a, int p1) {
	return abs(a - closest(a, p1));
}

static int closest(int a, int p1, int p2) {
	int best = INF;
	int cl = 0;
	for (int t1 = p1; t1 <= 60; t1 *= p1) {
		for (int t2 = p2 * t1; t2 <= 60; t2 *= p2) {
			if (abs(t2-a) < best) {
				best = abs(t2-a);
				cl = t2;
			}
		}
	}
	return cl;
}
static int dist(int a, int p1, int p2) {
	return abs(a - closest(a, p1, p2));
}

static int closest(int a, int p1, int p2, int p3) {
	int best = INF;
	int cl = 0;
	for (int t1 = p1; t1 <= 60; t1 *= p1) {
		for (int t2 = p2 * t1; t2 <= 60; t2 *= p2) {
			for (int t3 = p3 * t2; t3 <= 60; t3 *= p3) {
				if (abs(t3-a) < best) {
					best = abs(t3-a);
					cl = t3;
				}
			}
		}
	}
	return cl;
}
static int dist(int a, int p1, int p2, int p3) {
	return abs(a - closest(a, p1, p2, p3));
}

int main() {
	scanf("%d", &N);
	REP(i,N) scanf("%d", A+i);

	REP(i,120) REP(j,1<<17) opt[i][j] = INF;
	opt[0][0] = 0;
	REP(i,N) {
		REP(prev,1<<17) {
			consider(i+1, prev, opt[i][prev] + dist(A[i]), -1);
			REP(j,17) {
				if (!isset(prev, j)) {
					int next = setbit(prev, j);
					consider(i+1, next, opt[i][prev] + dist(A[i], primes[j]), j);
				}
			}
			if (!isset(prev, 0)) FOR(j,1,9) {
				if (!isset(prev, j)) {
					int next = setbit(setbit(prev, j), 0);
					consider(i+1, next, opt[i][prev] + dist(A[i], primes[j], 2), j+100);
				}
			}
			if (!isset(prev, 1)) FOR(j,2,7) {
				if (!isset(prev, j)) {
					int next = setbit(setbit(prev, j), 1);
					consider(i+1, next, opt[i][prev] + dist(A[i], primes[j], 3), j+200);
				}
			}
			if (!isset(prev, 2)) FOR(j,3,4) {
				if (!isset(prev, j)) {
					int next = setbit(setbit(prev, j), 2);
					consider(i+1, next, opt[i][prev] + dist(A[i], primes[j], 5), j+300);
				}
			}
			if (!isset(prev, 0) && !isset(prev, 1)) FOR(j,2,3) {
				if (!isset(prev, j)) {
					int next = setbit(setbit(setbit(prev, j), 0), 1);
					consider(i+1, next, opt[i][prev] + dist(A[i], primes[j], 2, 3), j+400);
				}
			}
		}
	}

	int best = INF;
	int bI = 0;
	REP(i,1<<17) {
		if (opt[N][i] < best) {
			best = opt[N][i];
			bI = i;
		}
	}
	vector<int> res;
	FORD(i,N,1) {
		int p = path[i][bI];
		if (p == -1) {
			res.push_back(1);
		} else if (p < 100) {
			bI = clearbit(bI, p);
			res.push_back(closest(A[i-1], primes[p]));
		} else if (p < 200) {
			bI = clearbit(bI, p - 100);
			bI = clearbit(bI, 0);
			res.push_back(closest(A[i-1], primes[p - 100], 2));
		} else if (p < 300) {
			bI = clearbit(bI, p - 200);
			bI = clearbit(bI, 1);
			res.push_back(closest(A[i-1], primes[p - 200], 3));
		} else if (p < 400) {
			bI = clearbit(bI, p - 300);
			bI = clearbit(bI, 2);
			res.push_back(closest(A[i-1], primes[p - 300], 5));
		} else {
			bI = clearbit(bI, p - 400);
			bI = clearbit(bI, 0);
			bI = clearbit(bI, 1);
			res.push_back(closest(A[i-1], primes[p - 400], 2, 3));
		}
	}

	FORD(i,N-1,0) {
		printf("%d%c", res[i], i ? ' ' : '\n');
	}

	return 0;
}