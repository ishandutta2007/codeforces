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

int n;
char p[3010];

void Process() {
	int i;
	scanf("%d", &n);
	scanf("%s", p);
	vector<int>V;
	for (i = 0; p[i]; i++) {
		if ((p[i] - '0') % 2 == 1)V.push_back(p[i] - '0');
	}
	if (V.size() < 2)puts("-1");
	else printf("%d%d\n", V[0], V[1]);
}

int main() {
	int Tcase;
	scanf("%d", &Tcase);
	while (Tcase--) {
		Process();
	}
}