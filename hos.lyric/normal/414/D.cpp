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
template<class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<class T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int N, K;
Int P;

int m, ptr[100010], next[200010], zu[200010];

int que[100010], *qb, *qe;
int dist[100010];

Int cnt[100010];
Int cntSum[100010];

void bfs(int src) {
	int i;
	int u, v;
	qb = qe = que;
	for (u = 0; u < N; ++u) {
		dist[u] = -1;
	}
	dist[src] = 0;
	*qe++ = src;
	for (; qb != qe; ) {
		u = *qb++;
		for (i = ptr[u]; ~i; i = next[i]) {
			v = zu[i];
			if (!~dist[v]) {
				dist[v] = dist[u] + 1;
				*qe++ = v;
			}
		}
	}
}

int main() {
	int i;
	int u, v;
	int x, y;
	
	for (; ~scanf("%d", &N); ) {
		K = in();
		P = in();
		m = 0;
		memset(ptr, ~0, N * 4);
		for (i = 0; i < N - 1; ++i) {
			u = in() - 1;
			v = in() - 1;
			next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
			next[m] = ptr[v]; ptr[v] = m; zu[m] = u; ++m;
		}
		bfs(0);
		memset(cnt, 0, sizeof(cnt));
		for (u = 1; u < N; ++u) {
			++cnt[dist[u]];
		}
// cout<<"cnt : ";pv(cnt,cnt+N);
		for (x = 0; x < N; ++x) {
			cntSum[x + 1] = cntSum[x] + cnt[x];
		}
		
		int ans = 0;
		
		//	(y, x]
		int water = 0;
		Int coin = 0;
		y = N - 1;
		for (x = N - 1; x > 0; --x) {
			for (; y > 0 && coin + cnt[y] * (x - y) <= P; --y) {
				water += cnt[y];
				coin += cnt[y] * (x - y);
			}
// cout<<x<<" "<<y<<" : "<<water<<" "<<coin<<endl;
			int tmp = water;
			if (y > 0) {
				tmp += (P - coin) / (x - y);
			}
			chmax(ans, tmp);
			water -= cnt[x];
			coin -= water;
		}
		
		chmin(ans, K);
		printf("%d\n", ans);
	}
	
	return 0;
}