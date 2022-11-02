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

#define DEBUG(x) cout << '>' << #x << " = " << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

typedef long long ll;

using namespace std;

bool is_rectangle(int x[4], int y[4]) {
	if (x[1]-x[0] != x[3]-x[2]) return false;
	if (y[1]-y[0] != y[3]-y[2]) return false;
	if (x[2]-x[0] != x[3]-x[1]) return false;
	if (y[2]-y[0] != y[3]-y[1]) return false;
	if ((x[1]-x[0])*(x[2]-x[0])+(y[1]-y[0])*(y[2]-y[0])) return false;
	return true;
}

bool is_square(int x[4], int y[4]) {
	if (!is_rectangle(x,y)) return false;
	int dx1 = x[1]-x[0], dy1 = y[1]-y[0];
	int dx2 = x[2]-x[0], dy2 = y[2]-y[0];
	if (dx1*dx1+dy1*dy1 != dx2*dx2+dy2*dy2) return false;
	return true;
}

int xs[10], ys[10];

struct cmp {
	bool operator () (int i1, int i2) {
		if (ys[i1]<ys[i2]) return true;
		if (ys[i1]>ys[i2]) return false;
		if (xs[i1]<xs[i2]) return true;
		return false;
	}
};

int main() {
	REP(i,8) scanf("%d%d", xs+i, ys+i);
	int is[] = {0,1,2,3,4,5,6,7};
	sort(is, is+8, cmp());
	FOR(i1,0,4)FOR(i2,i1+1,5)FOR(i3,i2+1,6)FOR(i4,i3+1,7){
		int sxs[4], sys[4], rxs[4], rys[4];
		int sc = 0, rc = 0;
		REP(ii,8){
			int i = is[ii];
			if (i==i1||i==i2||i==i3||i==i4){sxs[sc]=xs[i];sys[sc]=ys[i];++sc;}
			else {rxs[rc]=xs[i];rys[rc]=ys[i];++rc;}
		}
		if (is_square(sxs, sys) && is_rectangle(rxs, rys)){
			printf("YES\n");
			sc=rc=0;
			int ri[4], si[4];
			REP(ii,8){
				int i = is[ii];
				if (i==i1||i==i2||i==i3||i==i4){si[sc]=i;++sc;}
				else {ri[rc]=i;++rc;}
			}
			REP(i,4)printf(i==3?"%d\n":"%d ", si[i]+1);
			REP(i,4)printf(i==3?"%d\n":"%d ", ri[i]+1);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}