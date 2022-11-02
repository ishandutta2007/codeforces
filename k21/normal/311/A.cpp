#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<a;++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;

typedef long long ll;

int n, k;

int main()
{
	scanf("%d%d", &n, &k);
	int m = n*(n-1)/2;
	if (m <= k) {
		printf("no solution\n");
		return 0;
	}
	REP(i,n) {
		printf("0 %d\n", i);
	}
	return 0;
}