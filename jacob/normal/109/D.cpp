#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int isGoodNum(int p) {
	while (p) {
		if (p%10 != 7 && p%10 != 4) return 0;
		p /= 10;
	}
	return 1;
}

typedef pair<int, int> pii;

int main(void) {
	int n;
	scanf("%d", &n);
	vector<pii> ar(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i].first);
		ar[i].second = i;
	}
	sort(ar.begin(), ar.end());
	vector<int> curpos(n), curar(n);
	vector<pii> res;
	int g = -1;
	for (int i = 0; i < n; i++) {
		curpos[i] = i;
		curar[i] = i;
		if (isGoodNum(ar[i].first))
			g = ar[i].second;
	}
	if (g == -1) {
		for (int i = 0; i < n; i++) {
			if (ar[i].second != i) {
				printf("-1\n");
				return 0;
			}
		}
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (g == ar[i].second || curpos[ar[i].second] == i) continue;
		if (curpos[g] != i) {
			int a, b;
			a = curpos[g];
			b = i;
			res.push_back(pii(a, b));
			swap(curar[a], curar[b]);
			curpos[curar[a]] = a;
			curpos[curar[b]] = b;
		}
		int a, b;
		a = curpos[ar[i].second];
		b = i;
		res.push_back(pii(a, b));
		swap(curar[a], curar[b]);
		curpos[curar[a]] = a;
		curpos[curar[b]] = b;
	}
	printf("%d\n", res.size());
	for (int i = 0; i < (int)res.size(); i++) {
		printf("%d %d\n", res[i].first + 1, res[i].second + 1);
	}
	return 0;
}