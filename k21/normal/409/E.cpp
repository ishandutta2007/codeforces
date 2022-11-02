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
inline bool EQ(double a, double b) {return fabs(a-b) < 0.0001;}

const int INF = 1<<29;
typedef long long ll;

int main() {
	double x;
	scanf("%lf", &x);

	FOR(a,1,10) FOR(h,1,10) {
		double s1 = a / 2.0;
		double s2 = h;
		double p = sqrt(s1*s1 + s2*s2);
		double V = s1 * s2 / 2;
		double r = V / p * 2;
		if (EQ(r, x)) {
			printf("%d %d\n", a, h);
			return 0;
		}
	}
	abort();
	return 0;
}