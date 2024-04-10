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

char buf[100010];

int N;
string A[110];
int M;
int K[110];
string B[110][110];

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
		for (int i = 0; i < N; ++i) {
			scanf("%s", buf);
			A[i] = buf;
		}
		M = in();
		for (int j = 0; j < M; ++j) {
			K[j] = in();
			for (int k = 0; k < K[j]; ++k) {
				scanf("%s", buf);
				B[j][k] = buf;
			}
		}
		int ans = -1;
		int jm = -1;
		for (int j = 0; j < M; ++j) {
			int perm[] = { 0, 1, 2, 3, };
			do {
				bool ok = true;
				int k = 0;
				for (int i = 0; i < N; ++i) {
					for (; k < K[j] && A[perm[i]] != B[j][k]; ++k);
					if (k == K[j]) {
						ok = false;
						break;
					}
				}
				if (ok) {
					int tmp = N * (N - 1) / 2 + 1;
					for (int i = 0; i < N; ++i) for (int ii = i + 1; ii < N; ++ii) {
						if (perm[i] > perm[ii]) {
							--tmp;
						}
					}
					if (ans < tmp) {
						ans = tmp;
						jm = j;
					}
				}
			} while (next_permutation(perm, perm + N));
		}
		if (!~jm) {
			puts("Brand new problem!");
		} else {
			printf("%d\n", jm + 1);
			printf("[:%s:]\n", string(ans, '|').c_str());
		}
	}
	
	return 0;
}