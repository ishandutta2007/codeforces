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

int N, M, K;
bool is[20010][20];
int sent[20010];
int mess[20];

int main() {
	
	
	for (; ~scanf("%d%d%d", &N, &M, &K); ) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				is[i][j] = in();
			}
		}
		memset(sent, 0, sizeof(sent));
		memset(mess, 0, sizeof(mess));
		for (int k = 0; k < K; ++k) {
			const int i = in() - 1;
			const int j = in() - 1;
			++sent[i];
			++mess[j];
		}
		for (int i = 0; i < N; ++i) {
			int ans = -sent[i];
			for (int j = 0; j < M; ++j) if (is[i][j]) {
				ans += mess[j];
			}
			if (i) printf(" ");
			printf("%d", ans);
		}
		puts("");
	}
	
	return 0;
}