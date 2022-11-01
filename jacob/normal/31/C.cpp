#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
using namespace std;

greater<int> gr();

bool intersections[5000][5000];

int main(void) {
	int n;
	scanf("%d", &n);
	vector<int> lefts(n), rights(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &lefts[i], &rights[i]);
	}
	int totsum = 0;
	int strsum[5000];
	for (int i = 0; i < n; i++) {
		strsum[i] = 0;
		for (int j = 0; j < n; j++) {
			if (i == j)
				intersections[i][j] = false;
			else {
				if (lefts[i] >= rights[j] || lefts[j] >= rights[i]) {
					intersections[i][j] = false;
				} else {
					intersections[i][j] = true;
					++strsum[i];
					++totsum;
				}
			}
		}
	}
	vector<int> res;
	for (int i = 0; i < n; i++) {
		if (totsum - 2 * strsum[i] == 0)
			res.push_back(i + 1);
	}
	printf("%d\n", (int)res.size());
	for (int i = 0; i < (int)res.size(); i++) {
		printf("%d ", res[i]);
	}
	return 0;
}