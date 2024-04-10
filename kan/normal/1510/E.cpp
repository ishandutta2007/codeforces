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

const int N = 56;
const int M = N * N;
map<pii, ll> mapchik[N][M];
int forM[M][2];
int n;

double sqr(double x) {
	return x * x;
}
bool close(double x1, double y1, double x2, double y2) {
	return sqrt(sqr(x1 - x2) + sqr(y1 - y2)) < 1e-8;
}
int myRound(double x) {
	int y = (int)(x + 0.5);
	return y;
}
void read() {
	double x, y;
	scanf("%d%lf%lf", &n, &x, &y);
	for (int m = 1; m <= n * n; m++) {
		int X = myRound(3 * x * m), Y = myRound(3 * y * m);
		if (!close(x, y, (double)X / (3 * m), (double)Y / (3 * m))) {
			X = Y = -1;
		}
		forM[m][0] = X;
		forM[m][1] = Y;
	}
}

void brute1(int p, int end, ll mask, int bal, int mm, int mx, int my) {
	if (bal < 0 || bal > n - p) return;
	if (p == end) {
		//eprintf("%d %d %d %d -- %lld\n", bal, mm, mx, my, mask);
		mapchik[bal][mm][mp(mx, my)] = mask;
		return;
	}
	for (int f = -1; f < 2; f += 2) {
		ll nmask = mask;
		if (f == 1) nmask ^= 1LL << p;
		int nbal = bal + f;
		int nmm = mm + 2 * bal + f;
		int nmx = mx + 3 * (2 * p + 1) * bal + f * (3 * p + 2);
		int nmy = my + 3 * bal * bal + f * (3 * bal + f);
		brute1(p + 1, end, nmask, nbal, nmm, nmx, nmy);
	}
}

void tryFind(ll mask, int bal, int mm, int mx, int my) {
	for (int totm = mm; totm <= n * n; totm++) {
		if (forM[totm][0] == -1) continue;
		int wx = forM[totm][0] - mx, wy = forM[totm][1] - my;
		if (wx < 0 || wy < 0) continue;
		if (mapchik[bal][totm - mm].count(mp(wx, wy))) {
			mask |= mapchik[bal][totm - mm][mp(wx, wy)];
			for (int i = 0; i < n; i++) {
				if ((mask >> i) & 1) {
					printf("(");
				} else {
					printf(")");
				}
			}
			printf("\n");
			exit(0);
		}
	}
}

void brute2(int p, int end, ll mask, int bal, int mm, int mx, int my) {
	if (bal < 0) return;
	if (p == end) {
		//eprintf("%d %d %d %d -- %lld\n", bal, mm, mx, my, mask);
		tryFind(mask, bal, mm, mx, my);
		return;
	}
	p--;
	for (int f = -1; f < 2; f += 2) {
		ll nmask = mask;
		if (f == -1) nmask ^= 1LL << p;
		int nbal = bal + f;
		int nmm = mm + 2 * bal + f;
		int nmx = mx + 3 * (2 * p + 1) * bal + f * (3 * p + 1);
		int nmy = my + 3 * bal * bal + f * (3 * bal + f);
		brute2(p, end, nmask, nbal, nmm, nmx, nmy);
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	int mid = min(22, n);
	brute1(0, mid, 0, 0, 0, 0, 0);
	eprintf("----------\n");
	brute2(n, mid, 0, 0, 0, 0, 0);
	assert(false);

	return 0;
}