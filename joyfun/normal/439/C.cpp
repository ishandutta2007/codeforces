#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))

const int N = 100005;
int n, k, p, i, eve = 0;;
struct Num {
	int v, oe;
} a[N];
vector<int> ans[N];

bool cmp(Num a, Num b) {
	return a.oe > b.oe;
}
bool solve() {
	int i = 0, tmp = 0, j;
	for (;i < k - p; i++) {
		tmp++;
		if (a[i].oe == 0) return false;
		ans[i].push_back(a[i].v);
	}
	if ((n - eve - (k - p)) % 2) return false;
	if (eve + (n - eve - (k - p)) / 2 < p) return false;
	for (j = i; j < n - eve; j += 2) {
		if (tmp == k) break;
		ans[tmp].push_back(a[j].v);
		ans[tmp++].push_back(a[j + 1].v);
	}
	if (tmp == k) {
		for (; j < n - eve; j++) {
			ans[k - 1].push_back(a[j].v);
		}
	}
	j = n - eve;
	for (; j < n; j++) {
		if (tmp == k) break;
		ans[tmp++].push_back(a[j].v);
	}
	if (tmp == k) {
		for (; j < n; j++)
			ans[k - 1].push_back(a[j].v);
	}
	return true;
}
int main() {
	scanf("%d%d%d", &n, &k, &p);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i].v);
		a[i].oe = a[i].v % 2;
		if (a[i].oe == 0)
			eve++;
	}
	sort(a, a + n, cmp);
	if (solve()) {
		printf("YES\n");
		for (int i = 0; i < k; i++) {
			int t = ans[i].size();
			printf("%d", t);
			for (int j = 0; j < t; j++)
				printf(" %d", ans[i][j]);
			printf("\n");
		}
	}
	else {
		printf("NO\n");
	}
	return 0;
}