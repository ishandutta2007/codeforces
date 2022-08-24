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

#define MAX 600010

char buf[MAX];

int N;
int P[MAX];
string S[MAX];

int L;
char T[MAX];

int ptr[MAX], next[MAX];

int fail[MAX];

int ans;

void dfs(int u, int m0) {
	int v;
	for (v = ptr[u]; ~v; v = next[v]) {
		int m = m0;
		int sz = S[v].size(), j;
		for (j = 0; j < sz; ++j) {
			for (; ~m && T[m] != S[v][j]; m = fail[m]);
			if (++m == L) {
				++ans;
				m = fail[m];
			}
		}
		dfs(v, m);
	}
}

int main() {
	int u, v;
	int l, m;
	
	for (; ~scanf("%d", &N); ) {
		P[0] = 0;
		S[0] = "";
		for (v = 1; v < N; ++v) {
			P[v] = in() - 1;
			scanf("%s", buf);
			S[v] = buf;
		}
		scanf("%s", T);
		L = strlen(T);
		
		memset(ptr, ~0, sizeof(ptr));
		for (v = 1; v < N; ++v) {
			u = P[v];
			next[v] = ptr[u]; ptr[u] = v;
		}
// for(u=0;u<N;++u){for(v=ptr[u];~v;v=next[v])cout<<v<<" ";cout<<endl;}
		
		m = fail[0] = -1;
		for (l = 0; l < L; ++l) {
			for (; ~m && T[m] != T[l]; m = fail[m]);
			fail[l + 1] = ++m;
		}
// cout<<"fail : ";pv(fail,fail+L+1);
		
		ans = 0;
		dfs(0, 0);
		printf("%d\n", ans);
	}
	
	return 0;
}