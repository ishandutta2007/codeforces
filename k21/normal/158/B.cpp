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

int b[10];

int main() {
	int N;
	scanf("%d", &N);
	REP(i,5) b[i] = 0;
	REP(i,N) {
		int s;
		scanf("%d", &s);
		++b[s];
	}
	int res = b[4];
	b[4] = 0;
	res += b[3];
	b[1] = max(b[1]-b[3],0);
	b[3] = 0;
	if (b[2]%2) {
		res += b[2]/2;
		b[2] = 1;
		res += 1;
		b[1] = max(b[1]-2,0);
		b[2] = 0;
	} else {
		res += b[2]/2;
		b[2] = 0;
	}
	res += b[1]/4;
	b[1] -= b[1]/4*4;
	if (b[1]) ++res;
	printf("%d\n", res);
	return 0;
}