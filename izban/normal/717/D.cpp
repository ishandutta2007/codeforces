#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int N = 128;

void xft(vector<double> &a) {
	for (int len = 1; len < N; len <<= 1) {
		for (int i = 0; i < N; i += 2 * len) {
			for (int j = 0; j < len; j++) {
				double u = a[i + j];
				double v = a[i + j + len];
				a[i + j] = u + v;
				a[i + j + len] = u - v;
			}
		}
	}
}

vector<double> mul(vector<double> a, vector<double> b) {
	xft(a);
	xft(b);
	for (int i = 0; i < N; i++) a[i] *= b[i];
	xft(a);
	for (int i = 0; i < N; i++) a[i] /= N;

	double sum = 0;
	for (int i = 0; i < N; i++) sum += a[i];
	for (int i = 0; i < N; i++) a[i] /= sum;
	return a;
}

vector<double> bin(vector<double> a, int n) {
	vector<double> res(N, 0);
	res[0] = 1;
	while (n) {
		if (n & 1) res = mul(res, a);
		a = mul(a, a);
		n >>= 1;
	}
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	/*vector<double> a(N, 0);
	a[0] = a[1] = 0.5;
	mul(a, a);*/

	int n, x;
	while (cin >> n >> x) {
		vector<double> p(N);
		for (int i = 0; i <= x; i++) cin >> p[i];

		vector<double> res = bin(p, n);
		printf("%.15f\n", 1.0 - res[0]);
	}

	return 0;
}