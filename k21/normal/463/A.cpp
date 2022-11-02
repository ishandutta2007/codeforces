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

int main() {
	int N, S;
	scanf("%d%d", &N, &S);

	int best = -1;

	REP(i,N) {
		int x, y;
		scanf("%d%d", &x, &y);

		if (x > S || (x == S && y != 0)) {
			continue;
		}

		int sweets = y ? 100 - y : 0;
		best = max(best, sweets);
	}

	printf("%d\n", best);

	return 0;
}