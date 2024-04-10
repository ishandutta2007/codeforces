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
#include <queue>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 600600;
int n, m;
int a[N];
int s[N];
int z[N];
int ans[N];
int ansSz;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	a[n] = a[0] + m;
	for (int i = 0; i < n; i++)
		s[i] = a[i + 1] - a[i];
	s[n] = -1;
	for (int i = 0; i < n; i++)
		s[2 * n - i] = s[i];
	for (int i = 2 * n + 1; i <= 3 * n; i++)
		s[i] = s[i - n];
	int l = 0, r = 0;
	for (int i = 1; i <= 3 * n; i++) {
		if (i < r)
			z[i] = z[i - l];
		while(i + z[i] <= 3 * n && s[i + z[i]] == s[z[i]]) z[i]++;
		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}
	for (int i = n + 1; i <= 2 * n; i++) {
		if (z[i] < n) continue;
		ans[ansSz++] = ((ll)a[0] + a[2 * n - i + 1]) % m;
	}
	sort(ans, ans + ansSz);
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d ", ans[i]);
	if (ansSz > 0) printf("\n");

	return 0;
}