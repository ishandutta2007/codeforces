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


const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}


const int N = 2020;
int pref[N][N];
int a[N][4];
int C[N][N];
int n, k, r;
int ans;

int getSum(int x1, int y1, int x2, int y2) {
	if (x1 >= x2 || y1 >= y2) return 0;
	x1 = max(x1, 0);
	y1 = max(y1, 0);
	x2 = min(x2, N - 1);
	y2 = min(y2, N - 1);
	return pref[x2][y2] - pref[x2][y1] - pref[x1][y2] + pref[x1][y1];
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < N; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 1; i < N; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);

	scanf("%d%d%d", &n, &k, &r);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		pref[a[i][0]][a[i][1]]++;
		a[i][0]--;
		a[i][1]--;
	}
	for (int x = 1; x < N; x++)
		for (int y = 1; y < N; y++) {
			pref[x][y] += pref[x - 1][y] + pref[x][y - 1] - pref[x - 1][y - 1];
		}
	for (int i = 0; i < n; i++) {
		a[i][3] = getSum(a[i][0] - r, a[i][1] - r, a[i][0] + r + 1, a[i][1] + r + 1);
		ans = add(ans, mult(mult(a[i][2], a[i][2]), sub(C[n][k], C[n - a[i][3]][k])));
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			int cur = C[n][k];
			int w = getSum(max(a[i][0], a[j][0]) - r, max(a[i][1], a[j][1]) - r, min(a[i][0], a[j][0]) + r + 1, min(a[i][1], a[j][1]) + r + 1);
			cur = sub(cur, C[n - a[i][3]][k]);
			cur = sub(cur, C[n - a[j][3]][k]);
			cur = add(cur, C[n - a[i][3] - a[j][3] + w][k]);
			ans = add(ans, mult(mult(cur, 2), mult(a[i][2], a[j][2])));
		}
	printf("%d\n", ans);

	return 0;
}