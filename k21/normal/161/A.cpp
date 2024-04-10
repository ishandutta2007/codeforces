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

int a[100100];
int b[100100];
int res[100100][2];
int cres = 0;

int main() {
	int N, M;
	int x, y;
	scanf("%d%d%d%d", &N, &M, &x, &y);
	REP(i,N) scanf("%d", a+i);
	REP(i,M) scanf("%d", b+i);
	int ai = 0, bi = 0;
	while (ai < N && bi < M) {
		if (a[ai]-x <= b[bi] && b[bi] <= a[ai]+y) {
			res[cres][0] = ai;
			res[cres][1] = bi;
			++cres;
			++ai;
			++bi;
		} else if (a[ai]-x > b[bi]) ++bi;
		else ++ai;
	}
	printf("%d\n", cres);
	REP(i,cres) printf("%d %d\n", res[i][0]+1, res[i][1]+1);
	return 0;
}