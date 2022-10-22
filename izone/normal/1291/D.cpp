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

char p[201000];
int n, S[26][201000], SS[201000];

void Process() {
	int i, Q, j;
	scanf("%s", p);
	for (i = 0; p[i]; i++) {
		S[p[i] - 'a'][i + 1] = 1;
		if (i&&p[i] != p[i - 1])SS[i] = 1;
	}
	n = i;
	for (i = 0; i < 26; i++)for (j = 1; j <= n; j++)S[i][j] += S[i][j - 1];
	for (i = 1; i <= n; i++)SS[i] += SS[i - 1]; 
	scanf("%d", &Q);
	while (Q--) {
		int b, e;
		scanf("%d%d", &b, &e);
		if (b == e) {
			puts("Yes");
			continue;
		}
		int i, cc = 0;
		for (i = 0; i < 26; i++) {
			int c = S[i][e] - S[i][b - 1];
			if (c > 0)cc++;
		}
		if (cc == 1) {
			puts("No");
		}
		else if (cc == 2) {
			if (p[b-1]==p[e-1])puts("No");
			else puts("Yes");
		}
		else puts("Yes");
	}
}

int main() {
	int Tcase = 1;
	while (Tcase--) {
		Process();
	}
}