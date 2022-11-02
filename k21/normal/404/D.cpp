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

#define MOD 1000000007LL

char S[1001000];

ll state[2][2];

void updateState(char c) {
	ll nstate[2][2];
	REP(i,2) REP(j,2) nstate[i][j] = 0;

	switch (c) {
		case '0':
			nstate[0][0] = state[0][0];
			break;
		case '1':
			nstate[0][0] = state[1][0];
			nstate[0][1] = state[0][0];
			break;
		case '2':
			nstate[0][1] = state[1][0];
			break;
		case '*':
			nstate[1][0] = state[0][1] + state[1][1];
			nstate[1][1] = state[0][1] + state[1][1];
			break;
		case '?':
			nstate[0][0] = state[0][0] + state[1][0];
			nstate[0][1] = state[0][0] + state[1][0];
			nstate[1][0] = state[0][1] + state[1][1];
			nstate[1][1] = state[0][1] + state[1][1];
			break;
	}

	REP(i,2) REP(j,2) state[i][j] = nstate[i][j] % MOD;
}

int main() {

	state[0][0] = state[0][1] = 1;
	state[1][0] = state[1][1] = 0;

	gets(S);
	int L = strlen(S);

	REP(i,L) updateState(S[i]);

	printf("%lld\n", (state[0][0] + state[1][0]) % MOD);

	return 0;
}