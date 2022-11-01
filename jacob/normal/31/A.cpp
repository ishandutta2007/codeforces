#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <vector>
using namespace std;

int main(void) {
	int n;
	vector<int> v;
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i==j)
				continue;
			for (int k = 0; k < n; k++) {
				if (i == k || k == j)
					continue;
				if (v[i] == v[j] + v[k]) {
					printf("%d %d %d\n", i + 1, j + 1, k + 1);
					return 0;
				}
			}
		}
	}
	printf("-1");
	return 0;
}