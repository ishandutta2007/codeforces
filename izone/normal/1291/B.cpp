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

int n, w[301000];

void Process() {
	int i;
	scanf("%d", &n);
	int Mn = 1e9;
	int Mx = 0;
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		if (w[i] < i - 1)Mn = min(Mn, i);
		if (w[i] < n - i)Mx = max(Mx, i);
	}
	if (Mx + 1 <= Mn - 1) {
		puts("Yes");
	}
	else puts("No");
}

int main() {
	int Tcase;
	scanf("%d", &Tcase);
	while (Tcase--) {
		Process();
	}
}