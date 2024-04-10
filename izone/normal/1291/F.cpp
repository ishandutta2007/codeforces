/*
IZ*ONE

La vie en Rose
2018.10.29

Violeta
2019.04.01

Fiesta
2020.02.17
*/

#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, K, chk[2000];
int Ins(int a) {
	printf("? %d\n", a + 1);
	fflush(stdout);
	char pp[3];
	scanf("%s", pp);
	if (pp[0] == 'Y')return 1;
	return 0;
}
int main() {
	int i, j, k;
	scanf("%d%d", &n, &K);
	for (i = 0; i < K; i++) {
		if (Ins(i))chk[i] = 1;
	}
	for (i = 1; i < n / K; i++) {
		for (j = 0; j < i; j++) {
			puts("R");
			fflush(stdout);
			for (k = 0; k < K; k++) {
				Ins(j*K + k);
			}
			vector<int>V;
			for (k = 0; k < K; k++) {
				if (Ins(i*K + k)) {
					chk[i*K + k] = 1;
				}
				else {
					V.push_back(i*K + k);
				}
			}
			puts("R");
			fflush(stdout);
			reverse(V.begin(), V.end());
			for (k = K-1; k >= 0; k--) {
				Ins(j*K + k);
			}
			for (auto &t : V) {
				if (Ins(t)) chk[t] = 1;
			}
		}
	}
	int res = 0;
	for (i = 0; i < n; i++) {
		if (!chk[i])res++;
	}
	printf("! %d\n", res);
	fflush(stdout);
}