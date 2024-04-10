#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

using Int = __int128;
const Int INF = (Int)1e36;
const int A = 10;
vector<int> a[A];
Int dp[A + 1][A];
int par[A + 1][A][2];
int want;

Int mult(Int x, Int y) {
	if (2 * INF / x < y) return INF;
	return min(INF, x * y);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d%d", &n, &want);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[x % A].push_back(x);
	}
	for (int x = 0; x < A; x++)
		sort(all(a[x]));
	for (int i = 0; i <= A; i++)
		for (int x = 0; x < A; x++)
			dp[i][x] = INF;
	dp[0][1] = 1;
	for (int x = 0; x < A; x++) {
		for (int y = 0; y < A; y++) {
			if (dp[x][y] == INF) continue;
			if ((x % 2 == 0 && want % 2 != 0) || (x % 5 == 0 && want % 5 != 0)) {
				if (dp[x + 1][y] > dp[x][y]) {
					dp[x + 1][y] = dp[x][y];
					par[x + 1][y][0] = y;
					par[x + 1][y][1] = (int)a[x].size();
				}
				continue;
			}
			int k = min(4, (int)a[x].size());
			int q = ((int)a[x].size() - k) % 4;
			if (q == 0 && k != (int)a[x].size()) q = 4;
			int z = y;
			for (int i = 0; i < q; i++)
				z = (z * x) % A;
			Int nCost = 1;
			for (int i = 0; i < k; i++)
				nCost *= a[x][i];
			for (int i = k; i >= 0; i--) {
				Int w = mult(dp[x][y], nCost);
				if (dp[x + 1][z] > w) {
					dp[x + 1][z] = w;
					par[x + 1][z][0] = y;
					par[x + 1][z][1] = i;
				}
				if (i > 0) {
					nCost /= a[x][i - 1];
					z = (z * x) % A;
				}
			}
		}
	}
	if (dp[A][want] == INF) {
		printf("-1\n");
		return 0;
	}
	vector<int> res;
	int y = want;
	for (int x = A - 1; x >= 0; x--) {
		int k = par[x + 1][y][1];
		y = par[x + 1][y][0];
		for (int i = k; i < (int)a[x].size(); i++)
			res.push_back(a[x][i]);
	}
	if (res.empty()) {
		if (!a[1].empty()) {
			printf("1\n%d\n", a[1][0]);
		} else {
			printf("-1\n");
		}
		return 0;
	}
	printf("%d\n", (int)res.size());
	for (int x : res)
		printf("%d ", x);
	printf("\n");

	return 0;
}