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

// const int P = 998244353;

// int norm(int x) { return x >= P ? x - P : x; }
// int reduce(int x) { return x < 0 ? x + P : x; }
// int neg(int x) { return x ? P - x : 0; }
// void add(int& x, int y) { if ((x += y - P) < 0) x += P; }
// void sub(int& x, int y) { if ((x -= y) < 0) x += P; }
// void fam(int& x, int y, int z) { x = (x + y * (ull)z) % P; }
// int mpow(int x, unsigned k) {
// 	if (k == 0) return 1;
// 	int ret = mpow(x * (ull)x % P, k >> 1);
// 	if (k & 1) ret = ret * (ull)x % P;
// 	return ret;
// }
// int quo2(int x) { return ((x & 1) ? x + P : x) >> 1; }

const int _ = 100010;

#define fir first
#define sec second

using pii = pair<int, int>;

int cnt[3];
pii P[3][_ / 3];

int u[_], v[_];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;
	int ans = 1;
	for (int rep = 0; rep != N; ++rep) {
		int x, y, c; cin >> x >> y >> c; --c;
		P[c][cnt[c]++] = make_pair(x, y);
	}
	for (int ROT = 0; ROT != 4; ++ROT) {
		for (int i = 0; i != 3; ++i) {
			for (int j = 0; j != N / 3; ++j) {
				swap(P[i][j].fir, P[i][j].sec);  P[i][j].sec *= -1;
			}
			sort(P[i], P[i] + N / 3);
		}
		for (int i = 0; i != 3; ++i) {
			for (int j = 0; j != 3; ++j) {
				if (j == i) continue;
				int low = ans, high = N / 3;
				while (low < high) {
					int mid = (low + high + 1) / 2;

					int thres = P[i][mid - 1].fir;
					int c1 = 0, c2 = 0;
					for (int k = 0; k != N / 3; ++k) if (P[j][k].fir > thres) {
						u[c1++] = P[j][k].sec;
					}
					for (int k = 0; k != N / 3; ++k) if (P[3 - i - j][k].fir > thres) {
						v[c2++] = P[3 - i - j][k].sec;
					}
					bool fl = true;
					if (c1 < mid || c2 < mid) fl = false;
					else {
						nth_element(u, u + mid - 1, u + c1);
						nth_element(v, v + mid - 1, v + c2, greater<int>());
						fl = u[mid - 1] < v[mid - 1];
					}
					if (fl) low = mid;
					else high = mid - 1;
				}
				ans = max(ans, low);
			}
		}
		for (int i = 0; i != 3; ++i) {
			for (int j = 0; j != 3; ++j) {
				if (j == i) continue;
				int low = ans, high = N / 3;
				while (low < high) {
					int mid = (low + high + 1) / 2;

					int thres = P[i][mid - 1].fir;
					int c1 = 0, c2 = 0;
					for (int k = 0; k != N / 3; ++k) if (P[j][k].fir > thres) {
						u[c1++] = P[j][k].fir;
					}
					for (int k = 0; k != N / 3; ++k) if (P[3 - i - j][k].fir > thres) {
						v[c2++] = P[3 - i - j][k].fir;
					}
					bool fl = true;
					if (c1 < mid || c2 < mid) fl = false;
					else {
						nth_element(u, u + mid - 1, u + c1);
						nth_element(v, v + mid - 1, v + c2, greater<int>());
						fl = u[mid - 1] < v[mid - 1];
					}
					if (fl) low = mid;
					else high = mid - 1;
				}
				ans = max(ans, low);
			}
		}
	}
	cout << ans * 3;

	return 0;
}