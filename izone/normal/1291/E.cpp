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

int n, K, p[301000], tot, UF[301000], UP[301000], C[301000][2], T[301000];

char s[301000];
vector<int> g[301000], u[301000];

int Find(int a) {
	int x = a, s = 0;
	while (x != UF[x]) {
		s ^= UP[x];
		x = UF[x];
	}
	int t = 0, root = x;
	x = a;
	while (x != UF[x]) {
		int y = UF[x];
		int z = UP[x];
		UP[x] = t ^ s;
		UF[x] = root;
		t ^= z;
		x = y;
	}
	return root;
}

int Get(int a) {
	if (!T[a]) return min(C[a][0], C[a][1]);
	return C[a][!(T[a] - 2)];
}

void Minus(int a) {
	tot -= Get(a);
}
void Plus(int a) {
	tot += Get(a);

}
void f1(int a, int c) {
	int x = Find(a);
	int d = UP[a];
	int ck = d ^ c;
	Minus(x);
	T[x] = ck + 2;
	Plus(x);
}


void f2(int a, int b, int c) {
	int r1 = Find(a), r2 = Find(b);
	int d1 = UP[a], d2 = UP[b];
	int d = d1 ^ d2 ^ c;
	if (r1 == r2)return;
	Minus(r1);
	Minus(r2);
	C[r1][0] += C[r2][d];
	C[r1][1] += C[r2][d ^ 1];
	if (!T[r1] && T[r2]) {
		T[r1] = ((T[r2] - 2) ^ d) + 2;
	}
	UF[r2] = r1;
	UP[r2] = d;
	Plus(r1);
}

void Process() {
	int i, j;
	scanf("%d%d", &n, &K);
	scanf("%s", s + 1);
	for (i = 1; i <= K; i++) {
		int sz;
		scanf("%d", &sz);
		g[i].resize(sz);
		for (j = 0; j < sz; j++) {
			scanf("%d", &g[i][j]);
			u[g[i][j]].push_back(i);
		}
	}
	for (i = 1; i <= K; i++)UF[i] = i, C[i][0] = 1;
	for (i = 1; i <= n; i++) {
		int c = '1' - s[i];
		if (u[i].empty()) {
		}
		else if(u[i].size() == 1){
			f1(u[i][0], c);
		}
		else {
			int a = u[i][0], b = u[i][1];
			f2(a, b, c);
		}
		printf("%d\n", tot);
	}
}

int main() {
	int Tcase = 1;
	while (Tcase--) {
		Process();
	}
}