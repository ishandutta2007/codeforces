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
	double A, D;
	int N;
	scanf("%lf%lf%d", &A, &D, &N);
	FOR(i, 1, N) {
		double m = fmod(i*D, 4*A);
		if (m < A) {
			printf("%lf %lf\n", m, 0.0);
		} else if (m < 2*A) {
			printf("%lf %lf\n", A, m-A);
		} else if (m < 3*A) {
			printf("%lf %lf\n", 3*A-m, A);
		} else {
			printf("%lf %lf\n", 0.0, 4*A-m);
		}
	}
	return 0;
}