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

#define MAXN 2010

int N;
int A[MAXN], B[MAXN];
bool G[MAXN][MAXN];

int L[MAXN], M[MAXN];
bool S[MAXN];
int cnt[MAXN];

bool solve(int k) {
// cout<<"**** k = "<<k<<" ****"<<endl;
	int u;
	for (u = 0; u < N; ++u) {
		L[u] = 0;
		M[u] = N;
		S[u] = 1;
	}
	int q = 0, j;
	for (; ; ) {
		int um = -1;
		for (u = 0; u < N; ++u) if (S[u]) {
			if (!~um || B[um] > B[u]) {
				um = u;
			}
		}
// cout<<"um = "<<um<<endl;
		L[um] = ++q;
		if (q == N) {
			return 1;
		}
		for (u = 0; u < N; ++u) if (!L[u]) {
			if (G[um][u] && M[u] == N) {
				M[u] = min(L[um] + k, N);
			}
		}
		memset(cnt, 0, (N + 1) * 4);
		for (u = 0; u < N; ++u) if (!L[u]) {
			++cnt[max(M[u] - q, 0)];
		}
		for (j = 1; j <= N; ++j) {
			cnt[j] += cnt[j - 1];
		}
// cout<<"L : ";pv(L,L+N);
// cout<<"M : ";pv(M,M+N);
// cout<<"cnt : ";pv(cnt,cnt+N+1);
		for (j = max(k - q + 1, 0); j <= N; ++j) {
			if (cnt[j] > j) {
				return 0;
			}
		}
		for (j = max(k - q + 1, 1); j <= N; ++j) {
			if (cnt[j] == j) {
				break;
			}
		}
		for (u = 0; u < N; ++u) {
			S[u] = !L[u] && (M[u] <= q + j);
		}
// cout<<"j = "<<j<<endl;
// cout<<"S : ";pv(S,S+N);
	}
}


int perm[MAXN];

int brute() {
	int u, v;
	for (u = 0; u < N; ++u) {
		perm[u] = u;
	}
	int opt = N;
	do {
		int tmp = 0;
		for (u = 0; u < N; ++u) for (v = u + 1; v < N; ++v) if (G[u][v]) {
			chmax(tmp, abs(perm[u] - perm[v]));
		}
		chmin(opt, tmp);
	} while (next_permutation(perm, perm + N));
	return opt;
}

int ans[MAXN];

int main() {
	int u, v;
	int q;
	
	for (; ~scanf("%d", &N); ) {
		for (u = 0; u < N; ++u) {
			A[u] = in();
			B[u] = in();
		}
		for (u = 0; u < N; ++u) for (v = 0; v < N; ++v) if (u != v) {
			G[u][v] = (A[u] <= B[v] && A[v] <= B[u]);
		}
		int lo = -1, ho = N - 1;
		for (; lo + 1 < ho; ) {
			int mo = (lo + ho) / 2;
			(solve(mo) ? ho : lo) = mo;
		}
		solve(ho);
// cout<<"k = "<<ho<<endl;
// cout<<"L : ";pv(L,L+N);
// assert(ho==brute());
for(u=0;u<N;++u)for(v=u+1;v<N;++v)if(G[u][v])assert(abs(L[u]-L[v])<=ho);
		for (u = 0; u < N; ++u) {
			ans[L[u]] = u;
		}
		for (q = 1; q <= N; ++q) {
			if (q > 1) printf(" ");
			printf("%d", ans[q] + 1);
		}
		puts("");
	}
	
	return 0;
}