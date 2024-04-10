/* 2020. 02. 17. IZ*ONE - Fiesta */

#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, C[26];
long long U[1000];
char p[101000];
void Solve() {
	int i, j;
	scanf("%s", p);
	for (i = 0; p[i]; i++);
	n = i;
	for (i = 0; i < n; i++) {
		int x = p[i] - 'a';
		for (j = 0; j < 26; j++) {
			U[j * 26 + x] += C[j];
		}
		C[x]++;
	}
	long long res = 0;
	for (i = 0; i < 26; i++)res = max(res, (long long)C[i]);
	for (i = 0; i < 26 * 26; i++)res = max(res, U[i]);
	printf("%lld\n", res);
}
int main() {
	int TC = 1;
	while (TC--) {
		Solve();
	}
}