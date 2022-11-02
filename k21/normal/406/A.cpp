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

const int MAXN = 2000;

int main() {
	int N;
	scanf("%d", &N);
	int total = 0;
	REP(i,N) {
		REP(j,N) {
			int x;
			scanf("%d", &x);
			if (i == j) total += x;
		}
	}

	total &= 1;

	int Q;
	scanf("%d", &Q);
	REP(q,Q) {
		int c, k;
		scanf("%d", &c);
		if (c == 3) {
			printf("%d", total);
			continue;
		}
		scanf("%d", &k);
		total = (total + 1) & 1;
	}

	printf("\n");

	return 0;
}