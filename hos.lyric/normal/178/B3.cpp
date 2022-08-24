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

#define MAXN 100010
#define MAXM 200010

int N, M;
int m, ptr[MAXN], next[MAXM], zu[MAXM];
int R, Z, dis[MAXN], low[MAXN], par[MAXN];

void dfs0(int u, int p) {
	dis[u] = low[u] = Z++;
	par[u] = p;
	int i, v;
	for (i = ptr[u]; ~i; i = next[i]) {
		v = zu[i];
		if (v == p) continue;
		if (!~dis[v]) {
			dfs0(v, u);
			chmin(low[u], low[v]);
		} else {
			chmin(low[u], dis[v]);
		}
	}
}

int cost[MAXN];
int seqLen, seq[MAXN * 2];
int pos[MAXN];

void dfs1(int u, int c) {
	pos[u] = seqLen;
	seq[seqLen++] = c;
	int i, v;
	for (i = ptr[u]; ~i; i = next[i]) {
		v = zu[i];
		if (par[v] != u) continue;
		dfs1(v, c + cost[v]);
		seq[seqLen++] = c;
	}
}

const int INF = 1001001001;
int segN;
int seg[MAXN * 8];

void init() {
	for (segN = 1; segN < seqLen; segN <<= 1);
	int i, a;
	for (i = 0; i < segN; ++i) seg[segN + i] = (i < seqLen) ? seq[i] : INF;
	for (a = segN; --a; ) seg[a] = min(seg[a << 1], seg[a << 1 | 1]);
}
int rangeMin(int a, int b) {
	int ret = INF;
	for (a += segN, b += segN; a <= b; a >>= 1, b >>= 1) {
		if ( a & 1) { chmin(ret, seg[a]); ++a; }
		if (~b & 1) { chmin(ret, seg[b]); --b; }
	}
	return ret;
}

int main() {
	int i, u, v;
	
	for (; ~scanf("%d%d", &N, &M); ) {
		m = 0;
		memset(ptr, ~0, sizeof(ptr));
		for (i = 0; i < M; ++i) {
			u = in() - 1;
			v = in() - 1;
			next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
			next[m] = ptr[v]; ptr[v] = m; zu[m] = u; ++m;
		}
		R = 0;
		Z = 0;
		memset(dis, ~0, N << 2);
		dfs0(R, -1);
		for (v = 0; v < N; ++v) {
			cost[v] = (v != R && dis[v] <= low[v]) ? 1 : 0;
		}
// cout<<"cost : ";pv(cost,cost+N);
		seqLen = 0;
		dfs1(R, 0);
// cout<<"seq : ";pv(seq,seq+seqLen);
// cout<<"pos : ";pv(pos,pos+N);
		init();
		for (int qry = in(); qry--; ) {
			u = in() - 1;
			v = in() - 1;
			if (pos[u] > pos[v]) swap(u, v);
			int ans = seq[pos[u]] + seq[pos[v]] - rangeMin(pos[u], pos[v]) * 2;
			printf("%d\n", ans);
		}
	}
	
	return 0;
}