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

int n, k, m;

int gn() {
	static int next = 0;
	next += 2;
	while (next == m || next + 1 == m || next == 2*m || next + 1 == 2*m) next += 2;
	return next;
}

int main() {
	scanf("%d%d", &n, &k);
	if (n < 2) {
		if (k == 0) {
			printf("1\n");
		} else {
			
			printf("-1\n");
		}
		return 0;
	}
	m = k - (n-2)/2;
	if (m < 1) {
		printf("-1\n");
		return 0;
	}
	vector<int> out;
	out.push_back(m);
	out.push_back(2*m);

	while ((int)out.size() < n - 1) {
		int a = gn();
		out.push_back(a);
		out.push_back(a+1);
	}

	if ((int)out.size() != n) {
		int a = gn();
		out.push_back(a);
	}

	REP(i, (int)out.size()) {
		printf("%d%c", out[i], i == (int)out.size() - 1 ? '\n' : ' ');
	}
	return 0;
}