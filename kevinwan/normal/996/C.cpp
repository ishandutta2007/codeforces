#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c[4][50];
vector<int> q,w,e;
void p(int a, int b, int d) {
	q.push_back(a), w.push_back(b), e.push_back(d);
}
int ch[4];
int main() {
	int n,k,i,j;
	scanf("%d%d", &n,&k);
	for (i = 0; i < 4; i++)for (j = 0; j < n; j++)scanf("%d", &c[i][j]);
	ch[1] = 0, ch[2] = 3;
	int moves = 0;
	while (k) {
		for (i = 0; i < n; i++) {
			if (c[2][i] == 0)continue;
			else if (c[2][i] == c[3][i])p(c[2][i], 3, i), k--, c[2][i] = c[3][i] = 0;
			else if (i == n - 1)continue;
			else if (c[2][i + 1] == 0)p(c[2][i], 2, i + 1),  c[2][i + 1] = c[2][i], c[2][i] = 0;
		}
		if (c[2][n - 1] != 0 && c[1][n - 1] == 0)p(c[2][n - 1], 1, n - 1), c[1][n - 1] = c[2][n - 1], c[2][n - 1] = 0;
		for (i = n-1; i >=0; i--) {
			if (c[1][i] == 0)continue;
			else if (c[1][i] == c[0][i])p(c[1][i], 0, i), k--, c[1][i] = c[0][i] = 0;
			else if (i == 0)continue;
			else if (c[1][i - 1] == 0)p(c[1][i], 1, i - 1), c[1][i - 1] = c[1][i], c[1][i] = 0;
		}
		if (c[1][0] != 0 && c[2][0] == 0)p(c[1][0], 2,0), c[2][0] = c[1][0], c[1][0] = 0;
		moves++;
		if (moves > 20005) {
			printf("-1"); return 0;
		}
	}
	printf("%d\n", q.size());
	for (i = 0; i < q.size(); i++)printf("%d %d %d\n", q[i], w[i] + 1, e[i] + 1);
	getchar(); getchar();
}