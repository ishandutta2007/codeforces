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

typedef long double Double;

const int LIM = 50 * 50 + 5;

int N, P;
int A[60];

Double fac[60];
Double dp[60][LIM + 10];

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
		for (int i = 0; i < N; ++i) {
			A[i] = in();
		}
		P = in();
		
		if (accumulate(A, A + N, 0) <= P) {
			printf("%d\n", N);
			continue;
		}
		
		fac[0] = 1.0;
		for (int i = 1; i <= N; ++i) {
			fac[i] = fac[i - 1] * i;
		}
		
		for (int k = 0; k <= N; ++k) {
			fill(dp[k], dp[k] + LIM, 0.0);
		}
		dp[0][0] = 1.0;
		for (int i = 0; i < N; ++i) {
			for (int k = N; k > 0; --k) for (int x = A[i]; x < LIM; ++x) {
				dp[k][x] += dp[k - 1][x - A[i]];
			}
		}
		
		Double ans = 0.0;
		for (int i = 0; i < N; ++i) {
			//	remove
			for (int k = 1; k <= N; ++k) for (int x = A[i]; x < LIM; ++x) {
				dp[k][x] -= dp[k - 1][x - A[i]];
			}
// for(int k=0;k<=N;++k)pv(dp[k],dp[k]+10);cout<<endl;
			
			for (int k = 0; k < N; ++k) for (int x = 0; x < LIM; ++x) {
				if (x <= P && P < x + A[i]) {
					ans += (dp[k][x] * fac[k] * fac[N - 1 - k] / fac[N]) * k;
				}
			}
			
			//	revert
			for (int k = N; k > 0; --k) for (int x = A[i]; x < LIM; ++x) {
				dp[k][x] += dp[k - 1][x - A[i]];
			}
		}
		printf("%.10f\n", (double)ans);
	}
	
	return 0;
}