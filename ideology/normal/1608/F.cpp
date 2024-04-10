#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int P = 998244353;

int norm(int x) { return x >= P ? x - P : x; }
int reduce(int x) { return x < 0 ? x + P : x; }
int neg(int x) { return x ? P - x : 0; }
void add(int& x, int y) { if ((x += y - P) < 0) x += P; }
void sub(int& x, int y) { if ((x -= y) < 0) x += P; }
void fam(int& x, int y, int z) { x = (x + y * (ull)z) % P; }
int mpow(int x, unsigned k) {
	if (k == 0) return 1;
	int ret = mpow(x * (ull)x % P, k >> 1);
	if (k & 1) ret = ret * (ull)x % P;
	return ret;
}
int quo2(int x) { return ((x & 1) ? x + P : x) >> 1; }

int dp[2010][105], tmp[2010][105], pmt[2010][105];
int b[2010];
int C[2010][2010], fac[2010], ifac[2010];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, K; cin >> N >> K;
	for (int i = 1; i <= N; ++i) cin >> b[i];

	fac[0] = 1; for (int i = 1; i <= N; ++i) fac[i] = fac[i - 1] * (ull)i % P;
	ifac[N] = mpow(fac[N], P - 2); for (int i = N; i; --i) ifac[i - 1] = ifac[i] * (ull)i % P;

	dp[0][K] = 1;
	for (int i = 1; i <= N; ++i) {
		int L = b[i - 1] - K, R = b[i - 1] + K;
		int L1 = b[i] - K, R1 = b[i] + K;
		memset(tmp, 0, sizeof(tmp));
		memset(pmt, 0, sizeof(pmt));
		for (int j = 0; j != i; ++j) {
			for (int l = L; l <= R; ++l) {
				add(tmp[j][l - L], dp[j][l - L] * (ull)(l + j) % P);
				add(tmp[j + 1][l - L], dp[j][l - L]);
				if (l <= R1) {
					if (l >= L1) {
						add(pmt[j][l - L1 + 1], dp[j][l - L]);
					} else if (j >= L1 - l - 1) {
						add(pmt[j - (L1 - l - 1)][0], dp[j][l - L] * (ull)fac[j] % P * ifac[j - (L1 - l - 1)] % P);
					}
				}
			}
		}
		for (int j = i; j >= 0; --j)
			for (int k = 1; k <= K * 2; ++k)
				add(pmt[j][k], pmt[j + 1][k - 1] * (ull)(j + 1) % P);
		for (int j = 0; j <= i; ++j)
			for (int k = L; k <= R; ++k)
				if (k >= L1 && k <= R1) add(pmt[j][k - L1], tmp[j][k - L]);
		memcpy(dp, pmt, sizeof(pmt));
		
		// for (int j = 0; j <= i; ++j) for (int k = 0; k <= K * 2; ++k)
			// cout << dp[j][k] << " \n"[k == K * 2]; cout << '\n';
	}

	for (int i = 0; i <= N; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) C[i][j] = norm(C[i - 1][j - 1] + C[i - 1][j]);
	}

	int t = b[N] - K, L = max(0, b[N] - K), R = min(N, b[N] + K);
	int ans = 0;
	for (int i = 0; i <= N; ++i)
		for (int j = L; j <= R; ++j)
			ans = (ans + dp[i][j - t] * (ull)C[N - j][i] % P * fac[i]) % P;
	cout << ans << '\n';

	return 0;
}