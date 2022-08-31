#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int query(int sx, int ex, int sy, int ey){
	if(sx > ex || sy > ey) return 0;
	printf("? %d %d %d %d\n", sx, sy, ex, ey);
	fflush(stdout);
	int v;
	scanf("%d",&v);
	return v;
}

void report(int sx, int ex, int sy, int ey,
			int sx2, int ex2, int sy2, int ey2){
	printf("! %d %d %d %d %d %d %d %d\n", sx, sy, ex, ey, sx2, sy2, ex2, ey2);
	fflush(stdout);
}

struct rect{ int sx, ex, sy, ey; };

rect condense(int sx, int ex, int sy, int ey){
	rect r;
	int s = sx, e = ex;
	while(s != e){
		int m = (s+e+1)/2;
		if(query(m, ex, sy, ey) == 1) s = m;
		else e = m-1;
	}
	r.sx = s;
	s = sx, e = ex;
	while(s != e){
		int m = (s+e)/2;
		if(query(sx, m, sy, ey) == 1) e = m;
		else s = m+1;
	}
	r.ex = s;
	tie(sx, ex) = pi(r.sx, r.ex);
	s = sy, e = ey;
	while(s != e){
		int m = (s+e+1)/2;
		if(query(sx, ex, m, ey) == 1) s = m;
		else e = m-1;
	}
	r.sy = s;
	s = sy, e = ey;
	while(s != e){
		int m = (s+e)/2;
		if(query(sx, ex, sy, m) == 1) e = m;
		else s = m+1;
	}
	r.ey = s;
	return r;
}

int n;

int main(){
	scanf("%d",&n);
	int sx = 1, ex = n, sy = 1, ey = n;
	int lx, rx, ly, ry;
	int s = sx, e = ex;
	while(s != e){
		int m = (s+e)/2;
		if(query(sx, m, sy, ey) < 1) s = m+1;
		else e = m;
	}
	rx = s;
	s = sx, e = ex;
	while(s != e){
		int m = (s+e+1)/2;
		if(query(m, ex, sy, ey) < 1) e = m-1;
		else s = m;
	}
	lx = s;
	s = sy, e = ey;
	while(s != e){
		int m = (s+e)/2;
		if(query(sx, ex, sy, m) < 1) s = m+1;
		else e = m;
	}
	ry = s;
	s = sy, e = ey;
	while(s != e){
		int m = (s+e+1)/2;
		if(query(sx, ex, m, ey) < 1) e = m-1;
		else s = m;
	}
	ly = s;
	if(rx < lx){
		rect a = condense(1, rx, 1, n);
		rect b = condense(lx, n, 1, n);
		report(a.sx, a.ex, a.sy, a.ey, b.sx, b.ex, b.sy, b.ey);
	}
	else if(ry < ly){
		rect a = condense(1, n, 1, ry);
		rect b = condense(1, n, ly, n);
		report(a.sx, a.ex, a.sy, a.ey, b.sx, b.ex, b.sy, b.ey);
	}
	else assert(0);
}