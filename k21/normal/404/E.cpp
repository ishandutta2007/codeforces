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

char S[1001000];
int L;

bool works(int ob) {
	int at = 0;
	int e = 0;
	int es = 0;
	REP(i,L) {
		if (S[i] == 'L') --at;
		else ++at;
		if (at <= ob) at = ob+1;
		if (at > e) { e = at; es = i; }
	}

	return (es == L-1);
}

int main() {
	gets(S);
	L = strlen(S);
	int at = 0;
	int e1 = 0, e2 = 0;
	int e1s = 0, e2s = 0;
	REP(i,L) {
		if (S[i] == 'L') --at;
		else ++at;
		if (at < e1) { e1 = at; e1s = i; }
		if (at > e2) { e2 = at; e2s = i; }
	}

	if (e1s == L-1 || e2s == L-1) {
		printf("1\n");
		return 0;
	}

	if (S[L-1] == 'L') {
		REP(i,L) S[i] = 'R'+'L'-S[i];
		int t = e1;
		e1 = -e2;
		e2 = -t;
	}

	int hi = 0, lo = e1;

	while (hi > lo) {
		int med = (hi+lo-1)/2;
		//DEBUG(hi);
		//DEBUG(lo);
		//DEBUG(med);
		if (works(med)) {
			hi = med;
			//DEBUG(1);
		} else {
			lo = med+1;
			//DEBUG(0);
		}
	}

	printf("%d\n", -hi);

	return 0;
}