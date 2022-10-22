/*
IZ*ONE

La vie en Rose
2018.10.29

Violeta
2019.04.01

Fiesta
2020.02.17
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

int n, m, K, w[3510], P[3510], S[3510];

bool Pos(int M) {
	int i, j;
	for (i = 1; i <= n; i++) {
		if (w[i] >= M)P[i] = 1;
		else P[i] = 0;
	}
	int c = m - K - 1;
	int z = n - K - 1 - c;
	for (i = 1; i <= n - z; i++) {
		if (P[i] || P[i + z]) {
			S[i] = 1;
		}
		else S[i] = 0;
		S[i] += S[i - 1];
	}
	for (i = 1; i <= K + 1; i++) {
		int b = i, e = i + n - K - 1;
		if (S[b + c] - S[b - 1] == c+1) {
			return true;
		}
	}
	return false;
}

void Process() {
	scanf("%d%d%d", &n, &m, &K);
	int i;
	K = min(K, m - 1);
	for (i = 1; i <= n; i++)scanf("%d", &w[i]);
	int b = 1, e = 1e9, mid, r = 0;
	while (b <= e) {
		mid = (b + e) >> 1;
		if (Pos(mid)) {
			r = mid;
			b = mid + 1;
		}
		else e = mid - 1;
	}
	printf("%d\n", r);
}

int main() {
	int Tcase;
	scanf("%d", &Tcase);
	while (Tcase--) {
		Process();
	}
}