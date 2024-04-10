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
const int LIM = 1000005;
Int inv[1000010];
Int fac[1000010], fnv[1000010];
void prepare() {
	int i;
	inv[1] = 1;
	for (i = 2; i < LIM; ++i) {
		inv[i] = MO - MO / i * inv[MO % i] % MO;
assert(i*inv[i]%MO==1);
	}
	fac[0] = 1;
	fnv[0] = 1;
	for (i = 1; i < LIM; ++i) {
		fac[i] = fac[i - 1] * i % MO;
		fnv[i] = fnv[i - 1] * inv[i] % MO;
	}
assert(3628800*fnv[10]%MO==1);
}

int A, B, N;

bool isGood(int x) {
	for (; x; x /= 10) {
		if (!(x % 10 == A || x % 10 == B)) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int i;
	
	prepare();
	
	for (; ~scanf("%d%d%d", &A, &B, &N); ) {
		Int ans = 0;
		for (i = 0; i <= N; ++i) {
			if (isGood(A * i + B * (N - i))) {
				Int tmp = 1;
				(tmp *= fac[N]) %= MO;
				(tmp *= fnv[i]) %= MO;
				(tmp *= fnv[N - i]) %= MO;
				(ans += tmp) %= MO;
			}
		}
		ans = (ans % MO + MO) % MO;
		cout << ans << endl;
	}
	
	return 0;
}