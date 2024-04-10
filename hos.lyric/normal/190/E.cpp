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

#define MAXN  500010
#define MAXM 2000010

int N, M;
int m, ptr[MAXN], next[MAXM], zu[MAXM];

bool vis[MAXN];
int flg[MAXN];
vector<vint> comps;

int main() {
	int i, u, v;
	int z, c;
	
	for (; ~scanf("%d%d", &N, &M); ) {
		m = 0;
		memset(ptr, ~0, N << 2);
		for (i = 0; i < M; ++i) {
			u = in() - 1;
			v = in() - 1;
			next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
			next[m] = ptr[v]; ptr[v] = m; zu[m] = u; ++m;
		}
		memset(vis, 0, sizeof(vis));
		memset(flg, 0, sizeof(flg));
		comps.clear();
		priority_queue< pint,vector<pint>,greater<pint> > q;
		for (u = 0; u < N; ++u) {
			q.push(mp(flg[u], u));
		}
		for (z = 0; !q.empty(); ) {
			c = q.top().first;
			u = q.top().second;
			q.pop();
			if (flg[u] != c) continue;
			vis[u] = 1;
			if (c == z++) {
				comps.push_back(vint());
			}
			comps.back().push_back(u);
			for (i = ptr[u]; ~i; i = next[i]) {
				v = zu[i];
				if (!vis[v]) {
					q.push(mp(++flg[v], v));
				}
			}
		}
		printf("%u\n", comps.size());
		for (uint x = 0; x < comps.size(); ++x) {
			printf("%u", comps[x].size());
			for (uint y = 0; y < comps[x].size(); ++y) {
				printf(" %d", comps[x][y] + 1);
			}
			puts("");
		}
	}
	
	return 0;
}