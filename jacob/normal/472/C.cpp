#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

char names[100000][2][60];
bool canBe[100000][2];

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s%s", names[i][0], names[i][1]);
	}
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
		--p[i];
	}
	canBe[0][0] = canBe[0][1] = true;
	for (int i = 1; i < n; ++i) {
		canBe[i][0] = canBe[i][1] = false;
		for (int j = 0; j < 2; ++j) {
			if (!canBe[i-1][j])
				continue;
			for (int k = 0; k < 2; ++k) {
				if (strcmp(names[p[i-1]][j], names[p[i]][k]) < 0) {
					canBe[i][k] = true;
				}
			}
		}
	}
	printf("%s\n", (canBe[n-1][0] || canBe[n-1][1]) ? "YES" : "NO");
}