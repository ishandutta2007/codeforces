#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 505;
int n, a[N][N];
int main() {
	scanf("%d", &n);
	if(n <= 2) return puts("-1"), 0;
	int t = n * n - 9, cur = 0;
	a[1][1] = t + 2; a[1][2] = t + 8; a[1][3] = t + 7;
	a[2][1] = t + 3; a[2][2] = t + 1; a[2][3] = t + 6;
	a[3][1] = t + 4; a[3][2] = t + 5; a[3][3] = t + 9;
	for(int i = n; i > 3; i --) {
		if(i & 1) {
			for(int j = 1; j <= i; j ++) a[i][j] = ++ cur;
			for(int j = i - 1; j >= 1; j --) a[j][i] = ++ cur;
		} else {
			for(int j = 1; j < i; j ++) a[j][i] = ++ cur;
			for(int j = i; j >= 1; j --) a[i][j] = ++ cur;
			
		}
	}
	for(int i = 1; i <= n; i ++, puts(""))
		for(int j = 1; j <= n; j ++)
			printf("%d ", a[i][j]);
	return 0;
}
/*
2 8 7
3 1 6
4 5 9
*/