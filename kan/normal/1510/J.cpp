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

const int N = 100100;
int n;
char s[N];
vector<int> a;
bool hv[N];

void printAns(int k) {
	vector<int> ans;
	for (int i = 0; i < (int)a.size(); i++) {
		if (i % 2 == 0) {
			if (k == 1) {
				assert(a[i] == 1);
			} else if (k == 2) {
				assert(a[i] % 2 == 0);
				for (int j = 1; j < a[i] / 2; j++)
					ans.push_back(1);
			} else {
				if (a[i] == k) continue;
				assert(a[i] >= k + 2);
				int x = a[i] - k;
				while(x > 0) {
					int z = x % k;
					if (z != 0)
						z = min(k - 2, k - z);
					ans.push_back(k - 1 - z);
					x -= k;
					x += z;
				}
				assert(x == 0);
			}
		} else {
			ans.push_back(a[i] + k - 1);
		}
	}
	printf("%d\n", (int)ans.size());
	for (int x : ans)
		printf("%d ", x);
	printf("\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s", s + 1);
	n = strlen(s + 1);
	s[0] = '_';
	s[n + 1] = '_';
	int len = 0;
	for (int i = 0; i <= n + 1; i++) {
		if (i > 0 && s[i] != s[i - 1]) {
			a.push_back(len);
			len = 0;
		}
		len++;
	}
	a.push_back(len);
	assert((int)a.size() & 1);
	for (int i = 0; i < (int)a.size(); i += 2)
		hv[a[i]] = 1;
	if (hv[1]) {
		bool ok = true;
		for (int i = 2; i < N; i++)
			ok &= !hv[i];
		if (ok) {
			printAns(1);
			return 0;
		}
		printf("-1\n");
		return 0;
	}
	bool even = true;
	for (int i = 1; i < N; i += 2)
		even &= !hv[i];
	if (even) {
		printAns(2);
		return 0;
	}
	if (hv[2]) {
		printf("-1\n");
		return 0;
	}
	if (!hv[4]) {
		printAns(3);
		return 0;
	}
	if (hv[3] || hv[5]) {
		printf("-1\n");
		return 0;
	}
	printAns(4);

	return 0;
}