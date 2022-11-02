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

int M, N;

int main() {
	scanf("%d%d", &M, &N);

	double dieExp = 0;
	REP(j,M) {
		double r = ((double)j/M) / ((double)(j+1)/M);
		double a = (j+1) * pow((double)(j+1)/M, N-1);
		dieExp += a * (1 - pow(r, N)) / (1 - r);
	}

	printf("%lf\n", dieExp / M);

	return 0;
}