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
#define DEBUG(x) cerr << '>' << #x << ':' << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;
typedef unsigned long long ull;

const int BITS = 30;
const int MAXN = 100100;
const int MAXM = 100100;
const int BLOCKS = 317;

int N, M;

int onUntil[BITS*MAXN];
bool isOn[BITS*MAXN];
int result[MAXN];
int blocks[BLOCKS];
int L[MAXM], R[MAXM], Q[MAXM];

void setOn(int from, int to) {
	onUntil[from] = max(onUntil[from], to);
}

int getBlock(int i) {
	return i / BLOCKS;
}

int getAndSlow(int b, int e) {
	int r = (1<<BITS) - 1;
	FOR(i,b,e-1) r &= result[i];
	return r;
}

int getAndBlocks(int bb, int ee) {
	int r = (1<<BITS) - 1;
	FOR(ii,bb,ee-1) r &= blocks[ii];
	return r;
}

int getAnd(int b, int e) {
	int bb = getBlock(b);
	int ee = getBlock(e);
	if (bb == ee) {
		return getAndSlow(b, e);
	}
	
	return getAndBlocks(bb+1, ee) & getAndSlow(b, (bb+1)*BLOCKS) & getAndSlow(ee*BLOCKS, e);
}

int main() {
	scanf("%d%d", &N, &M);
	REP(i,M) {
		scanf("%d%d%d", L+i, R+i, Q+i);
	}
	REP(i,M) {
		int bit = 0;
		int q = Q[i];
		while (q) {
			if (q & 1) {
				setOn(bit*MAXN+L[i]-1, bit*MAXN+R[i]);
			}
			q >>= 1;
			++bit;
		}
	}
	
	int until = 0;
	REP(bit, BITS) {
		int mask = 1 << bit;
		REP(ii,N) {
			int i = bit*MAXN + ii;
			until = max(until, onUntil[i]);
			if (i < until) {
				result[ii] |= mask;
			}
		}
	}
	
	REP(i, BLOCKS) {
		int r = (1<<BITS) - 1;
		REP(j, BLOCKS) {
			r &= result[i*BLOCKS+j];
		}
		blocks[i] = r;
	}
	
	/*
	REP(i,N) {
		DEBUG(result[i]);
	}
	*/
	
	REP(i,M) {
		if (getAnd(L[i]-1, R[i]) != Q[i]) {
			printf("NO\n");
			return 0;
		}
	}
	
	printf("YES\n");
	REP(i,N) {
		printf("%d%c", result[i], i == N-1 ? '\n' : ' ');
	}
	
	return 0;
}