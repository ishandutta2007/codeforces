#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

#define MAXN 500010

int N;
int m, ptr[MAXN], next[MAXN * 2], zu[MAXN * 2];
int zeit, dis[MAXN], fin[MAXN];
int Q;

void dfs(int u, int p) {
	int i;
	dis[u] = zeit++;
	for (i = ptr[u]; ~i; i = next[i]) if (zu[i] != p) {
		dfs(zu[i], u);
	}
	fin[u] = zeit++;
}

int segN;
int seg1[MAXN * 8];
int seg2[MAXN * 8];

void updateRange(int *seg, int a, int b, int val) {
	for (a += segN, b += segN; a <= b; a >>= 1, b >>= 1) {
		if ( a & 1) { chmax(seg[a], val); ++a; }
		if (~b & 1) { chmax(seg[b], val); --b; }
	}
}
int getMaxPoint(int *seg, int a) {
	int ret = -1;
	for (a += segN; a; a >>= 1) {
		chmax(ret, seg[a]);
	}
	return ret;
}

void updatePoint(int *seg, int a, int val) {
	for (a += segN; a; a >>= 1) {
		chmax(seg[a], val);
	}
}
int getMaxRange(int *seg, int a, int b) {
	int ret = -1;
	for (a += segN, b += segN; a <= b; a >>= 1, b >>= 1) {
		if ( a & 1) { chmax(ret, seg[a]); ++a; }
		if (~b & 1) { chmax(ret, seg[b]); --b; }
	}
	return ret;
}

int main() {
	int i, u, v;
	int q;
	
	N = in();
	m = 0;
	memset(ptr, ~0, N * 4);
	for (i = 0; i < N - 1; ++i) {
		u = in() - 1;
		v = in() - 1;
		next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
		next[m] = ptr[v]; ptr[v] = m; zu[m] = u; ++m;
	}
	zeit = 0;
	dfs(0, -1);
// cout<<"dis : ";pv(dis,dis+N);
// cout<<"fin : ";pv(fin,fin+N);
	
	for (segN = 2; segN < N * 2; segN <<= 1);
	memset(seg1, ~0, sizeof(seg1));
	memset(seg2, ~0, sizeof(seg2));
	
	Q = in();
	for (q = 0; q < Q; ++q) {
// cout<<"seg1 : ";pv(seg1+1,seg1+segN*2);
// cout<<"seg2 : ";pv(seg2+1,seg2+segN*2);
		int typ = in();
		u = in() - 1;
// cout<<"QUERY "<<typ<<" "<<u<<endl;
		switch (typ) {
			case 1: {
				//	fill
				updateRange(seg1, dis[u], fin[u], q);
			} break;
			case 2: {
				//	empty
				updatePoint(seg2, dis[u], q);
			} break;
			case 3: {
				//	question
				int res1 = getMaxPoint(seg1, dis[u]);
				int res2 = getMaxRange(seg2, dis[u], fin[u]);
				puts((res1 > res2) ? "1" : "0");
			} break;
			default: assert(0);
		}
	}
	
	return 0;
}