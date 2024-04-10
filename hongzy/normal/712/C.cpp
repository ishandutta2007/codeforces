#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	int x, y, ans = 0;
	scanf("%d%d", &x, &y);
	int a[3] = {y, y, y};
	while(1) {
		if(a[0] == x && a[1] == x && a[2] == x) break ;
		a[0] = min(a[1] + a[2] - 1, x);
		sort(a, a + 3); ans ++;
	}
	printf("%d\n", ans);
	return 0;
}
/*
6 6 6 -> 3 3 3
6 6 3
6 4 3
3 4 3
3 3 3
22 22 22 -> 4 4 4
4 4 4
4 4 7
4 7 10
7 10 16
10 16 22
22 16 22
22 22 22

*/