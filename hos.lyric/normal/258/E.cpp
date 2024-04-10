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

#define MAXN 200010
#define MAXM 400010
#define MAXK 200010

int N, K;
int m, ptr[MAXN], next[MAXM], zu[MAXM];
int A[MAXK], B[MAXK];
vint ks[MAXN];

int esLen;
pint es[MAXN * 2];
int posL[MAXN], posR[MAXN];

void dfs(int u, int p) {
	int i, v;
	es[esLen++] = mp(u, +1);
	for (i = ptr[u]; ~i; i = next[i]) {
		v = zu[i];
		if (v != p) {
			dfs(v, u);
		}
	}
	es[esLen++] = mp(u, -1);
}

int segP[MAXN * 4], segQ[MAXN * 4];
void segAdd(int u, int x, int y, int a, int b, int val) {
	chmax(a, x);
	chmin(b, y);
	if (a >= b) {
		return;
	}
	int uL = u * 2 + 0;
	int uR = u * 2 + 1;
	int z = (x + y) / 2;
	if (a == x && b == y) {
		segP[u] += val;
	} else {
		segAdd(uL, x, z, a, b, val);
		segAdd(uR, z, y, a, b, val);
	}
	segQ[u] = (segP[u] > 0) ? (y - x) : (y - x > 1) ? (segQ[uL] + segQ[uR]) : 0;
}
int segCount(int u, int x, int y, int a, int b) {
	chmax(a, x);
	chmin(b, y);
	if (a >= b) {
		return 0;
	}
	int uL = u * 2 + 0;
	int uR = u * 2 + 1;
	int z = (x + y) / 2;
	if (a == x && b == y) {
		return segQ[u];
	}
	int sum = 0;
	sum += segCount(uL, x, z, a, b);
	sum += segCount(uR, z, y, a, b);
	return sum;
}
void segAdd(int a, int b, int val) {
// cout<<"add "<<a<<" "<<b<<" "<<val<<endl;
	segAdd(1, 0, esLen, a, b + 1, val);
// cout<<"segP : ";pv(segP,segP+32);
}
int segCount(int a, int b) {
// cout<<"count "<<a<<" "<<b<<" : "<<segCount(1,0,esLen,a,b+1)<<endl;
	return segCount(1, 0, esLen, a, b + 1);
}

int ans[MAXN];

int main() {
	int i, u, v;
	int k;
	
	for (; ~scanf("%d%d", &N, &K); ) {
		m = 0;
		memset(ptr, ~0, N << 2);
		for (i = 0; i < N - 1; ++i) {
			u = in() - 1;
			v = in() - 1;
			next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
			next[m] = ptr[v]; ptr[v] = m; zu[m] = u; ++m;
		}
		for (u = 0; u < N; ++u) {
			ks[u].clear();
		}
		for (k = 0; k < K; ++k) {
			A[k] = in() - 1;
			B[k] = in() - 1;
			ks[A[k]].push_back(k);
			ks[B[k]].push_back(k);
		}
		
		esLen = 0;
		dfs(0, -1);
// for(i=0;i<esLen;++i)cout<<"("<<es[i].first<<", "<<es[i].second<<")";cout<<endl;
		for (i = 0; i < esLen; ++i) {
			u = es[i].first;
			if (es[i].second > 0) {
				posL[u] = i;
			} else {
				posR[u] = i;
			}
		}
// cout<<"posL : ";pv(posL,posL+N);
// cout<<"posR : ";pv(posR,posR+N);
		
		memset(segP, 0, sizeof(segP));
		memset(segQ, 0, sizeof(segQ));
		for (i = 0; i < esLen; ++i) {
			u = es[i].first;
			if (es[i].second > 0) {
				for (uint j = 0; j < ks[u].size(); ++j) {
					k = ks[u][j];
					segAdd(posL[A[k]], posR[A[k]], +1);
					segAdd(posL[B[k]], posR[B[k]], +1);
				}
				ans[u] = segCount(0, esLen - 1);
			} else {
				for (uint j = 0; j < ks[u].size(); ++j) {
					k = ks[u][j];
					segAdd(posL[A[k]], posR[A[k]], -1);
					segAdd(posL[B[k]], posR[B[k]], -1);
				}
			}
		}
		
		for (u = 0; u < N; ++u) {
			if (u) printf(" ");
			printf("%d", ans[u] ? (ans[u] / 2 - 1) : 0);
		}
		puts("");
	}
	
	return 0;
}