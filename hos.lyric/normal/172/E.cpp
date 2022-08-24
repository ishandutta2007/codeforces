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

#define MAXV 250010

Int enc(char *s, char *t) {
	Int ret = 0;
	for (char *it = s; it != t; ++it) if (*it != '/') {
		ret = ret * 27 + (*it - 'a' + 1);
	}
	return ret;
}

int V, E, ptr[MAXV], next[MAXV], zu[MAXV];
Int P[MAXV];

char S[1000010];
int stackLen;
int stack[MAXV];

int N;
Int A[210];
int fail[210];

int ans;
void dfs(int u, int j) {
	if (P[u] == A[j]) ++j;
	if (j == N && P[u] == A[N - 1]) ++ans;
	for (int i = ptr[u]; ~i; i = next[i]) {
		dfs(zu[i], j);
	}
}

int main() {
	int i, j;
	int u, v;
	
	for (; gets(S); ) {
// cout<<"S = "<<S<<endl;
		memset(ptr, ~0, sizeof(ptr));
		V = 1;
		E = 0;
		P[0] = -2;
		stackLen = 0;
		stack[stackLen++] = 0;
		for (i = 0; S[i]; i = j + 1) {
			for (j = i; S[j] != '>'; ++j);
// cout<<i<<" "<<j<<endl;
			Int val = enc(S + i + 1, S + j);
			bool isOpen = 0, isClose = 0;
			if (S[j - 1] == '/') {
				//	self
				isOpen = isClose = 1;
			} else if (S[i + 1] == '/') {
				//	close
				isClose = 1;
			} else {
				//	open
				isOpen = 1;
			}
			if (isOpen) {
				v = V++;
				u = stack[stackLen - 1];
				P[v] = val;
// cout<<"edge "<<P[u]<<" "<<P[v]<<endl;
				next[E] = ptr[u]; ptr[u] = E; zu[E] = v; ++E;
				stack[stackLen++] = v;
			}
			if (isClose) {
				--stackLen;
			}
		}
		for (int qry = atoi(gets(S)); qry--; ) {
			gets(S);
			S[strlen(S) + 1] = 0;
			N = 0;
			for (i = 0; S[i]; i = j + 1) {
				for (j = i; islower(S[j]); ++j);
				A[N++] = enc(S + i, S + j);
			}
			A[N] = -1;
// cout<<"A : ";pv(A,A+N);
			ans = 0;
			dfs(0, 0);
			printf("%d\n", ans);
		}
	}
	
	return 0;
}