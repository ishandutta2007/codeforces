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

const Int MO = 1000000007;
Int bn[110][110];

const int LIM = 100000;
const int L = 11;
int CNT[110];

int luck(int n) {
	int ret = 0;
	for (; n; n /= 10) {
		if (n % 10 == 4 || n % 10 == 7) {
			++ret;
		}
	}
	return ret;
}

void prepare() {
	int i, j;
	for (i = 0; i < 105; ++i) {
		bn[i][0] = bn[i][i] = 1;
		for (j = 1; j < i; ++j) {
			bn[i][j] = (bn[i - 1][j - 1] + bn[i - 1][j]) % MO;
		}
	}
	
	int n;
	for (n = 0; n < 100000; ++n) {
		++CNT[luck(n)];
	}
}

Int downFact(Int n, int k) {
	Int ret = 1;
	int i;
	for (i = 0; i < k; ++i) {
		(ret *= (n - i)) %= MO;
	}
	return ret;
}

Int M;
Int A[110];

const int P = 6;
Int dp[110][110][110];

int main() {
	int k, n;
	int i, j, p, q;
	
	prepare();
	
	for (; cin >> M; ) {
		memset(A, 0, sizeof(A));
		for (k = 0; k < M / LIM; ++k) {
			int l = luck(k);
			for (i = l; i < L; ++i) {
				A[i] += CNT[i - l];
			}
		}
		--A[luck(0)];
		for (n = M / LIM * LIM; n <= M; ++n) {
			++A[luck(n)];
		}
// cout<<"A : ";pv(A,A+L);
// cout<<M<<" == "<<accumulate(A,A+L,0)<<endl;
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		for (i = 0; i < L; ++i) for (p = 0; p <= P; ++p) for (j = 0; j < L; ++j) {
			for (q = 0; p + q <= P; ++q) {
				(dp[i + 1][p + q][j + i * q] += dp[i][p][j] * (bn[P - p][q] * downFact(A[i], q) % MO)) %= MO;
			}
		}
		Int ans = 0;
		for (i = 0; i < L; ++i) {
			for (j = 0; j < i; ++j) {
				(ans += dp[L][P][j] * A[i]) %= MO;
			}
		}
		ans = (ans % MO + MO) % MO;
		cout << ans << endl;
	}
	
	return 0;
}