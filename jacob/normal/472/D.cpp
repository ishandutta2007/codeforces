#define _CRT_SECURE_NO_DEPRECATE
#include <vector>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int n;
vector<char> used;
int ma[2000][2000];

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &ma[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (ma[i][i] != 0) {
			printf("NO\n");
			return 0;
		}
		for (int j = 0; j < i; ++j) {
			if (ma[i][j] != ma[j][i] || ma[i][j] == 0) {
				printf("NO\n");
				return 0;
			}
		}
	}
	used.assign(n, 0);
	typedef pair<int, int> pii;
	vector<pii> order;
	for (int i = 0; i < n; ++i) {
		order.push_back(pii(-ma[0][i], i));
	}
	sort(order.begin(), order.end());
	for (int i = 0; i < n - 1; ++i) {
		int current_leaf = order[i].second;
		pii min_dist = pii(INT_MAX, -1);
		used[current_leaf] = true;
		for (int j = 0; j < n; ++j) {
			if (used[j]) continue;
			min_dist = min(min_dist, pii(ma[current_leaf][j], j));
		}
		for (int j = 0; j < n; ++j) {
			if (used[j]) continue;
			if (ma[current_leaf][j] != min_dist.first + ma[min_dist.second][j]) {
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
}