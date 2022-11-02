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

const int K = 1000000;

bool used[K+42];

int main() {
	int N;
	scanf("%d", &N);
	REP(i,K) used[i] = false;
	REP(i,N) {
		int x;
		scanf("%d", &x);
		used[x-1] = true;
	}

	vector<int> my;

	int miss = 0;
	REP(i, K) {
		if (used[i] && used[K-1-i]) {
			++miss;
		} else if (used[i]) {
			my.push_back(K-1-i);
		}
	}

	int i = 0;
	while (miss) {
		if (!used[i] && !used[K-1-i]) {
			my.push_back(i);
			my.push_back(K-1-i);
			miss -= 2;
		}
		++i;
		if (i >= K) exit(1);
	}

	printf("%d\n", (int)my.size());
	REP(i, (int)my.size()) {
		printf("%d%c", my[i]+1, i == (int)my.size() - 1 ? '\n' : ' ');
	}

	return 0;
}