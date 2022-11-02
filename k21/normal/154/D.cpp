#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
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

#define DEBUG(x) cout << ">>> " << #x << " = " << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

typedef long long ll;

int main() {
	int x1, x2, oa, ob;
	scanf("%d%d%d%d", &x1, &x2, &oa, &ob);
	int a = oa, b = ob;
	int d = x2 - x1;
	if (d < 0) {
		swap(a, b);
		a = -a;
		b = -b;
		d = -d;
	}
	if (b <= 0) {puts("DRAW"); return 0;}
	if (a <= d && b >= d) {printf("FIRST\n%d\n", x2); return 0;}
	if (a > d) {puts("DRAW"); return 0;}
	if (a > 0) {
		int t = d % (a+b);
		if (t == 0) puts("SECOND");
		else if (t < a || t > b) puts("DRAW");
		else {
			if (oa != a) t = -t;
			printf("FIRST\n%d\n", x1+t);
		}
		return 0;
	}
	puts("DRAW");
	return 0;
}