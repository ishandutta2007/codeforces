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

int N;
int ts[30000];
int sc[30000];

int sco(int d) {
	if (N/d < 3) return -1000000000;
	REP(i,d) sc[i] = 0;
	REP(i,N) sc[i%d] += ts[i];
	int r = -1000000000;
	REP(i,d) r = max(r,sc[i]);
	return r;
}

int main() {
	scanf("%d", &N);
	REP(i,N) scanf("%d", ts+i);
	int d = 1;
	int best = -1000000000;
	while (d*d <= N) {
		if (N%d) {++d;continue;}
		int o = sco(d);
		best = max(best, o);
		o = sco(N/d);
		best = max(best, o);
		++d;
	}
	printf("%d\n", best);
	return 0;
}