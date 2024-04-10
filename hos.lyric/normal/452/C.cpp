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

const int LIM = 1000 * 1000 + 5;
long double logFac[LIM + 10];

void prepare() {
	logFac[0] = 0.0;
	for (int i = 1; i < LIM; ++i) {
		logFac[i] = logFac[i - 1] + log((long double)i);
	}
}

long double logBinom(int n, int k) {
	assert(0 <= k && k <= n);
	return logFac[n] - logFac[k] - logFac[n - k];
}

int N, M;

int main() {
	prepare();
	
	for (; ~scanf("%d%d", &N, &M); ) {
		/*
			C(M, k) C((N - 1) M, N - k) / C(N M, N)
		*/
		long double sum = 0.0;
		for (int k = 0; k <= N; ++k) {
			if (0 <= k && k <= M) 
			if (0 <= N - k && N - k <= (N - 1) * M) 
			if (0 <= N && N <= N * M) 
			{
				long double logProb = 0.0;
				logProb += logBinom(M, k);
				logProb += logBinom((N - 1) * M, N - k);
				logProb -= logBinom(N * M, N);
				const long double succ = k / (long double)N;
				sum += exp(logProb) * succ * succ;
			}
		}
		const long double ans = sum * N;
		printf("%.10f\n", (double)ans);
	}
	
	return 0;
}