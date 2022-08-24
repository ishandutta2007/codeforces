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

int K;
int S, T, N, L;
bool G[1010][1010];

int ssLen;
int ss[110];

int main() {
	int i;
	int j, u, v;
	
	for (; ~scanf("%d", &K); ) {
		ssLen = 0;
		for (int k = K; k; k >>= 1) {
			if (k & 1) {
				ss[ssLen++] = 1;
			}
			ss[ssLen++] = 0;
		}
		reverse(ss, ss + ssLen);
// cout<<"ss : ";pv(ss,ss+ssLen);
		
		S = 2;
		T = 3;
		N = 4;
		L = 1;
		memset(G, 0, sizeof(G));
		G[S][T] = G[T][S] = 1;
		
		for (i = 2; i < ssLen; ++i) {
			switch (ss[i]) {
				case 0: {
					//	x 2
					for (j = 0; j < 2; ++j) {
						G[T][N + j] = G[N + j][T] = 1;
						G[N + 2][N + j] = G[N + j][N + 2] = 1;
					}
					T = N + 2;
					N += 3;
					L += 2;
				} break;
				case 1: {
					//	+ 1
					for (j = 0; j < L; ++j) {
						u = (j == 0) ? S : (N + j - 1);
						v = (j == L - 1) ? T : (N + j);
						G[u][v] = G[v][u] = 1;
					}
					N += L - 1;
				} break;
				default: assert(0);
			}
		}
		
		G[0][S] = G[S][0] = 1;
		G[1][T] = G[T][1] = 1;
		
// for(u=0;u<N;++u)for(v=u+1;v<N;++v)if(G[u][v])cout<<u<<" "<<v<<endl;
		printf("%d\n", N);
		for (u = 0; u < N; ++u) {
			for (v = 0; v < N; ++v) {
				putchar(G[u][v] ? 'Y' : 'N');
			}
			puts("");
		}
	}
	
	return 0;
}