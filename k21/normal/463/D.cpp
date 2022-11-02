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

const int MAXN = 1500;
const int MAXK = 10;

int N, K;

bool edge[MAXN][MAXN];
int perm[MAXN];

set<int> inputs[MAXN];
set<int> outputs[MAXN];

vector<int> ready;
int best[MAXN];

int main() {
	scanf("%d%d", &N, &K);

	REP(i,N) REP(j,N) edge[i][j] = (i != j);

	REP(i,K) {
		REP(j,N) {
			scanf("%d", perm + j);
			--perm[j];
			REP(k,j) {
				int first = perm[k];
				int second = perm[j];
				edge[second][first] = false;
			}
		}
	}
	
	REP(i,N) REP(j,N) {
		if (edge[i][j]) {
			inputs[j].insert(i);
			outputs[i].insert(j);
		}
	}

	REP(i,N) {
		best[i] = 1;
		if (inputs[i].empty()) {
			ready.push_back(i);
		}
	}

	while (!ready.empty()) {
		int i = ready.back();
		ready.pop_back();
		for (int j : outputs[i]) {
			best[j] = max(best[j], best[i] + 1);
			inputs[j].erase(i);
			if (inputs[j].empty()) {
				ready.push_back(j);
			}
		}
	}

	int result = 0;
	REP(i,N) result = max(result, best[i]);

	printf("%d\n", result);

	return 0;
}