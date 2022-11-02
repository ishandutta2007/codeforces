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
	int N;
	char buf[1000];
	scanf("%d ", &N);
	bool ok = true;
	bool first = true;
	char c1 = '\0', c2 = '\0';
	REP(i,N) {
		gets(buf);
		if (first) {
			c1 = buf[0];
			c2 = buf[1];
			first = false;
			if (c1 == c2) ok = false;
		}
		REP(j,N) {
			if (j == i || N-j-1 == i) {
				if (buf[j] != c1) {
					ok = false;
				}
			} else {
				if (buf[j] != c2) {
					ok = false;
				}
			}
		}
	}
	printf("%s\n", ok ? "YES" : "NO");
	return 0;
}