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
#define DEBUG(x) cerr << '>' << #x << ':' << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

const int MAXN = 101000;

int N, L, X, Y;
int A[MAXN];

vector<pair<int, int>> canMeasure(int d) {
	vector<pair<int, int>> out;
	int i1 = 0, i2 = 0;
	while (i2 < N && i1 < N) {
		if (A[i2] - A[i1] < d) {
			++i2;
		} else if (A[i2] - A[i1] > d) {
			++i1;
		} else {
			out.push_back({i1, i2});
			++i1; ++i2;
		}
	}
	return std::move(out);
}

int main() {
	scanf("%d%d%d%d", &N, &L, &X, &Y);
	REP(i,N) {
		scanf("%d", A+i);
	}
	
	if (!canMeasure(X).empty() && !canMeasure(Y).empty()) {
		printf("0\n");
		return 0;
	}
	
	if (!canMeasure(X).empty()) {
		printf("1\n%d\n", Y);
		return 0;
	}
	
	if (!canMeasure(Y).empty()) {
		printf("1\n%d\n", X);
		return 0;
	}
	
	auto opts = canMeasure(X+Y);
	if (!opts.empty()) {
		printf("1\n%d\n", A[opts[0].first] + X);
		return 0;
	}
	
	opts = canMeasure(Y-X);
	for (auto p : opts) {
		int i1 = p.first;
		int i2 = p.second;
		if (A[i1] - X >= 0) {
			printf("1\n%d\n", A[i1] - X);
			return 0;
		}
		if (A[i2] + X <= L) {
			printf("1\n%d\n", A[i2] + X);
			return 0;
		}
	}
	
	printf("2\n%d %d\n", X, Y);
	return 0;
}