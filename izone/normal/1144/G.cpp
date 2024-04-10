#include<cstdio>
#include<algorithm>
using namespace std;
int n, D[201000][2], w[201000];
int Path[201000][2], R[201000];
void Print(int x, int y) {
	puts("YES");
	int i;
	while (x) {
		R[x] = y;
		if (Path[x][y] == 2)y^=1;
		x--;
	}
	for (i = 1; i <= n; i++)printf("%d ", R[i]);
}
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		D[i][0] = -1e9, D[i][1] = 1e9;
	}
	D[1][0] = 1e9, D[1][1] = -1e9;
	for (i = 2; i <= n; i++) {
		if (w[i - 1] < w[i]) {
			if (D[i][0] < D[i - 1][0]) {
				D[i][0] = D[i - 1][0];
				Path[i][0] = 1;
			}
		}
		if (D[i - 1][1] < w[i]) {
			if (D[i][0] < w[i - 1]) {
				D[i][0] = w[i - 1];
				Path[i][0] = 2;
			}
		}
		if (w[i - 1] > w[i]) {
			if (D[i][1] > D[i - 1][1]) {
				D[i][1] = D[i - 1][1];
				Path[i][1] = 1;
			}
		}
		if (D[i - 1][0] > w[i]) {
			if (D[i][1] > w[i - 1]) {
				D[i][1] = w[i - 1];
				Path[i][1] = 2;
			}
		}
	}
	if (D[n][0] >= 0) {
		Print(n, 0);
		return 0;
	}
	if (D[n][1] <= 1e8) {
		Print(n, 1);
		return 0;
	}
	puts("NO");
}