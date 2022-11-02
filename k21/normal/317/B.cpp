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

const int MAXS = 1000;

int data1[MAXS][MAXS], data2[MAXS][MAXS];

int (*state)[MAXS] = data1;
int (*tstate)[MAXS] = data2;
int S = 1;
int N, T;

int main() {
	scanf("%d", &N);
	state[0][0] = N;
	while (true) {
		bool change = false;
		REP(i,S) REP(j,S) tstate[i][j] = state[i][j];
		REP(i,S) REP(j,S) {
			if (state[i][j] >= 4) {
				change = true;
				tstate[i][j] -= 4;
				++tstate[i+1][j  ];
				++tstate[i  ][j+1];
				if (i != 0) ++tstate[i-1][j  ];
				if (j != 0) ++tstate[i  ][j-1];
				if (i == 1) ++tstate[i-1][j  ];
				if (j == 1) ++tstate[i  ][j-1];
				if (i+1 >= S || j+1 >= S) ++S;
			}
		}
		swap(state, tstate);
		if (!change) break;
	}
	scanf("%d", &T);
	REP(t,T) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x < 0) x = -x;
		if (y < 0) y = -y;
		if (x >= S || y >= S) { printf("0\n"); continue; }
		printf("%d\n", state[x][y]);
	}
	return 0;
}