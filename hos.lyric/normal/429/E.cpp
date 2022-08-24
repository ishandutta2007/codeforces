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
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<typename T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int N;
int A[100010], B[100010];
int psLen;
pint ps[200010];

int n;
int m, ptr[200010], nxt[400010], zu[400010];
int col[200010];

void ae(int u, int v) {
// cout<<"ae "<<u<<" "<<v<<endl;
	nxt[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
	nxt[m] = ptr[v]; ptr[v] = m; zu[m] = u; ++m;
}

void dfs(int u, int color) {
	if (~col[u]) {
		assert(col[u] == color);
		return;
	}
	col[u] = color;
	for (int i = ptr[u]; ~i; i = nxt[i]) {
		const int v = zu[i];
		dfs(v, color ^ 1);
	}
}

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
		for (int i = 0; i < N; ++i) {
			A[i] = in();
			B[i] = in() + 1;
		}
		n = N * 2;
		m = 0;
		fill_n(ptr, n, -1);
#define IN(i)  ((i) * 2)
#define OUT(i)  ((i) * 2 + 1)
		psLen = 0;
		for (int i = 0; i < N; ++i) {
			ps[psLen++] = mp(A[i], IN(i));
			ps[psLen++] = mp(B[i], OUT(i));
		}
		sort(ps, ps + psLen);
		for (int i = 0; i < N; ++i) {
			ae(IN(i), OUT(i));
		}
		for (int j = 0; j + 1 < psLen; j += 2) {
			ae(ps[j].second, ps[j + 1].second);
		}
		fill_n(col, n, -1);
		for (int u = 0; u < n; ++u) if (!~col[u]) {
			dfs(u, 0);
		}
		for (int i = 0; i < N; ++i) {
			if (i) printf(" ");
			printf("%d", col[IN(i)]);
		}
		puts("");
	}
	
	return 0;
}