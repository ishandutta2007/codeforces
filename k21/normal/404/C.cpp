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

int N, K, D[110000];
vector<int> rev[110000];
int maxD = 0;
vector<pair<int, int> > edges;

int main() {
	scanf("%d%d", &N, &K);
	REP(i, N) scanf("%d", D+i);

	if (K == 1) {
		if (N > 2) {
			printf("-1\n");
			return 0;
		}
	}

	REP(i, N) rev[D[i]].push_back(i);
	REP(i, N) if (D[i] > maxD) maxD = D[i];

	if (rev[0].size() != 1) {
		printf("-1\n");
		return 0;
	}

	FOR(i, 1, maxD) {
		if (rev[i-1].empty()) {
			printf("-1\n");
			return 0;
		}
		vector<int>::iterator it1 = rev[i-1].begin();
		vector<int>::iterator it2 = rev[i].begin();
		int left = (i == 1) ? K : K-1;
		while (it2 != rev[i].end()) {
			if (left == 0) {
				++it1;
				if (it1 == rev[i-1].end()) {
					printf("-1\n");
					return 0;
				}
				left = K-1;
			}
			--left;
			edges.push_back(make_pair(*it1, *it2));
			++it2;
		}
	}

	printf("%d\n", (int)edges.size());
	REP(i, (int)edges.size()) {
		printf("%d %d\n", edges[i].first+1, edges[i].second+1);
	}

	return 0;
}