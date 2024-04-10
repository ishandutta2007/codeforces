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
#define FOR2(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

typedef long long ll;

struct ip_t {
	int x, y;
	int dir1, dir2;
} ip;

char in[80][80];
int m, n, w;
int tops[80][80];
int lefts[80][80];
int rights[80][80];
int bottoms[80][80];

int ndir1[4][4] = {
	{4, 1, 4, 0},
	{1, 4, 2, 4},
	{4, 2, 4, 3},
	{0, 4, 3, 4}
};

int ndir2[4][4] = {
	{4, 0, 4, 1},
	{2, 4, 1, 4},
	{4, 3, 4, 2},
	{3, 4, 0, 4}
};

bool valid(int x, int y) {
	if (x < 0 || x >= w) return false;
	if (y < 0 || y >= m) return false;
	if (in[y][x] == 0) return false;
	return true;
}

//  0
// 3 1
//  2

int step() {
	if (ip.dir2 == 0) ip.y = tops[ip.y][ip.x];
	if (ip.dir2 == 1) ip.x = rights[ip.y][ip.x];
	if (ip.dir2 == 2) ip.y = bottoms[ip.y][ip.x];
	if (ip.dir2 == 3) ip.x = lefts[ip.y][ip.x];
	int cx = ip.x, cy = ip.y;
	if (ip.dir1 == 0) {ip.y = tops[ip.y][ip.x]; cy = ip.y-1;}
	if (ip.dir1 == 1) {ip.x = rights[ip.y][ip.x]; cx = ip.x+1;}
	if (ip.dir1 == 2) {ip.y = bottoms[ip.y][ip.x]; cy = ip.y+1;}
	if (ip.dir1 == 3) {ip.x = lefts[ip.y][ip.x]; cx = ip.x-1;}
	if (valid(cx, cy)) {
		ip.x = cx; ip.y = cy;
		return 1;
	} else {
		int d1 = ip.dir1, d2 = ip.dir2;
		ip.dir1 = ndir1[d1][d2];
		ip.dir2 = ndir2[d1][d2];
		return 0;
	}
}

int main() {
	scanf("%d%d", &m, &n);
	char asdf; scanf("%c", &asdf);
	REP(i,m){
		gets(in[i]);
	}
	w = strlen(in[0]);
	REP(i,m)REP(j,w)in[i][j]-='0';
	REP(i,80) {
		tops[0][i] = 0;
		lefts[i][0] = 0;
		rights[i][w-1] = w-1;
		bottoms[m-1][i] = m-1;
	}
	REP(x,w) {
		FOR2(i,m-2,0) {
			if (in[i][x] == in[i+1][x]) bottoms[i][x] = bottoms[i+1][x];
			else bottoms[i][x] = i;
		}
		FOR(i,1,m-1) {
			if (in[i][x] == in[i-1][x]) tops[i][x] = tops[i-1][x];
			else tops[i][x] = i;
		}
	}
	REP(y,m) {
		FOR2(i,w-2,0) {
			if (in[y][i] == in[y][i+1]) rights[y][i] = rights[y][i+1];
			else rights[y][i] = i;
		}
		FOR(i,1,w-1) {
			if (in[y][i] == in[y][i-1]) lefts[y][i] = lefts[y][i-1];
			else lefts[y][i] = i;
		}
	}
	//printf("%d\n", rights[0][3]);
	ip.x = ip.y = 0;
	ip.dir1 = 1; ip.dir2 = 0;
	while (n) {
		step();
		--n;
		//printf("%d: %d,%d   %d\n", n, ip.x, ip.y, (int)in[ip.y][ip.x]);
	}
	printf("%d\n", (int)in[ip.y][ip.x]);
	return 0;
}