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
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
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

const int N = 300300;
pll a[N];
ll xs[N];
int m;
int n;
ll v;
int c[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &v);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i].first);
	m = 0;
	for (int i = 0; i < n; i++) {
		ll x = a[i].first * v, y;
		scanf("%lld", &y);
		if (abs(y) > x) continue;
		a[m++] = mp(x - y, x + y);
	}
	n = m;
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		xs[i] = a[i].second;
	sort(xs, xs + n);
	m = unique(xs, xs + n) - xs;
	c[0] = -1;
	for (int i = 1; i <= n; i++)
		c[i] = N;
	for (int i = 0; i < n; i++) {
		int x = lower_bound(xs, xs + n, a[i].second) - xs;
		int p = upper_bound(c, c + n + 1, x) - c;
		c[p] = x;
	}
	int ans = n;
	while(c[ans] == N) ans--;
	printf("%d\n", ans);

	return 0;
}